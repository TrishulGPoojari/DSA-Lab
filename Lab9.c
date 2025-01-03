#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a node structure for storing a polynomial term
typedef struct Node {
    float coeff; // Coefficient of the term
    int x, y, z; // Powers of x, y, z
    struct Node* next; // Pointer to the next term
} Node;

// Function to create a new term
Node* createNode(float coeff, int x, int y, int z) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->x = x;
    newNode->y = y;
    newNode->z = z;
    newNode->next = NULL;
    return newNode;
}

// Function to create a polynomial by taking user input
Node* createPolynomial() {
    int terms;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &terms);

    Node *head = NULL, *tail = NULL;

    // Loop to create terms
    for (int i = 0; i < terms; i++) {
        float coeff;
        int x, y, z;
        printf("Enter coefficient and powers of x, y, z (e.g., 3 2 1 0 for 3x^2y^1z^0): ");
        scanf("%f %d %d %d", &coeff, &x, &y, &z);

        Node* newNode = createNode(coeff, x, y, z);

        // Add the term to the polynomial
        if (head == NULL) {
            head = tail = newNode; // Initialize head and tail for the first term
        } else {
            tail->next = newNode; // Add subsequent terms at the end
            tail = newNode;
        }
    }

    return head;
}

// Function to display a polynomial
void displayPolynomial(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        // Print coefficient and powers in a readable format
        if (temp != head && temp->coeff > 0) printf("+");
        printf("%.1fx^%dy^%dz^%d ", temp->coeff, temp->x, temp->y, temp->z);
        temp = temp->next;
    }

    printf("\n");
}

// Function to evaluate a polynomial for given values of x, y, and z
void evaluatePolynomial(Node* head) {
    int x, y, z;
    printf("Enter values for x, y, and z: ");
    scanf("%d %d %d", &x, &y, &z);

    float result = 0;
    Node* temp = head;

    while (temp != NULL) {
        result += temp->coeff * pow(x, temp->x) * pow(y, temp->y) * pow(z, temp->z);
        temp = temp->next;
    }

    printf("Result of evaluation = %.2f\n", result);
}

// Function to add two polynomials
Node* addPolynomials(Node* p1, Node* p2) {
    Node *head = NULL, *tail = NULL;

    while (p1 != NULL && p2 != NULL) {
        Node* newNode;

        // Compare terms based on powers of x, y, z
        if (p1->x == p2->x && p1->y == p2->y && p1->z == p2->z) {
            // If powers are the same, add coefficients
            newNode = createNode(p1->coeff + p2->coeff, p1->x, p1->y, p1->z);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->x > p2->x || (p1->x == p2->x && p1->y > p2->y) || 
                   (p1->x == p2->x && p1->y == p2->y && p1->z > p2->z)) {
            // Add p1's term if it has higher powers
            newNode = createNode(p1->coeff, p1->x, p1->y, p1->z);
            p1 = p1->next;
        } else {
            // Add p2's term if it has higher powers
            newNode = createNode(p2->coeff, p2->x, p2->y, p2->z);
            p2 = p2->next;
        }

        // Add the new term to the result polynomial
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add remaining terms from p1
    while (p1 != NULL) {
        Node* newNode = createNode(p1->coeff, p1->x, p1->y, p1->z);
        if (head == NULL) head = tail = newNode;
        else tail->next = newNode, tail = newNode;
        p1 = p1->next;
    }

    // Add remaining terms from p2
    while (p2 != NULL) {
        Node* newNode = createNode(p2->coeff, p2->x, p2->y, p2->z);
        if (head == NULL) head = tail = newNode;
        else tail->next = newNode, tail = newNode;
        p2 = p2->next;
    }

    return head;
}

// Main function
int main() {
    int choice;
    Node *poly1 = NULL, *poly2 = NULL, *polySum = NULL;

    do {
        printf("\nMenu:\n");
        printf("1. Represent and Evaluate a Polynomial\n");
        printf("2. Add Two Polynomials\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nCreate Polynomial:\n");
            poly1 = createPolynomial();
            printf("Polynomial: ");
            displayPolynomial(poly1);
            evaluatePolynomial(poly1);
            break;
        case 2:
            printf("\nCreate First Polynomial:\n");
            poly1 = createPolynomial();
            printf("\nCreate Second Polynomial:\n");
            poly2 = createPolynomial();
            polySum = addPolynomials(poly1, poly2);
            printf("\nFirst Polynomial: ");
            displayPolynomial(poly1);
            printf("Second Polynomial: ");
            displayPolynomial(poly2);
            printf("Sum of Polynomials: ");
            displayPolynomial(polySum);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}
