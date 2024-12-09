#include<stdio.h>
#include<stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
}*last;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    return new;
}

// Insert at head
void insertAthead(struct Node** head, int data) {
    struct Node* new = createNode(data);
    if (*head == NULL) {
        new->next = new;
        *head = new;
        last = new;
    } else {
        new->next = *head;
        last->next = new;
        *head = new;
    }
}

// Insert at end
void insertAtend(struct Node** head, int data) {
    struct Node* new = createNode(data);
    if (*head == NULL) {
        new->next = new;
        *head = new;
        last = new;
        return;
    }
    new->next = *head;
    last->next = new;
    last = new;
}

// Delete at head
void deleteAtHead(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    if (*head == last) { // Single node case
        *head = NULL;
        last = NULL;
        free(temp);
        return;
    }
    *head = temp->next;
    last->next = *head;
    free(temp);
}

// Delete at end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (*head == last) { // Single node case
        *head = NULL;
        last = NULL;
        free(temp);
        return;
    }
    while (temp->next != *head) { // Traverse to the last node
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head;
    last = prev;
    free(temp);
}

// Traverse and print the list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function
void main() {
    struct Node* head = NULL;

    // Insert operations
    insertAthead(&head, 2);
    insertAthead(&head, 3);
    insertAtend(&head, 4);
    insertAtend(&head, 5);

    // Traverse the list
    printf("List after insertions: ");
    traverse(head);

    // Delete at head
    deleteAtHead(&head);
    printf("List after deleting at head: ");
    traverse(head);

    // Delete at end
    deleteAtEnd(&head);
    printf("List after deleting at end: ");
    traverse(head);
}
