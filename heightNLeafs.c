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

void inorder(struct node **root) {
    struct node* ptr = *root;
    while(ptr != NULL || top != -1) {
        while(ptr != NULL) {
            push(ptr);
            ptr = ptr->left;
        }
        ptr = pop();
        printf("%d ", ptr->data);
        ptr = ptr->right;
    }
    printf("\n");
}
// Function to calculate the height of the tree
int getHeight(struct node* root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to count the number of leaf nodes
int countLeafNodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int ch, x;
    while (1) {
        printf("1- Insert Node 2- Inorder 3- Tree Height 4- Leaf Count 0- Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &x);
                insertNode(x);
                break;
            case 2:
                printf("Inorder Traversal\n");
                inorder(&root);
                break;
            case 3:
                printf("Height of the tree is: %d\n", getHeight(root));
                break;
            case 4:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!!\n");
        }
    }
    return 0;
}
