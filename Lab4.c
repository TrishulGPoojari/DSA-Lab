/*Develop a Program in C for converting an Infix Expression to Postfix Expression. Program should support for both parenthesized and free parenthesized expressions with the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

char infix[SIZE], postfix[SIZE], stack[SIZE];
int top = -1;

// Function prototypes
void evaluate();
void push(char item);
char pop();
int prec(char symb);

void evaluate() {
    int i = 0, j = 0;  //i iterates over infix and j iterates over postfix
    char symb, temp;    //temp is used to store the poped elements
    
    push('#');  // Initial marker on stack
    for (i = 0; infix[i] != '\0'; i++) {
        symb = infix[i];
        switch (symb) {
            case '(': 
                push(symb); //push into the stack 
                break;
            case ')':
                temp = pop();  //pops the top element from stack logically the element before the ')'
                while (temp != '(') {   //pop all the elements in the braces 
                    postfix[j++] = temp; //adding it on the postfix string
                    temp = pop();
                }
                break;
            case '+':   //in any of this case we pop the top element from the stack and add it to the postfix string    
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
            case '$':
                 // Compares the precedence of the operator on the stack and the symb
                while (prec(stack[top]) >= prec(symb)) {  
                    temp = pop();      //push all the higher precedence operators into the postfix string
                    postfix[j++] = temp;
                }
                push(symb); //if the operator(symb) had higher precedence then push it on the stack
                break;
            default:
                // Append operand directly to postfix expression as it is an operand 
                postfix[j++] = symb;
        }
    }
    
    // Pop remaining operators from the stack
    while (top > 0) {  //excluding top=0 because we pushed '#' at the beginning
        temp = pop();
        postfix[j++] = temp;
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

void push(char item) {
    if (top >= SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

//this prec() is used to check the precedence of the operator by returning specify value belonging to that operator
int prec(char symb) {           
    switch (symb) {
        case '#': return -1;
        case '(':
        case ')': return 0;  
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '^':
        case '$': return 3; //it has the highest precedence 
        default: return -1;  // For invalid operators
    }
}

int main() {
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    
    evaluate();
    
    printf("The entered infix expression is: %s\n", infix);
    printf("The postfix expression is: %s\n", postfix);
    
    return 0;
}
