#include<stdio.h>
#include<stdlib.h>

struct Process{
    int pid;
    int tt;
    int wt;
    int bt;
    int at;
    int ct;
}p[100];
int n,totaltt,totalwt;

void calcFcfs(){
    int curr=0;
    for(int i=0;i<n;i++){
        curr+=p[i].bt;
        p[i].ct=curr;
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-p[i].bt;

        totalwt+=p[i].wt;
        totaltt+=p[i].tt;
    }
    printf("avg waiting time: %f",(float)totalwt/n);
    printf("avg tt time: %f",(float)totaltt/n);
}
int main(){
  printf("enter n: ");
  scanf("%d",&n);
  printf("enter bursts: ");
  for(int i=0;i<n;i++){
    scanf("%d",&p[i].bt);
  }
  calcFcfs();
  return 0;
}