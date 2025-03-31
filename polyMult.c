#include <stdio.h>
#include <stdlib.h>
struct Poly {
    int expo, coeff;
} p1[10], p2[10], p3[100];

int add(struct Poly p1[],struct  Poly p2[],struct Poly p3[],int t1,int t2)
{
    int i=0,j=0,k=0;
    while(i<t1 && j<t2)
    {
        if(p1[i].expo==p2[j].expo)
        {
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].expo=p1[i].expo;
            i++;j++;k++;
        }
        else if(p1[i].expo>p2[j].expo)
        {
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;k++;
        }
        else
        {
            p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            j++;k++;
        }
    }
    //add leftover terms
    while(i<t1)
    {
        p3[k].coeff=p1[i].coeff;
        p3[k].expo=p1[i].expo;
        i++;k++;
    }
    while(j<t2)
    {
        p3[k].coeff=p2[j].coeff;
        p3[k].expo=p2[j].expo;
        j++;k++;
    }
    return k;
}

int multiply(struct Poly p1[], struct Poly p2[], struct Poly p3[], int t1, int t2) {
    int k = 0;

    // Multiply each term of p1 with each term of p2
    for (int i = 0; i < t1; i++) {
        for (int j = 0; j < t2; j++) {
            p3[k].coeff = p1[i].coeff * p2[j].coeff;
            p3[k].expo = p1[i].expo + p2[j].expo;
            k++;
        }
    }

    // Combine terms with the same exponents
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (p3[i].expo == p3[j].expo) {
                p3[i].coeff += p3[j].coeff;
                // Mark duplicate term by setting coefficient to 0
                p3[j].coeff = 0;
            }
        }
    }

    // Remove terms with zero coefficients and sort by exponents in descending order
    int m = 0;
    struct Poly temp;
    for (int i = 0; i < k; i++) {
        if (p3[i].coeff != 0) {
            p3[m++] = p3[i];
        }
    }

    // Sort terms by exponents (descending order)
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (p3[i].expo < p3[j].expo) {
                temp = p3[i];
                p3[i] = p3[j];
                p3[j] = temp;
            }
        }
    }

    return m; // Return the number of terms in the resulting polynomial
}

int read(struct Poly p[]) {
    int t;
    printf("Enter the number of terms: ");
    scanf("%d", &t);
    printf("Enter the polynomial:\n");
    for (int i = 0; i < t; i++) {
        printf("Coefficient: ");
        scanf("%d", &p[i].coeff);
        printf("Exponent: ");
        scanf("%d", &p[i].expo);
    }
    return t;
}

void display(struct Poly p[], int t) {
    for (int i = 0; i < t - 1; i++) {
        printf("%dx^%d + ", p[i].coeff, p[i].expo);
    }
    printf("%dx^%d\n", p[t - 1].coeff, p[t - 1].expo);
}

void main() {
    int t1, t2, t3;
    printf("First Polynomial\n");
    t1 = read(p1);
    printf("First Polynomial: ");
    display(p1, t1);

    printf("Second Polynomial\n");
    t2 = read(p2);
    printf("Second Polynomial: ");
    display(p2, t2);

    printf("Multiplication Result\n");
    t3 = multiply(p1, p2, p3, t1, t2);
    display(p3, t3);
}
