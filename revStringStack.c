#include <stdio.h>
char stack[3];
int top = -1;
void push(char c){
    stack[++top]=c;
}
char pop(){
    return stack[top--];
}
void revString(char c[]){
    int i=0;
    while(c[i]!='\0'){
        push(c[i]);
        i++;
    }
    while(top!=-1){
        printf("%c",pop());
    }
}
void main(){
    char word[100];
    scanf("%s",word);
    printf("reverse: ");
    revString(word);
}