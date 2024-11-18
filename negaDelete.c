
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

//to delete a node which contains a given key value
void deleteNode(struct Node **head,int key){
        struct Node* temp=*head;
        struct Node* prev=NULL;
    //if key is in the head node itself
    if(temp!=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }

    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("key not found!\n");
        return;
    }
    prev->next=temp->next;
    free(temp);
}
void deleteNega(struct Node** head){
    struct Node* temp=*head;
    struct Node* prev=*head;
    while(temp!=NULL){
        if(temp->data<0){
            deleteNode(head,temp->data);
            temp=*head;
        }
        temp=temp->next;
    }
}
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void main(){
    struct Node* head=NULL;
    insertAtend(&head,-1);
    insertAtend(&head,1);
    insertAtend(&head,2);
    insertAtend(&head,-2);
    insertAtend(&head,3);
    traverse(head);
    deleteNega(&head);
    traverse(head);
}