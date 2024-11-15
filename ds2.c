#include<stdio.h>
#define MX 10

int top=-1,top2=-1,top3=-1;
int stack[100],s2[100],s3[100];
void push1(int val){
    if(top==MX){
        printf("stack full");
    }
    else{
        stack[++top]=val;
    }
}
void push2(int val){
    if(top2==MX){
        printf("stack full");
    }
    else{
        s2[++top2]=val;
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
    printf("enter the 9 integers: ");
    for(int i=0;i<9;i++){
        scanf("%d",&n);
        push1(n);
    }
    printf("enter threshold: ");
    scanf("%d",&key);
    while(top!=-1){
        if(stack[top]>=key){
            val=pop();
            push2(val);
        }else{
            val=pop();
            push3(val);
        }
    }
    if(top2==-1){
        printf("no values greater than threshold!");
    }
    printf("the stack after removing values greater than threshold: ");
    while(top3>=0){
        printf("%d, ",pop3());
    }
}