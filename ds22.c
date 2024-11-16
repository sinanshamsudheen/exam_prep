#include<stdio.h>
#define MX 10

int top=-1,top3=-1;
int stack[100],s3[100];
void push1(int val){
    if(top==MX){
        printf("stack full");
    }
    else{
        stack[++top]=val;
    }
}

void push3(int val){
    if(top3==MX){
        printf("stack full");
    }
    else{
        s3[++top3]=val;
    }
}
int pop(){
    if(top<0){
        printf("stack empty");
    }
    else{
        return stack[top--];
    }
}
int pop3(){
    if(top3<0){
        printf("stack empty");
    }
    else{
        return s3[top3--];
    }
}
void main(){
    int n,key,val;
    printf("enter 5 integers: ");
    for(int i=0;i<5;i++){
        scanf("%d",&n);
        push1(n);
    }
    int mx=-99999;
    int tempTop=top;
    while(tempTop!=-1){
        if(stack[tempTop]>=mx){
            mx=stack[tempTop];
        }
            tempTop--;
    }
    while(top!=-1){
        val=pop();
        if(val!=mx){
            push3(val);
        }
    }
    printf("the stack after removing the greatest value: ");
    while(top3>=0){
        printf("%d, ",pop3());
    }
}
// enter 5 integers: 1 2 3 4 5
// the stack after removing the greatest value: 1, 2, 3, 4,