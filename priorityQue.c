#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    int priority;
    struct Node* next;
};
struct Node* CreateNode(int data,int priority){
    struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode->data=data;
    NewNode->priority=priority;
    NewNode->next=NULL;
    return NewNode;
}

int peek(struct Node** head){
    struct Node *temp=*head;
    return temp->priority;
}
void push(struct Node** head,int data,int prio){
    struct Node* new=CreateNode(data,prio);
    if(*head==NULL){
        *head=new;
        return;
    }
    struct Node* temp=*head;
    if(new->priority <= peek(head)){
        new->next=*head;
        *head=new;
        return;
    }
    while(temp->next!=NULL && temp->next->priority <= new->priority ){
        temp=temp->next;
    }
        new->next=temp->next;
        temp->next=new;
}
void pop(struct Node** head){
    if(*head==NULL){
        printf("list empty");
        return;
    }
    struct Node* temp=*head;
    *head=temp->next;
    free(temp);
    return;
}
void traverse(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("[%d,%d] ->",temp->data,temp->priority);
        temp=temp->next;
    }
    printf("NULL\n");
}
void main(){
    struct Node* head=NULL;
    int n,p;
    printf("enter elements (end with -999)");
    while(1){
        printf("enter data: ");
        scanf("%d",&n);
        if(n==-999)break;
        printf("enter priority: ");
        scanf("%d",&p);
        push(&head,n,p);
    }
    traverse(head);
    pop(&head);
    traverse(head);
}