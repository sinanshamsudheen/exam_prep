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

void maintainList(struct Node** head){
    struct Node* temp=*head;

    while(temp!=NULL && temp->next!=NULL){
        if(temp->next->data < temp->data){
            struct Node* toDelete = temp->next;
            temp->next=toDelete->next;
            free(toDelete);
        }
        else{
            temp=temp->next;
        }
    }
}
void main(){
    struct Node* head1=NULL;
    printf("insert first list(stop with -999): ");
    int n,m;
    while(1){
        scanf("%d",&n);
        if(n==-999) break;
        insertAtend(&head1,n);
    }
    
    traverse(head1);
    maintainList(&head1);
    traverse(head1);
}
// o,p,
// insert first list(stop with -999):  9 24 0-2 45 77 287 3 4 300-999
// 9 -> 24 -> 0 -> -2 -> 45 -> 77 -> 287 -> 3 -> 4 -> 300 -> NULL
// 9 -> 24 -> 45 -> 77 -> 287 -> 300 -> NULL