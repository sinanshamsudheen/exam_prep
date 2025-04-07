#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int n1,n2;
    pid_t pid=fork();

    if(pid<0){
        printf("failed fork");
        exit(1);
    }else if(pid==0){
        printf("child process(PID: %d):enter no.for odd/even: ",getpid());
        scanf("%d",&n1);
        (n1%2==0)?printf("even\n"):printf("odd\n");
    }
    else{
        wait(NULL);
        printf("parent process(PID= %d) waiting for child process to end \n",getpid());
        printf("enter n for sum: ");
        scanf("%d",&n1);
        printf("the sum is: %d",(n1*(n1+1))/2);
    }
    exit(0);
  return 0;
}