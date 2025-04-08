#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int finish[10],max[100][100],allocation[100][100],need[100][100],available[100],work[10],n,m;
int safeSeq[100];

bool isSafe(){
    for(int i=0;i<n;i++){
        finish[i]=0;
    }
    for(int j=0;j<m;j++){
        work[j]=available[j];
    }
    int k=0;
    int count=0;
    while(count < n){
        int found=0;
        for(int i=0;i<n;i++){
            if(!finish[i]){
                int canAlloc=1;
                for(int j=0;j<m;j++){
                    if(need[i][j]>work[j]){
                        canAlloc=0;
                        break;
                    }
                }
                if(canAlloc){
                    for(int j=0;j<m;j++){
                        work[j]+=allocation[i][j];
                    }
                    finish[i]=1;
                    safeSeq[k++]=i;
                    count++;
                    found=1;
                }
            }
        }
        if(!found){
            return 0;
        }
    }
    printf("in safe state, the safeSeq is :");
    for(int i=0;i<n;i++){
        printf("%d ",safeSeq[i]);
    }printf("\n");
    return 1;
}

void requestResources(int process,int resource[100]){
        for(int j=0;j<m;j++){
            available[j]-=resource[j];
            allocation[process][j]+=resource[j];
            need[process][j]-=resource[j];
        }
        if(isSafe){
            printf("\nyes we can safely allocate those resources!\n");
        }else{
            printf("no we cant! giving back the resources");
        }
        for(int j=0;j<m;j++){
            available[j]+=resource[j];
            allocation[process][j]-=resource[j];
            need[process][j]+=resource[j];
        }
    }
}
int main(){
    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter Maximum Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &available[i]);

    // Calculate Need Matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    // Display matrices
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
    isSafe();

    // Check initial system state

    // Handling a resource request
    int process;
    int request[MAX_RESOURCES];

    printf("\nEnter process number requesting resources: ");
    scanf("%d", &process);

    printf("Enter requested resources: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &request[i]);

    requestResources(process, request);
  
  return 0;
}