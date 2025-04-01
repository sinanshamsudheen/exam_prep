#include<stdio.h>
#include<stdlib.h>

void firstfit(int p[],int b[],int n,int m){
    int allocation[10];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[j]>=p[i]){
                allocation[i]=j;
                b[j]-=p[i];
                break;
            }
        }
    }
    printf("best fit allocated blocks");
    for(int i=0;i<n;i++){
        if(allocation[i]!=-1){
            printf("%d allocated at %d\n",p[i],allocation[i]);
        }else{
            printf("%d Not allocated",p[i]);
        }
    }
}
void bestfit(int p[],int b[],int n,int m){
    int allocation[10];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++){
        int bestIdx=-1;
        for(int j=0;j<m;j++){
            if(b[j]>=p[i]){
                if(bestIdx==-1 || b[j] < b[bestIdx]){
                    bestIdx=j;
                }
            }
        }
        if(bestIdx!=-1){
            allocation[i]=bestIdx;
            b[bestIdx]-=p[i];
        }
    }
    printf("best fit allocated blocks");
    for(int i=0;i<n;i++){
        if(allocation[i]!=-1){
            printf("%d allocated at %d\n",p[i],allocation[i]);
        }else{
            printf("%d Not allocated",p[i]);
        }
    }
}
void worstfit(int p[],int b[],int n,int m){
    int allocation[10];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++){
        int worstIdx=-1;
        for(int j=0;j<m;j++){
            if(b[j]>=p[i]){
                if(worstIdx==-1 || b[worstIdx] < b[j]){
                    worstIdx=j;
                }
            }
        }
        if(worstIdx!=-1){
            allocation[i]=worstIdx;
            b[worstIdx]-=p[i];
        }
    }
    printf("best fit allocated blocks");
    for(int i=0;i<n;i++){
        if(allocation[i]!=-1){
            printf("%d allocated at %d\n",p[i],allocation[i]);
        }else{
            printf("%d Not allocated",p[i]);
        }
    }
}

int main(){
    int n,m,p[10],b[10];
    printf("enter no of processes: ");
    scanf("%d",&n);
    printf("enter no of blocks: ");
    scanf("%d",&m);

    printf("enter size of processes: ");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("enter size of blocks: ");
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    int blockCopy1[m], blockCopy2[m], blockCopy3[m];
    for(int i = 0; i < m; i++) {
        blockCopy1[i] = b[i];  // Copy for First Fit
        blockCopy2[i] = b[i];  // Copy for Best Fit
        blockCopy3[i] = b[i];  // Copy for Worst Fit
    }
    firstfit(p,blockCopy1,n,m);
    bestfit(p,blockCopy2,n,m);
    worstfit(p,blockCopy3,n,m);
}