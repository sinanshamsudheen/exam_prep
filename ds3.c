#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node* CreateNode(int data){
    struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=data;
    NewNode->next=NULL;
    return NewNode;
}

void insertAtend(struct Node **head,int data){
    struct Node* NewNode=CreateNode(data);
    if(*head==NULL){
        *head=NewNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=NewNode;
}
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void sortNmerge(struct Node** head1,struct Node** head2,struct Node** head3){
    struct Node* temp1=*head1;
    struct Node* temp2=*head2;
    while(temp1!=NULL){
        if(temp1->data%2==0){
            insertAtend(head3,temp1->data);
        }
        temp1=temp1->next;
    }
    while(temp2!=NULL){ 
        if(temp2->data%2==0){
            insertAtend(head3,temp2->data);
        }
        temp2=temp2->next;
    }
    temp1=*head1;
    temp2=*head2;
    while(temp1!=NULL){
        if(temp1->data%2!=0){
            insertAtend(head3,temp1->data);
        }
        temp1=temp1->next;
    }
    while(temp2!=NULL){ 
        if(temp2->data%2!=0){
            insertAtend(head3,temp2->data);
        }
        temp2=temp2->next;
    }
}
void main(){
    struct Node* head1=NULL;
    struct Node* head2=NULL;
    struct Node* head3=NULL;
    printf("insert first list(stop with -999): ");
    int n,m;
    while(1){
        scanf("%d",&n);
        if(n==-999) break;
        insertAtend(&head1,n);
    }
    printf("insert 2nd list(stop with -999): ");
    while(1){
        scanf("%d",&m);
        if(m==-999)break;
        insertAtend(&head2,m);
    }
    sortNmerge(&head1,&head2,&head3);
    traverse(head3);
}
// o,p,
// insert first list(stop with -999): 12 47 878 2 0 3 -999
// insert 2nd list(stop with -999): 5 45 20 81 100 1008 87 25 -999
// 12 -> 878 -> 2 -> 0 -> 20 -> 100 -> 1008 -> 47 -> 3 -> 5 -> 45 -> 81 -> 87 -> 25 -> NULL