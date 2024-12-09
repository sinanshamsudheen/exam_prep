#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int DQ[MAX], front = -1, rear = -1;

void insertFront(int val)    // add element to front of deque
{
    if ((front == 0 && rear == MAX-1) || (front == rear + 1)) 
    {
        printf("Deque Overflow!\n");
        return;
    }
    else if (front == -1)    // If deque is empty
    {
        front = 0;
        rear = 0;
        DQ[front] = val;
    } 
    else if (front > 0) 
    {
        front--;
        DQ[front] = val;
    } 
    else  // Shift elements to the right
    {
        for (int i = rear; i >= front; i--) 
        {
            DQ[i + 1] = DQ[i];
        }
        DQ[front] = val;
        rear++;
    }
}

void insertRear(int val) // add element from rear
{
    if ((front == 0 && rear == MAX-1) || (front == rear + 1)) 
    {
        printf("Deque Overflow!\n");
        return;
    }
    else if (rear == -1)    // if deque is empty
    {
        front = 0;
        rear = 0;
        DQ[rear] = val;
    } 
    else if (rear < MAX-1)  // if there is space in rear, then add it there
    {
        rear++;
        DQ[rear] = val;
    } 
    else // Shift elements to the left
    {
        for (int i = front; i <= rear; i++) 
        {
            DQ[i - 1] = DQ[i];
        }
        rear--;
        front--;
        DQ[rear] = val;
    }
}

void deleteFront()
{
    if (front == -1) 
    {
        printf("Deque is Empty!\n");
        return;
    }
    
    else if (front == rear)  // Only one element
    {
        printf("Dequed element is %d\n",DQ[front]);
        front = -1;
        rear = -1;
        
    } 
    else 
    {
        printf("Dequed element is %d\n",DQ[front]);
        front++;
    }
}

void deleteRear()
{
    if (rear == -1) 
    {
        printf("Deque is Empty!\n");
        return;
    }
    
    else if (front==rear)  // Only one element
    {
        printf("Deleted item is %d\n", DQ[rear]);
        front = -1;
        rear = -1;
    } 
    else 
    {
        printf("Deleted item is %d\n", DQ[rear]);
        rear--;
    }
}

void displayDQ()
{
    if (front == -1) 
    {
        printf("Deque is EMPTY!\n");
    } 
    else 
    {
        for (int i = front; i <= rear; i++) 
        {
            printf("%d\t", DQ[i]);
        }
        printf("\n");
    }
}

int main()
{
    int val, ch;
    printf("Max size of Deque is 5!\n");
    while (1) 
    {
        printf("Deque Operations:\n");
        printf("1.InsertFront  2.InsertRear  3.DeleteFront  4.DeleteRear  5.Display  6.EXIT\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                printf("Enter value to add in front:");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value to add in rear:");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                displayDQ();
                break;
            case 6:
                printf("THANK YOU!\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}