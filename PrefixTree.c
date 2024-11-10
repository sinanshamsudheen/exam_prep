#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the structure for a binary tree node
typedef struct TreeNode {
    char value[10];
    struct TreeNode *left, *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(char *value) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    strcpy(newNode->value, value);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check if a string is an operator
int isOperator(char *str) {
    return (strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || 
            strcmp(str, "*") == 0 || strcmp(str, "/") == 0);
}

int index = 0; // Global index for the prefix expression array

// Function to build a binary tree from the prefix expression
TreeNode* buildTreeFromPrefix(char *prefix[], int size) {
    if (index >= size) return NULL;

    // Create a new node with the current token
    TreeNode *node = createNode(prefix[index]);
    index++;

    // If the current node is an operator, build the left and right subtrees
    if (isOperator(node->value)) {
        node->left = buildTreeFromPrefix(prefix, size);  // Build left subtree
        node->right = buildTreeFromPrefix(prefix, size); // Build right subtree
    }
    return node;
}

// Function to generate the postfix expression from the binary tree
void generatePostfix(TreeNode *root) {
    if (root == NULL) return;

    // Traverse left subtree
    generatePostfix(root->left);

    // Traverse right subtree
    generatePostfix(root->right);

    // Print the current node (postfix order)
    printf("%s ", root->value);
}

int main() {
    // Example prefix expression
    char *prefixExpr[] = { "*", "+", "A", "B", "-", "C", "D" };
    int size = sizeof(prefixExpr) / sizeof(prefixExpr[0]);

    // Step 1: Build the binary tree from the prefix expression
    TreeNode *root = buildTreeFromPrefix(prefixExpr, size);

    // Step 2: Generate and print the postfix expression
    printf("Postfix Expression: ");
    generatePostfix(root);
    printf("\n");

    return 0;
}
