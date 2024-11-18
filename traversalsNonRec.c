
#include<stdio.h>
#include<stdlib.h>
int top=-1,front=-1,rear=-1;

struct Node{
    int data;
    struct Node *left,*right;
}*stack[100],*Q[100];
void push(struct Node* temp){
    top++;
    stack[top]=temp;
}
struct Node* pop(){
    if(top<0){
        return NULL;
    }
    return stack[top--];
}
void enqueue(struct Node* temp){
    if(front==-1){
        front=0;
        rear=0;
    }
    Q[rear++]=temp;
}
struct Node* dequeue(){
    if(front==-1){
        return NULL;
    }
    struct Node* temp=Q[front];
    if(front==rear){
        front=-1,rear=-1;
    }else{
        front++;
    }
    return temp;
}
struct Node* createNode(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->left=NULL;
    new->right=NULL;
    new->data=data;
    return new;
}
void insert(struct Node** head,int data){
    struct Node* new=createNode(data);
    if(*head==NULL){
        *head=new;
        printf("root node created with data %d\n",new->data);
        return;
    }
    struct Node* temp=*head;
    struct Node* ptr=NULL;
    while(temp!=NULL){
        ptr=temp;
        if(data < temp->data){
            temp=temp->left;
        }else if(data > temp->data){
            temp=temp->right;
        }else{
            printf("duplicates not allowed");
            free(new);
            return;
        }
    }
    if(data<ptr->data){
        ptr->left=new;
    }else{
        ptr->right=new;
    }
}
void inorder(struct Node* head){
    struct Node* curr=head;
    while(curr!=NULL || top!=-1){
        while(curr!=NULL){
            push(curr);
            curr=curr->left;
        }
        curr=pop();
        printf("%d ",curr->data);
        curr=curr->right;
    }
    printf("\n");
}
void preorder(struct Node* head){
    if(head!=NULL){
        printf("%d",head->data);
        preorder(head->left);
        preorder(head->right);
    }
}

void levelOrder(struct Node* root){
    struct Node* curr=NULL;
    if(root==NULL){
        return;
    }
    enqueue(root);
    while(front!=-1 && front<=rear){
        curr=dequeue();
        printf("%d ",curr->data);
        if(curr->left!=NULL){
           enqueue(curr->left);
        }
        if(curr->right!=NULL){
           enqueue(curr->right);
        }
    }
}
void main(){
    struct Node* head=NULL;
    int n,ch;
    do{
        printf("enter 1-insert 2-inorder 3-level order 4-postorder 5-  0-exit\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("enter data to enter: ");
                scanf("%d",&ch);
                insert(&head,ch);
                break;
            case 2:
                inorder(head);
                break;
            case 3:
                levelOrder(head);
                break;
            default:
                printf("option not available\n");
                break;
        }
    }while(n!=0);
}