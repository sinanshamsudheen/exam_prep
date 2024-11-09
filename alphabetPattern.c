#include<stdio.h>
#include<ctype.h>
void main(){
    char alpha[100]={'a','b','c','d','e','f','g','h','i','j'};
    int n=4;
    int k=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(k%2==0){
                char a=tolower(alpha[k++]);
                printf("%c ",a);
            }
            else{
                char a=toupper(alpha[k++]);
                printf("%c ",a);
            }
        }
        printf("\n");
    }
}