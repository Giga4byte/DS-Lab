#include <stdio.h>

#define MAX_TERMS 10 // Maximum number of terms in each polynomial

// Structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
};

// Function to add two polynomials and return the number of terms in the resultant polynomial
int addPolynomials(struct Term poly1[], int p, struct Term poly2[], int q, struct Term result[]) {
    int i = 0, j = 0, k = 0;

    while (i < p && j < q) {
        if (poly1[i].exponent > poly2[j].exponent) {
            result[k].exponent = poly1[i].exponent;
            result[k].coefficient = poly1[i].coefficient;
            i++;
        } else if (poly1[i].exponent < poly2[j].exponent) {
            result[k].exponent = poly2[j].exponent;
            result[k].coefficient = poly2[j].coefficient;
            j++;
        } else {
            result[k].exponent = poly1[i].exponent;
            result[k].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            i++;
            j++;
        }
        k++;
    }

    while (i < p) {
        result[k].exponent = poly1[i].exponent;
        result[k].coefficient = poly1[i].coefficient;
        i++;
        k++;
    }

    while (j < q) {
        result[k].exponent = poly2[j].exponent;
        result[k].coefficient = poly2[j].coefficient;
        j++;
        k++;
    }

    return k; // Number of terms in the resultant polynomial
}

// Function to display a polynomial
void displayPoly(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
        if (i < n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int choice;
    int p = 0, q = 0; // Number of terms in polynomial A and B
    struct Term poly1[MAX_TERMS];
    struct Term poly2[MAX_TERMS];
    struct Term result[MAX_TERMS];

    do {
        printf("\nMenu:\n");
        printf("1. Enter Polynomial A\n");
        printf("2. Enter Polynomial B\n");
        printf("3. Add Polynomials\n");
        printf("4. Display Polynomials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (p < MAX_TERMS) {
                    int degree;
                    printf("Enter the degree of Polynomial A: ");
                    scanf("%d", &degree);

                    printf("Enter coefficients for Polynomial A (from highest degree to constant term):\n");
                    for (int i = degree; i >= 0; i--) {
                        printf("Coefficient for x^%d: ", i);
                        scanf("%d", &poly1[p].coefficient);
                        poly1[p].exponent = i;
                        p++;
                    }
                } else {
                    printf("Polynomial A is full. Cannot add more terms.\n");
                }
                break;

            case 2:
                if (q < MAX_TERMS) {
                    int degree;
                    printf("Enter the degree of Polynomial B: ");
                    scanf("%d", &degree);

                    printf("Enter coefficients for Polynomial B (from highest degree to constant term):\n");
                    for (int i = degree; i >= 0; i--) {
                        printf("Coefficient for x^%d: ", i);
                        scanf("%d", &poly2[q].coefficient);
                        poly2[q].exponent = i;
                        q++;
                    }
                } else {
                    printf("Polynomial B is full. Cannot add more terms.\n");
                }
                break;

            case 3:
                if (p == 0 || q == 0) {
                    printf("Please enter both Polynomial A and Polynomial B first.\n");
                } else {
                    int r = addPolynomials(poly1, p, poly2, q, result);
                    printf("Resultant Polynomial (A + B): ");
                    displayPoly(result, r);
                }
                break;

            case 4:
                printf("Polynomial A: ");
                displayPoly(poly1, p);
                printf("Polynomial B: ");
                displayPoly(poly2, q);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
