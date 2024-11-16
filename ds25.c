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
void deleteNode(struct Node **head,int pos){
        struct Node* temp=*head;
        struct Node* prev=NULL;
    //if key is in the head node itself
    int i=0;
    if(pos==0){
        *head=temp->next;
        free(temp);
    }

    while(temp!=NULL && i!=pos){
        prev=temp;
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("key not found!");
    }
    prev->next=temp->next;
    free(temp);
}
void deleteMiddle(struct Node** head){
    struct Node* temp=*head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    int mid=len/2;
    deleteNode(head,mid);
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
    printf("insert list(stop with -999): ");
    int n,m;
    while(1){
        scanf("%d",&n);
        if(n==-999) break;
        insertAtend(&head,n);
    }
    
    traverse(head);
    deleteMiddle(&head);
    printf("list after deletion of middle element: ");
    traverse(head);
}
// insert list(stop with -999): 1 2 3 4 5 -999
// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// list after deletion of middle element: 1 -> 2 -> 4 -> 5 -> NULL