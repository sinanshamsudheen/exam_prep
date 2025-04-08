#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void SCAN(int request[],int n,int head,int disksize){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(request[j]>request[j+1]){
                int temp=request[j];
                request[j]=request[j+1];
                request[j+1]=temp;
            }
        }
    }
    int seek_time=0,direction;
    printf("enter direction(1-right, 0-left): ");
    scanf("%d",&direction);
    printf("%d ",head);
    if(direction){
        for(int i=0;i<n;i++){
            if(request[i]>=head){
                for(int j=i;j<n;j++){
                    seek_time+=abs(request[j]-head);
                    head=request[j];
                    printf("%d ",head);
                }
                if(head!=(disksize-1)){
                    seek_time+=abs(head-(disksize-1));
                    head=disksize-1;
                    printf("%d ",head);
                }
                for(int j=i-1;j>=0;j--){
                    seek_time+=abs(request[j]-head);
                    head=request[j];
                    printf("%d ",head);

                }
                break;
            }
        }
        printf("seek time = %d",seek_time);
    }
    else{
        for(int i=0;i<n;i++){
            if(request[i+1]>=head){
                for(int j=i;j>=0;j--){
                    seek_time+=abs(request[j]-head);
                    head=request[j];
                    printf("%d ",head);
                }
                if(head!=0){
                    seek_time+=abs(head-0);
                    head=0;
                    printf("%d ",head);
                }
                for(int j=i+1;j<n;j++){
                    seek_time+=abs(head-request[j]);
                    head=request[j];
                    printf("%d ",head);
                }
                break;
            }
        }
        printf("seek time = %d",seek_time);
    }
}
int main(){
    int n,request[100],disksize=200,head;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter req array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&request[i]);
    }
    printf("enter head: ");
    scanf("%d",&head);
    SCAN(request,n,head,disksize);
  
  return 0;
}