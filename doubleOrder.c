#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left,*right;
};
struct Node* createNode(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->right=NULL;
    new->left=NULL;
    new->data=data;
}
void insert(struct Node** head,int data){
    char ch;
    struct Node* curr=*head;
    struct Node* new=createNode(data);
    while(1){
        printf("currently at node %d.\n ",curr->data);
        printf("enter right or left to insert:(r/l) ");
        scanf("%c",&ch);
        if(ch=='r'){
            if(curr->right==NULL){
                printf("inserted at r of node %d.\n ",curr->data);
                curr->right=new;
                break;
            }else{
                curr=curr->right;
                printf("currently at node %d. \n",curr->data);
            }
        }
        else if(ch=='l'){
            if(curr->left==NULL){
                printf("inserted at l of node %d.\n ",curr->data);
                curr->left=new;
                break;
            }else{
                curr=curr->left;
                printf("currently at node %d. \n",curr->data);
            }
        }
        else{
            printf("invalid choice\n");
        }
    }
}
void doubleOrder(struct Node* root){
    if(root!=NULL){
        printf("%d",root->data);
        doubleOrder(root->left);
        printf("%d",root->data);
        doubleOrder(root->right);
    }
}
    void main(){
        struct Node* root=NULL;
        int ch,x;
    while(1)
    {
        printf("1.insertNode 2.double order 5.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter data to enter:");
                    scanf("%d",&x);
                if(root==NULL)
                {
                    root=createNode(x);
                    printf("Root node created with value %d\n:",x);
                }
                else
                {   
                    insert(&root,x);
                }
                
                break;
            case 2:
                printf("Inorder traversal\n");
                doubleOrder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("invalid choice!!");
        }
    }
 }
// 3 2 1 1 2 3 4 5 5 6 6 4 6 8 8 6 9 9 
//           3
//          / \
//         2   4
//        /   / \
//       1   5   6
//          / \    \
//         7   8    9
             
