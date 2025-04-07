#include<stdio.h>
#include<stdlib.h>

int blocks[100],process[100],allocation[100];

void firstFit(int blocks[], int m, int process[], int n){
    for(int i=0;i<n;i++){
      allocation[i]=-1;
    }
    for(int i =0;i< n;i++){
        for(int j=0;j<m;j++){
            if(blocks[j]>=process[i]){
              allocation[i]=j;
              blocks[j]-=process[i];
              break;
        }
      }
    }
    printf("FIRST FIT allocated: \n");
    for(int i=0;i<n;i++){
      if(allocation[i]!=-1){
        printf("P%d allocated to %d\n",i,allocation[i]);
      }else{
        printf("P%d not allocated\n",i);
      }
    }printf("\n");
}

void bestFit(int blocks[],int m,int process[],int n){
  for(int i=0;i<n;i++){
    allocation[i]=-1;
  }
  for(int i=0;i<n;i++){
    int bestIdx=-1;
    for(int j=0;j<m;j++){
      if(blocks[j]>=process[i]){
        if(blocks[j]<blocks[bestIdx] || bestIdx==-1){
          bestIdx=j;
        }
    }
    }
    if(bestIdx!=-1){
      allocation[i]=bestIdx;
      blocks[bestIdx]-=process[i];
    }
  }
  printf("BEST FIT allocated: \n");
    for(int i=0;i<n;i++){
      if(allocation[i]!=-1){
        printf("P%d allocated to %d\n",i,allocation[i]);
      }else{
        printf("P%d not allocated\n",i);
      }
    }printf("\n");
}
void worstFit(int blocks[],int m,int process[],int n){
  for(int i=0;i<n;i++){
    allocation[i]=-1;
  }
  for(int i=0;i<n;i++){
    int worstIdx=-1;
    for(int j=0;j<m;j++){
      if(blocks[j]>=process[i]){
          if(blocks[j]>blocks[worstIdx] || worstIdx==-1){
            worstIdx=j;
          }
      }
    }
    if(worstIdx!=-1){
      allocation[i]=worstIdx;
      blocks[worstIdx]-=process[i];
    }
  }
  printf("WORST FIT allocated: \n");
    for(int i=0;i<n;i++){
      if(allocation[i]!=-1){
        printf("P%d allocated to %d\n",i,allocation[i]);
      }else{
        printf("P%d not allocated\n",i);
      }
    }printf("\n");
}

int main(){
  int m, n;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter the size of each memory block:\n");
    for(int i = 0; i < m; i++) {
        printf("Block %d: ", i+1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter the size of each process:\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &processSize[i]);
    }

    int blockCopy1[m], blockCopy2[m], blockCopy3[m];

    for(int i = 0; i < m; i++) {
        blockCopy1[i] = blockSize[i];
        blockCopy2[i] = blockSize[i];
        blockCopy3[i] = blockSize[i];
    }

    firstFit(blockCopy1, m, processSize, n);
    bestFit(blockCopy2, m, processSize, n);
    worstFit(blockCopy3, m, processSize, n);

  return 0;
}

// Enter the number of memory blocks: 5
// Enter the size of each memory block:
// Block 1: 100
// Block 2: 500
// Block 3: 200
// Block 4: 300
// Block 5: 600
// Enter the number of processes: 4
// Enter the size of each process:
// Process 1: 212
// Process 2: 417
// Process 3: 112
// Process 4: 426

// 5 100 500 200 300 600 4 212 417 112 426
