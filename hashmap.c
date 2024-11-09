#include <stdio.h>
#include <stdlib.h>

// Define the table size
#define TABLE_SIZE 10

// Define the structure for a hash table node (linked list node)
struct Node {
    int key;
    struct Node* next;
};

// Hash table array of pointers to linked list heads
struct Node* hashTable[TABLE_SIZE];

// Hash function: Division method
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key into the hash table
void insert(int key) {
    // Calculate hash value (index) for the key
    int index = hashFunction(key);
    
    // Create a new node for the key
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;

    // Insert the node at the beginning of the linked list at hashTable[index]
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }

    printf("Inserted key %d at index %d\n", key, index);
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function to test the hash table
int main() {
    // Initialize the hash table with NULLs
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert some keys into the hash table
    insert(15);
    insert(25);
    insert(35);
    insert(10);
    insert(20);
    insert(5);
    insert(30);

    // Display the hash table
    printf("Hash Table:\n");
    display();

    return 0;
}