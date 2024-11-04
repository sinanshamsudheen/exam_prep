#include <stdio.h>
#include <stdlib.h>

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

struct node *findMin(struct node *root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

void deleteNode(struct node **rootRef, int x) {
    struct node *parent = NULL;
    struct node *curr = *rootRef;

    // Find the node and its parent
    while (curr != NULL && curr->data != x) {
        parent = curr;
        if (x < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    // Node not found
    if (curr == NULL) {
        printf("Value %d not found.\n", x);
        return;
    }

    // Case 1: Node is a leaf node
    if (curr->left == NULL && curr->right == NULL) {
        if (parent == NULL) {
            *rootRef = NULL;
        } else if (parent->left == curr) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(curr);
    }
    // Case 2: Node has one child
    else if (curr->left == NULL || curr->right == NULL) {
        struct node *child = (curr->left != NULL) ? curr->left : curr->right;
        if (parent == NULL) {
            *rootRef = child;
        } else if (parent->left == curr) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        free(curr);
    }
    // Case 3: Node has two children
    else {
        struct node *succ = findMin(curr->right);
        int succData = succ->data;
        deleteNode(&curr->right, succ->data); // Delete successor
        curr->data = succData; // Replace current node's data with successor's data
    }
}

void inorder(struct node *root) {
    struct node *curr = root;
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
    printf("\n");
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int ch, x;
    while (1) {
        printf("1.insertNode 2.inorder 3.preorder 4.postorder 5.deleteNode 6.exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &x);
                insertNode(x);
                break;
            case 2:
                printf("Inorder traversal\n");
                inorder(root);
                break;
            case 3:
                printf("Preorder traversal\n");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal\n");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter data to delete: ");
                scanf("%d", &x);
                deleteNode(&root, x);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!!\n");
        }
    }
    return 0;
}