#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void AddSum(int a,int b){
    int sum= a+b;
    printf("%d",sum);
}

void main(){
    int x=3,y=6;
    swap(&x,&y); //call by reference

    AddSum(6,8); //call by value
    return;
}