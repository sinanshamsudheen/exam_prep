#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* right,*left;
}*stack[100];
int top=-1;
struct Node* create(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    return new;
}
void insert(struct Node** root,int data){
    struct Node* new=create(data);
    struct Node* curr=*root;
    struct Node* ptr=NULL;

    if(*root==NULL){
        *root=new;
        return;
    }
    else{
        while(curr!=NULL){
            ptr=curr;
            if(data<curr->data){
                curr=curr->left;
            }
            else if(data>curr->data){
                curr=curr->right;
            }
            else{
                printf("no dupes\n");
                free(new);
            }
        }
        if(data>ptr->data){
            ptr->right=new;
        }else{
            ptr->left=new;
        }
    }
}

void push(struct Node* temp){
    stack[++top]=temp;
}
struct Node* pop(){
    return stack[top--];
}
void inorder(struct Node** root){
    struct Node* curr=*root;
    while(curr!=NULL || top!=-1){
        while(curr!=NULL){
            push(curr);
            curr=curr->left;
        }
        curr=pop();
        printf("%d ->",curr->data);
        curr=curr->right;
    }
    printf("NULL\n");
}
void delete(struct Node** root,int key){
    struct Node* curr=*root;
    struct Node* parent=NULL;
    while(curr!=NULL && curr->data!=key){
        parent=curr;
        if(key<curr->data){
            curr=curr->left;
        }else{
            curr=curr->right;
        }
    }
    if(curr->left==NULL && curr->right==NULL){
        if(parent==NULL){
            root=NULL;
        }
        if(curr==parent->left){
            parent->left=NULL;
        }else{
            parent->right=NULL;
        }
        free(curr);
    }
    else if(curr->left==NULL || curr->right==NULL){
        struct Node* child=(curr->left!=NULL)?curr->left:curr->right;
        if(parent==NULL){
            *root=child;
        }
        if(parent->right==curr){
            parent->right=child;
        }
        else{
            parent->left=child;
        }
    }
    else{
        struct Node* suParent=NULL;
        struct Node* successor=curr->right;
        while(successor!=NULL){
            suParent=successor;
            successor=successor->left;
        }
        curr->data=successor->data;
        if(suParent->left==successor){
            suParent->left=(successor->right!=NULL)?successor->right:NULL;
        }else{
            suParent->right=(successor->right!=NULL)?successor->right:NULL;
        }
        free(successor);
    }
}
void main(){
    struct Node* root=NULL;
    insert(&root,2);
    insert(&root,3);
    insert(&root,8);
    insert(&root,6);
    insert(&root,9);
    inorder(&root);
    delete(&root,9);
    inorder(&root);
    delete(&root,8);
    inorder(&root);
    
}