#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
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
void split(struct Node **head1,struct Node **head2,int pos){
    struct Node* temp1=*head1;
    int i=1;
    while(temp1!=NULL && i!=pos){
        temp1=temp1->next;
        i++;
    }
    if(i!=pos){
        printf("position out of bounds!");
    }else{
        *head2=temp1->next;
        temp1->next=NULL;
    }
}
void traverse(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }printf("NULL\n");
}
void main(){
    struct Node* head1=NULL,*head2=NULL;
    int n,data,pos;

    do{
        printf("1-insert to main list\n2-split by pos and display the lists\n0-exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:{
                printf("enter data:");
                scanf("%d",&data);
                insertAtend(&head1,data);
                break;
            }
            case 2:{
                printf("enter pos to split: ");
                scanf("%d",&pos);
                printf("main list: ");
                traverse(head1);
                split(&head1,&head2,pos);
                printf("first split: ");
                traverse(head1);
                printf("second split: ");
                traverse(head2);
                break;
            }
            case 0:
                break;
        }
    }while(n!=0);
}
/*o/p,
1-insert to main list
2-split by pos and display the lists
0-exit
1
enter data:1
1-insert to main list
2-split by pos and display the lists
0-exit
1
enter data:2
1-insert to main list
2-split by pos and display the lists
0-exit
1
enter data:3
1-insert to main list
2-split by pos and display the lists
0-exit
1
enter data:4
1-insert to main list
2-split by pos and display the lists
0-exit
2
enter pos to split: 2
main list: 1 ->2 ->3 ->4 ->NULL
first split: 1 ->2 ->NULL
second split: 3 ->4 ->NULL
*/