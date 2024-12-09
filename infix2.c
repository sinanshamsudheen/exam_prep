#include<stdio.h>
char stack[100];
int top=-1;

void push(int val){
    stack[++top]=val;
}
int pop(){
    return stack[top--];
}
int isp(char i){
    if(i=='+' || i=='-'){
        return 1;
    }
    else if(i=='*' || i=='/'){
        return 3;
    }
}
int icp(char i){
    if(i=='+' || i=='-'){
        return 2;
    }
    else if(i=='*' || i=='/'){
        return 4;
    }
}
int isOperator(char i){
    if(i=='-' || i=='+' || i=='/' || i=='*'){
        return 1;
    }
    return 0;
}
void infixToPostfix(char e[],char p[]){
    int i=0,k=0;
    while(e[i]!='\0'){
        char ch=e[i];
        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z'){
            p[k++]=ch;
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(stack[top]!='(' && top!=-1){
                p[k++]=pop();
            }
            pop();
        }
        else if(isOperator(ch)){
            if(isp(stack[top])>=icp(ch) && top!=-1){
                p[k++]=pop();
            }
            push(ch);
        }
        i++;
    }
    while(top!=-1){
        p[k++]=pop();
    }
    p[k]='\0';
}
int compute(int op1,int op2,char op){
    if(op=='+'){
        return op1+op2;
    }
    else if(op=='-'){
        return op1-op2;
    }
    else if(op=='/'){
        return op1/op2;
    }else if(op=='*'){
        return op1*op2;
    }
}
void postFixEval(char p[]){
    int i=0,top2=-1,val;
    int s2[100];
    while(p[i]!='\0'){
        char ch=p[i];
        if(ch>='a' && ch<='z' || ch>='A' && ch<='Z'){
            printf("enter val for %c: ",ch);
            scanf("%d",&val);
            s2[++top2]=val;
        }
        if(isOperator(ch)){
            int op1=s2[top2--];
            int op2=s2[top2--];
            int res=compute(op1,op2,ch);
            s2[++top2]=res;
        }
        i++;
    }
    printf("result: %d",s2[top2]);
}
void main(){
    char expr[100];
    char post[100];
    printf("enter ur expr: ");
    scanf("%s",expr);
    infixToPostfix(expr,post);
    int i=0;
    while(post[i]!='\0'){
        printf("%c",post[i]);
        i++;
    }
    postFixEval(post);
}