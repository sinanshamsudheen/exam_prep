#include<stdio.h>
#define MX 5
int front=-1,rear=-1,i=0;

struct Customer{
    int token;
    int count;
}counter[100],CQ[MX];

void enqueue(struct Customer val){
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
    printf("dequed token %d.\n",CQ[front].token);
    if(front==rear){
        front=-1;
        rear=-1;
    }
    front=(front+1)%MX;
    i--;
}

void display(){
    if(front==-1){
        printf("CQ empty\n");
        return;
    }
    int i=front;
    while(1){
        printf("[%d,%d] ",CQ[i].token,CQ[i].count);
        if(i==rear)break;
        i=(i+1)%MX;
    }
    printf("\n");
}
void main(){
    int n,t,c,size;

    do{
        printf("RAILWAY COUNTER\n1-enqueue a customer\n2-display the queue\n3-token at the front\n4-size of queue\n5-dequeue a customer\n0-exit\n: ");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("enter customer token: ");
                scanf("%d",&t);
                printf("enter customer ticket count: ");
                scanf("%d",&c);
                counter[i].token=t;
                counter[i].count=c;
                enqueue(counter[i]);
                i++;
                break;
            case 2:
                display();
                break;
            case 3 :
                printf("customer token at front: %d\n",CQ[front].token);
                break;
            case 4 :
                size = (front == -1) ? 0 : ((rear - front + MX) % MX + 1);
                printf("size of the queue : %d\n",size);
                break;
            case 5:
                dequeue();
                break;
        }

    }while(n!=0);
}