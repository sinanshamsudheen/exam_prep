#include<stdio.h>
#define MX 5
int CQ[MX];
int front=-1,rear=-1;

void enqueue(int val){
    if(front==(rear+1)%MX){
        printf("CQ is full\n");
        return;
    }
    else if(front==-1){
        front=0;
        rear=0;
    }else{
        rear=(rear+1)%MX;
    }
    CQ[rear]=val;
}
void dequeue(){
    if(front==-1){
        printf("empty\n");
        return;
    }
    printf("dequed %d.\n",CQ[front]);
    if(front==rear){
        front=-1;
        rear=-1;
    }
    front=(front+1)%MX;
}

void display(){
    if(front==-1){
        printf("CQ empty\n");
        return;
    }
    int i=front;
    while(1){
        printf("%d ",CQ[i]);
        if(i==rear)break;
        i=(i+1)%MX;
    }
    printf("\n");
}
void main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    dequeue();
    enqueue(6);
    enqueue(7);
    display();
}