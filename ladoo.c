
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
int traverse(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void OnlyUnique(struct Node** head1,struct Node** head2){
    struct Node* temp1=*head1;
    struct Node* temp2=*head2;
    while(temp1!=NULL){
        int flag=0;
        temp2=*head2;
        while(temp2!=NULL){
            if(temp1->data==temp2->data){
                flag=1;
                break;
            }
            temp2=temp2->next;
        }
        if(flag==0){
            insertAtend(head2,temp1->data);
        }
        temp1=temp1->next;
    }
}
void main(){
    struct Node* head1=NULL;
    struct Node* head2=NULL;
    int n,a;
    printf("enter ur ladoo sizes(end with -999)");
    while(1){
        scanf("%d",&n);
        if(n==-999)break;
        insertAtend(&head1,n);
    }
    OnlyUnique(&head1,&head2);
    printf("displaying unique laddoos: ");
    traverse(head2);
}
// enter ur ladoo sizes(end with -999)2 2 5 6 7 8 8 -999
// displaying unique laddoos: 2 ->5 ->6 ->7 ->8 ->NULL