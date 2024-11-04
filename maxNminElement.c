#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node {
    int data;
    struct node *left, *right;
} *root = NULL, *stack[100];

int top = -1;

void push(struct node *temp) {
    if (top < 99) {
        top++;
        stack[top] = temp;
    }
}

struct node *pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        return NULL;
    }
}

struct node *createNode(int x) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void insertNode(int x) {
    struct node *new = createNode(x);
    if (root == NULL) {
        root = new;
        printf("Root node created with data %d\n", new->data);
        return;  
    }
    struct node *curr = root;
    struct node *ptr = NULL;
    while (curr != NULL) {
        ptr = curr;
        if (x < curr->data) {
            curr = curr->left;   // Move to left subtree
        } else if (x > curr->data) {
            curr = curr->right;  // Move to right subtree
        } else {
            printf("Duplicate value %d not inserted.\n", x);
            return;
        }
    }
    if (x < ptr->data) {
        ptr->left = new;
    } else {
        ptr->right = new;
    }
}
void inorder(struct node **root){
    struct node* ptr=*root;
    while(ptr!=NULL || top!=-1){
        while(ptr!=NULL){
            push(ptr);
            ptr=ptr->left;
        }
        ptr=pop();
        printf("%d ",ptr->data);
        ptr=ptr->right;
    }
    printf("\n");
}
void findMaxElement(struct node* root){
   int max=INT_MIN;
   struct node* curr=root;
   while(curr!=NULL || top!=-1){
        while(curr!=NULL){
            push(curr);
            curr=curr->left;
        }
    curr=pop();
    if(curr->data>=max){
            max=curr->data;
    }

    curr=curr->right;
   }
   printf("max element is: %d\n",max);
}
void findMinElement(struct node* root){
   int min=INT_MAX;
   struct node* curr=root;
   while(curr!=NULL || top!=-1){
        while(curr!=NULL){
            push(curr);
            curr=curr->left;
        }
    curr=pop();
    if(curr->data<=min){
            min=curr->data;
    }
    curr=curr->right;
   }
   printf("minimum element is: %d\n",min);
}

int main() {
    int ch, x;
    while (1) {
        printf("1- insertNode 2- inorder 3- MAX element 4- MIN element 0- exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &x);
                insertNode(x);
                break;
            case 2:
                printf("Inorder traversal\n");
                inorder(&root);
                break;
            case 3:
                findMaxElement(root);
                break;
            case 4:
                findMinElement(root);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!!\n");
        }
    }
    return 0;
}