#include<stdio.h>
#include<stdlib.h>
struct Process{
    int pid;
    int bt;
    int at;
    int tt;
    int wt;
    int ct;
}p[100];
int n;
void sortByarrival(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at > p[j+1].at){
                struct Process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}
void calcfcfs(){
    int currt=0;
    for(int i=0;i<n;i++){
        if(p[i].at > currt){
            currt=p[i].at;
        }
        currt+=p[i].bt;
        p[i].ct=currt;
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-p[i].bt;
    }
}
void printTable() {
    int totwt=0,tottn=0;
    // Print table header
    printf("\nPID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    // Print process details
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tt, p[i].wt);
               totwt+=p[i].wt;
               tottn+=p[i].tt;
    }
    printf("avg waiting time: %f",(float)totwt/n);
    printf("avg turnaround time: %f",(float)tottn/n);
}
int main(){
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get arrival times and burst times for each process
    printf("Enter the arrival times and burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;  // Assign process IDs (1 to n)
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
    }
    sortByarrival();
    calcfcfs();
    printTable();
}