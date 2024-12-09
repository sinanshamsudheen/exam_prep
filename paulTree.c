
#include <stdio.h>
#include<stdbool.h>
#include<string.h>

char tree[50];
int cur_index=0;
char pref[50];
int n=0;
bool isOperator(char c){
    return c=='+' || c=='-' ||c=='*' ||c=='/' ? true :false;
}
bool isOperand(char c){
    return 'a'<= c && c<='z'?true :false;
}

void treemake(int index){
    // If the current index is greater than or equal to n, stop the recursion
    if(cur_index >= n){
        return;
    }
    
    // Get the current character from the prefix expression and increment the current index
    char cur_char = pref[cur_index++];
    
    // Assign the current character to the tree at the given index
    tree[index] = cur_char;

    // If the current character is an operator, recursively create left and right subtrees
    if(isOperator(cur_char)){
        // Create the left subtree at index (2*index)+1
        treemake((2*index) + 1);
        // Create the right subtree at index (2*index)+2
        treemake((2*index) + 2);
    }
}
void postorder(int i){
    if(i>=50||tree[i]=='\0'){
        return;
    }
    postorder(2*i+1);
    postorder(2*i+2);
    printf("%c",tree[i]);
}
void main(){
    char ch;
    printf("Enter the Prefix tree: ");
    while((ch=getchar())!='\n'){
        pref[n++]=ch;
    }
    memset(tree,'\0',50);
    treemake(0);
    int i=0;
    printf("Tree array:\n");
    for (int i = 0; i < 50; i++) {
        if (tree[i] == '\0') {
            continue;
        } else {
            printf("%c", tree[i]);
        }
    }
    printf("\n");
    printf("Postfix is: ");
    postorder(0);
}