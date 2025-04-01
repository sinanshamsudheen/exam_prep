#include<stdio.h>
#include<stdlib.h>
struct Process{
    int pid;
    int tt;
    int bt;
    int wt;
    int rt;
    int ct;
}p[100];
int n,quantum;

void calcRR(){
    int currt=0;
    int completedProcess=0;
    while(completedProcess < n){
        for(int i=0;i<n;i++){
            if(p[i].rt>0){
                if(p[i].rt>quantum){
                    p[i].rt-=quantum;
                    currt+=quantum;
                }else{
                    currt+=p[i].rt;
                    p[i].rt=0;
                    p[i].ct=currt;
                    p[i].tt=p[i].ct; // Turnaround time is completion time minus arrival time (arrival time is 0 here)
                    p[i].wt=p[i].tt-p[i].bt; // Waiting time is turnaround time minus burst time
                    completedProcess++;
                }
            }
        }
    }
}
void printTable() {
    int totwt=0,tottn=0;
    // Print table header
    printf("\nPID\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    // Print process details
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", 
               p[i].pid, p[i].bt,
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
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;  // Assign process IDs (1 to n)
        printf("Process %d:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        p[i].rt=p[i].bt;
        p[i].wt=0;
        p[i].tt=0;
    }
    printf("Enter the quantum: ");
    scanf("%d", &quantum);
    calcRR();
    printTable();
}