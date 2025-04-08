#include<stdio.h>
#include<stdlib.h>

struct Node{
    int page;
    struct Node* next,*prev;
}*head=NULL,*tail=NULL;
int pages[100];

struct Node* create(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->next=NULL;
    new->prev=NULL;
    new->page=data;
    return new;
}
void PushToTop(struct Node* new){
    new->next=head->next;
    new->prev=head;
    if(head->next)head->next->prev=new;
    head->next=new;
    if(head==tail){
        tail=new;
    }
}
void moveToTop(struct Node* temp){
    if(temp->next)temp->next->prev=temp->prev;
    if(temp->prev)temp->prev->next=temp->next;
    if(temp==tail)tail=temp->prev;
    PushToTop(temp);
}
void deleteLRU(){
    struct Node* temp=tail;
    if(head==tail)return;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
}
struct Node* search(int page){
    struct Node* temp=head->next;
    while(temp){
        if(temp->page==page)return temp;
        temp=temp->next;
    }
    return NULL;
}
void LRU(int pages[],int n,int capacity){
    int pageFaults=0,pageHits=0,count=0;
    printf("Page\tFrame\n");
    for(int i=0;i<n;i++){
        struct Node* existing=search(pages[i]);
        if(existing){
            printf("\npage hit\n");
            pageHits++;
            moveToTop(existing);
        }else{
            pageFaults++;
            printf("\npage fault\n");
            if(count==capacity){
                deleteLRU();
                count--;
            }
            struct Node* new=create(pages[i]);
            PushToTop(new);
            count++;
        }
    }
    printf("no of page faults: %d\n",pageFaults);
    printf("no of page hits: %d\n",pageHits);
}
int main(){
    head=create(-1);
    tail=head;
    int n,framesize;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter frame size: ");
    scanf("%d",&framesize);
    printf("enter pages: ");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    LRU(pages,n,framesize);
  return 0;
}