#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


char infix[10];
char postfix[10];
char stack[10];
int top = -1;

//checking precedence
int precedence (char operators) {
    if (operators == '^')
        return 3;
    else if (operators == '*' || operators == '/')
        return 2;
    else if (operators == '+' || operators == '-')
        return 1;
    else
        return 0;
}

void push (char x) {
    if (top == 9) {
        printf("STACK IS FULL\n");
    } 
    else {
        top = top + 1;
        stack[top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("STACK IS EMPTY\n");
        return '\0';
        //Done to ensure stack indeed is empty
    } 
    else {
        char x = stack[top];
        top = top - 1;
        return x;
    }
}

//classifying operators
int operand(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

void infixpostfix() {
    int length = strlen(infix);
    int index = 0;

    for (int i = 0; i < length; i++) {
        char x = infix[i];

        if (x == ' ' || x == '\t') {
            continue;
        } 
        else if (operand(x)) {
            postfix[index++] = x;
        } 
        else if (x == '(') {
            push(x);
        } 
        else if (x == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[index++] = pop();
            }
            pop(); // Pop '('
        } 
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(x)) {
                postfix[index++] = pop();
            }
            push(x);
        }
    }

    while (top != -1) {
        postfix[index++] = pop();
    }

    postfix[index] = '\0';
}

void main() {
    printf("Enter an infix expression: ");
    scanf("%[^\n]", infix);

    infixpostfix();

    printf("Postfix expression: %s\n", postfix);
    
    int result = 0; 
    int i; char x;
    
    int length = strlen(postfix);
    int stack[10];
    int top = -1;

    for (i = 0; i < length; i++) {
        x = postfix[i];
        if (isdigit(x)) {  // Check if x is a digit - ctype.h
            stack[++top] = x - '0';  // Convert char to int
        } 
        else {
            int op2 = stack[top--];
            int op1 = stack[top--];

            switch (x) {
                case '+':
                    stack[++top] = op1 + op2;
                    break;
                case '-':
                    stack[++top] = op1 - op2;
                    break;
                case '*':
                    stack[++top] = op1 * op2;
                    break;
                case '/':
                    stack[++top] = op1 / op2;
                    break;
                case '^':
                    stack[++top] = pow(op1, op2);
                    break;
            }
        }
    }

    if (top == 0) {
        result = stack[top];
        printf("RESULT: %d\n", result);
    } 
    else {
        printf("RESULT: can't be found\n");
    }

}
