#include <stdio.h>
#include <stdlib.h>

// Definition of the polynomial structure
struct Poly {
    int coeff, expo;
    struct Poly *next;
};

// Function to create a new polynomial term
struct Poly* createPoly(int coeff, int expo) {
    struct Poly* newPoly = (struct Poly*)malloc(sizeof(struct Poly));
    newPoly->coeff = coeff;
    newPoly->expo = expo;
    newPoly->next = NULL;
    return newPoly;
}

// Function to insert a term at the beginning of the polynomial linked list
void insertAtBegin(struct Poly** head, int coeff, int expo) {
    struct Poly* newPoly = createPoly(coeff, expo);
    newPoly->next = *head;
    *head = newPoly;
}

// Function to traverse and display the polynomial
void traverse(struct Poly* head) {
    struct Poly* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
void addPoly(struct Poly* headP, struct Poly* headQ, struct Poly** headR) {
    struct Poly *p = headP, *q = headQ;
    int coeff, expo;

    while (p != NULL && q != NULL) {
        if (p->expo == q->expo) {
            coeff = p->coeff + q->coeff;
            expo = p->expo;
            insertAtBegin(headR, coeff, expo);
            p = p->next;
            q = q->next;
        } else if (p->expo > q->expo) {
            coeff = p->coeff;
            expo = p->expo;
            insertAtBegin(headR, coeff, expo);
            p = p->next;
        } else {
            coeff = q->coeff;
            expo = q->expo;
            insertAtBegin(headR, coeff, expo);
            q = q->next;
        }
    }

    // Add remaining terms from P
    while (p != NULL) {
        coeff = p->coeff;
        expo = p->expo;
        insertAtBegin(headR, coeff, expo);
        p = p->next;
    }

    // Add remaining terms from Q
    while (q != NULL) {
        coeff = q->coeff;
        expo = q->expo;
        insertAtBegin(headR, coeff, expo);
        q = q->next;
    }
}

// Function to multiply two polynomials
void multiplyPoly(struct Poly* headP, struct Poly* headQ, struct Poly** headR) {
    struct Poly *p = headP, *q = headQ;

    // Temporary result polynomial
    struct Poly* tempResult = NULL;

    // Multiply each term of the first polynomial with every term of the second polynomial
    while (p != NULL) {
        q = headQ;
        while (q != NULL) {
            int coeff = p->coeff * q->coeff;
            int expo = p->expo + q->expo;

            // Insert the term into the temporary result
            insertAtBegin(&tempResult, coeff, expo);
            q = q->next;
        }
        p = p->next;
    }

    // Merge like terms in the temporary result
    struct Poly* temp = tempResult;
    while (temp != NULL) {
        struct Poly* ptr = temp->next;
        struct Poly* prev = temp;
        while (ptr != NULL) {
            if (temp->expo == ptr->expo) {
                temp->coeff += ptr->coeff;
                prev->next = ptr->next;
                free(ptr);
                ptr = prev->next;
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        temp = temp->next;
    }

    *headR = tempResult;
}

// Main function
int main() {
    struct Poly *P = NULL, *Q = NULL, *R_add = NULL, *R_mul = NULL;

    // Creating first polynomial: 3x^3 + 5x^2 + 6
    insertAtBegin(&P, 6, 0);
    insertAtBegin(&P, 5, 2);
    insertAtBegin(&P, 3, 3);

    // Creating second polynomial: 4x^2 + 2x + 1
    insertAtBegin(&Q, 1, 0);
    insertAtBegin(&Q, 2, 1);
    insertAtBegin(&Q, 4, 2);

    printf("First Polynomial: ");
    traverse(P);

    printf("Second Polynomial: ");
    traverse(Q);

    // Adding the polynomials
    addPoly(P, Q, &R_add);
    printf("Resultant Polynomial (P + Q): ");
    traverse(R_add);

    // Multiplying the polynomials
    multiplyPoly(P, Q, &R_mul);
    printf("Resultant Polynomial (P * Q): ");
    traverse(R_mul);

    return 0;
}
