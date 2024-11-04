#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node *next,*prev;
};

struct Node* createNode(char data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    return new;
}
void insertFront(struct Node **root,char data){
    struct Node *new=createNode(data);
    if(*root==NULL){
        *root=new;
        return;
    }
    struct Node* temp=*root;
    *root=new;
    new->next=temp;
    temp->prev=new;
}

void palindrome(struct Node **root){
    struct Node* last=*root;
    struct Node* first=*root;
    int len=1;
    while(last->next!=NULL){
        last=last->next;
        len++;
    }
    int flag=0;
    for(int i=0;i<len/2;i++){
        if(first->data!=last->data){
            flag=1;
            break;
        }
            first=first->next;
            last=last->prev;
    }
    if(flag){
        printf("its not a palindrome");
    }else{
        printf("palindrome");
    }

}
void main(){
    struct Node* root=NULL;
    char ch;
    int n,m;


    printf("enter word ending with #: ");
   
    int i=0;
    while ((ch = getchar()) != '#') {
        insertFront(&root, ch);
    }
    palindrome(&root);
}