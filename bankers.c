#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int alloc[10][10],max[10][10],avail[10],need[10][10],work[10],finish[10],safeSeq[10];
int n,m;

bool isSafe(){
    for(int j=0;j<m;j++){
        work[j]=avail[j];
    }
    
    for(int i=0;i<n;i++){
        finish[i]=0;
    }
   int count=0;

    while(count<n){
        int found=0;
        for(int i=0;i<n;i++){
            if(!finish[i]){
                int canAllocate=1;
                for(int j=0;j<m;j++){
                    if(need[i][j]>work[j]){
                        canAllocate=0;
                        break;
                    }
                }
                if(canAllocate){
                    for(int j=0;j<m;j++){
                        work[j]+=alloc[i][j];
                    }
                    safeSeq[count]=i;
                    finish[i]=1;
                    count++;
                    found=1;
                }
            }
        }
        if(!found){
            printf("unsafe");
            return 0;
        }
    }
    printf("safe sequence:");
    for(int i=0;i<n;i++){
        printf("%d |",safeSeq[i]);
    }
    return 1;
}
int main(){
    printf("enter no of processes: ");
    scanf("%d",&n);
    printf("enter no of resources: ");
    scanf("%d",&m);

    printf("enter allocation matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("enter max matrix:");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("enter available matrix:");
    for(int j=0;j<m;j++){
        scanf("%d",&avail[j]);
    }
    
    printf("need matrix is:");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    isSafe();
    
    
}

// enter no of processes: 5
// enter no of resources: 3
// enter allocation matrix:    0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
// enter max matrix:           7 5 3 3 2 2 9 0 2 2 2 2 4 3 3
// enter available matrix:     3 3 2
