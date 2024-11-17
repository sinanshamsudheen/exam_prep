#include<stdio.h>

#define MX 5
int DQ[MX];
int front=-1,rear=-1;
void insertFront(int val){
    if((front==0 && rear==MX-1) || (front==rear+1)){
        printf("DQ full\n");
        return;
    }
    else if(front==-1){
        front=0;
        rear=0;
        DQ[front]=val;
    }
    else if(front>0){
        DQ[--front]=val;
    }else{
        for(int i=rear;i>=front;i--){
            DQ[i+1]=DQ[i];
        }
        DQ[front]=val;
        rear++;
    }
}
void insertRear(int val){
    if((front==0 && rear==MX-1) || (front==rear+1)){
        printf("full\n");
    }else if(rear==-1){
        front=0;
        rear=0;
        DQ[rear]=val;
    }else if(rear<MX-1){
        rear++;
        DQ[rear]=val;
    }else{
        for(int i=front;i<rear;i++){
            DQ[i-1]=DQ[i];
        }
        DQ[rear]=val;
        front--;
    }
}
void deleteFront(){
    if(front==-1){
        printf("empty\n");
    }else if(front==rear){
        printf("deleted %d",DQ[front]);
        rear=-1,front=-1;
    }
    else{
        printf("deleted %d",DQ[front]);
        front++;
    }
}
void deleteRear(){
    if(front==-1){
        printf("empty\n");
    }else if(front==rear){
        printf("deleted %d",DQ[rear]);
        rear=-1;
        front=-1;
    }else
    {
        printf("deleted %d",DQ[rear]);
        rear--;
    }
}
void display(){
    if(front==-1){
        printf("empty\n");
        return;
    }
    printf("displayin the DQ: ");
    for(int i=front;i<=rear;i++){
        printf("%d ",DQ[i]);
    }
    printf("\n");
}
void main(){
    int ch,data;
    do
    {
        printf("\n1.insertFront 2.display 3.insertRear 4.deleteFront 5. deleteRear 0.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter data to enter:");
                scanf("%d",&data);
                insertFront(data);
                break;
            case 2 :
                display();
                break;
            case 3:
                printf("Enter data to enter:");
                scanf("%d",&data);
                insertRear(data);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteRear();
                break;
            case 0:
                break;
            default:
                printf("invalid choice!!");
        }
    }while(ch!=0);
}