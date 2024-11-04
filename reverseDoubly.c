#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};
struct Node* createNode(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->right=NULL;
    new->left=NULL;
    new->data=data;
    return new;
}
void insertEnd(struct Node **head,int data){
    struct Node* new=createNode(data);
    struct Node* temp=*head;
    if(*head==NULL){
        *head=new;
        return;
    }
    while(temp->right!=NULL){
        temp=temp->right;
    }
    temp->right=new;
    new->left=temp;
}
//swapping the data
void reverseList1(struct Node** head){
    struct Node* first=*head;
    struct Node* last=*head;
   
    while(last->right!=NULL){
        last=last->right;
    }
    while(first!=last && first->left!=last){
        int temp=first->data;
        first->data=last->data;
        last->data=temp;

        first=first->right;
        last=last->left;
    }
}
//swapping the nodes
void reverseList2(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;

    // Traverse the list and swap left and right pointers of each node
    while (current != NULL) {
        // Swap the pointers
        temp = current->left;
        current->left = current->right;
        current->right = temp;

        // Move to the next node in the original sequence
        current = current->left; // This is current->right before the swap
    }

    // Update head to the new front of the list
    if (temp != NULL) {
        *head = temp->left;
    }
}

void traverse(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->right;
    }printf("NULL\n");
}
int main() {
    struct Node *head=NULL;
    int ch, x;
    while (1) {
        printf("1- insertNode 2- traverse 3- reverse 0- exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &x);
                insertEnd(&head,x);
                break;
            case 2:
                printf("traversal\n");
                traverse(head);
                break;
            case 3:
                reverseList2(&head);
                traverse(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!!\n");
        }
    }
    return 0;
}
/*

*/