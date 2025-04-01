#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};

void calculateRoundRobin(struct Process p[], int n, int quantum) {
    int currentTime = 0;
    int completedProcess = 0;

    while (completedProcess < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remainingTime > 0) {
                if (p[i].remainingTime > quantum) {
                    currentTime += quantum;
                    p[i].remainingTime -= quantum;
                } else {
                    currentTime += p[i].remainingTime;
                    p[i].remainingTime = 0;
                    p[i].completionTime = currentTime;
                    p[i].turnaroundTime = currentTime;
                    p[i].waitingTime = currentTime - p[i].burstTime;
                    completedProcess++;
                }
            }
        }
    }

    printf("\nPID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burstTime, p[i].waitingTime, p[i].turnaroundTime);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time for Process P%d: ", i + 1);
        scanf("%d", &p[i].burstTime);
        p[i].remainingTime = p[i].burstTime;
        p[i].waitingTime = 0;
        p[i].turnaroundTime = 0;
    }

    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    calculateRoundRobin(p, n, quantum);

    float avgWait = 0, avgTurnaround = 0;
    for (int i = 0; i < n; i++) {
        avgWait += p[i].waitingTime;
        avgTurnaround += p[i].turnaroundTime;
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWait / n);
    printf("Average Turnaround Time: %.2f\n", avgTurnaround / n);

    return 0;
}