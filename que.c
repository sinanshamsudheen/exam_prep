#include<stdio.h>

#define MX 10
int Q[MX];
int front=-1;
int rear=-1;

void enque(int val){
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
    }
    if(rear==MX){
        printf("Q full");
    }else{
        Q[rear++]=val;
    }
}
int deq(){
    if(front==-1 && rear==-1){
        printf("Q empty");
    }
    return Q[front++];
}
void display(){
    for(int i=front;i<rear;i++){
        printf("%d ",Q[i]);
    }
}
void main(){
    enque(1);
    enque(2);
    enque(3);
    enque(4);
    display();
    deq();
    deq();
    printf("after dequeue: ");
    display();
}