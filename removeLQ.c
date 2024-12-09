#include <stdio.h>
#define MX 10

int front = -1, rear = -1;
int queue[100];

// Function to check if the queue is full
int isFull() {
    return (rear == MX - 1);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to enqueue an element
void enqueue(int val) {
    if (isFull()) {
        printf("Queue full\n");
    } else {
        if (front == -1) {
            front = 0; // Initialize front on first enqueue
        }
        queue[++rear] = val;
    }
}

// Function to dequeue an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return -1; // Return a sentinel value for empty queue
    } else {
        return queue[front++];
    }
}

int main() {
    int n, val;
    printf("Enter 5 integers: ");
    
    // Enqueue 5 integers
    for (int i = 0; i < 5; i++) {
        scanf("%d", &n);
        enqueue(n);
    }

    int mx = -99999;
    
    // Find the maximum value in the queue
    for (int i = front; i <= rear; i++) {
        if (queue[i] >= mx) {
            mx = queue[i];
        }
    }

    // Create a temporary queue to hold values except the maximum
    int tempQueue[100];
    int tempFront = -1, tempRear = -1;

    // Dequeue elements and enqueue them to tempQueue if not max
    while (!isEmpty()) {
        val = dequeue();
        if (val != mx) {
            if (tempFront == -1) {
                tempFront = 0; // Initialize tempFront on first enqueue
            }
            tempQueue[++tempRear] = val;
        }
    }

    // Display the remaining values in the queue after removing the max
    printf("The queue after removing the greatest value: ");
    for (int i = tempFront; i <= tempRear; i++) {
        printf("%d, ", tempQueue[i]);
    }
    
    return 0;
}
// Enter 5 integers: 3 1 2 7 6
// The queue after removing the greatest value: 3, 1, 2, 6,