#include<stdio.h>
#include<stdlib.h>
int request[100],n,visited[100],head;
void SSTF(){
    for(int i=0;i<n;i++)visited[i]=0;
    int seek_time=0;
    int index=0;
    int completed=0;
    while(completed<n){
        int min_dist=999;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int distance=abs(request[i]-head);
                if(distance<min_dist){
                    min_dist=distance;
                    index=i;
                }
            }
        }
        visited[index]=1;
        head=request[index];
        seek_time+=min_dist;
        completed++;
    }
    printf("seek time: %d",seek_time);
}
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&request[i]);
  }
  scanf("%d",&head);
  SSTF();
  return 0;
}