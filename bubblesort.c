#include<stdio.h>
void main(){
    int arr[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){

            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return;
}
// #include<stdio.h>
// #include<string.h>
// void main(){
//     char s1[]="sinanuu";
//     char s2[]="lizaaa";
//     int i=0,j=0;
    
//     char s3[100];

//     while(s1[i]!='\0'){
//         s3[j]=s1[i];
//         j++;
//         i++;
//     }
//     i=0;
//     while(s2[i]!='\0'){
//         s3[j]=s2[i];
//         j++;
//         i++;
//     }
//     s3[j]='\0';

//         printf("%s",s3);

//     // printf("%d\n",strlen(name));
//     // printf("%d",sizeof(name));
//     return;
// }

#include<stdio.h>
void main(){
    char s[]="malayalam";
    int flag=0;
    int size=0;

    for(int i=0;s[i]!='\0';i++){
        size++;
    }

    for(int i=0;i<size/2;i++){
        if(s[i]!=s[size-i-1]){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Not a palindrome");
    }
    else{
        printf("palindrome");
    }
    return;
}