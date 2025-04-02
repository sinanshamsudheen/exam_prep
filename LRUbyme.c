#include<stdio.h>
#include<stdlib.h>

struct Node{
    int page;
    struct Node *next,*prev;
}*head,*tail;

struct Node* createNode(int page){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->next=new->prev=NULL;
    new->page=page;
    return new;
}

void PushToTop(struct Node* node){
    node->next=head->next;
    node->prev=head;
    if(head->next){
        head->next->prev=node;
    }
    head->next=node;
    if(head==tail){
        tail=node;
    }
}

void deleteLRU(){
    if(tail==head) return;
    struct Node* temp=tail;
    tail=tail->prev;
    if(tail) tail->next=NULL;
    free(temp);
}

void moveToTop(struct Node* node){
    if(node->prev) node->prev->next=node->next;
    if(node->next) node->next->prev=node->prev;
    if(node==tail){
        tail=node->prev;
    }
    PushToTop(node);
}

struct Node* search(int page){
    struct Node* temp=head->next;
    while(temp){
        if(temp->page==page){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

void LRU(int pages[],int n,int capacity){
    int pageFaults=0;
    int pageHits=0;
    int count=0;
    printf("Page\tFrame\n");

    for(int i=0;i<n;i++){
        printf("%d\t",pages[i]);

        struct Node* existing=search(pages[i]);
        if(existing){
            moveToTop(existing);
            pageHits++;
            printf("Hit");
        }else{
            pageFaults++;
            if(count==capacity){
                deleteLRU();
                count--;
            }
            struct Node* newNode=createNode(pages[i]);
            PushToTop(newNode);
            count++;
            printf("Miss");
        }
        struct Node* temp=head->next;
        printf("\t[");
        while(temp){
            printf("%d",temp->page);
            if(temp->next) printf(",");
            temp=temp->next;
        }
        printf("]\n");
    }
    printf("Total Page Hits: %d\n",pageHits);
    printf("Total Page Miss: %d\n",pageFaults);
}

int main(){
    int n,frames;
    printf("Enter number of pages: ");
    scanf("%d",&n);
    int pages[n];

    printf("Enter reference string: ");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d",&frames);
    head=createNode(-1);
    tail=head;
    LRU(pages,n,frames);
    return 0;
}
