#include<stdio.h>
#include<stdlib.h>
int fact(int n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}
void main(){
    printf("%d",fact(5));
}