#include <stdio.h>

int stack[100]; // Maximum size set to 100, can be changed by the user
int top = -1;
int n;

void push(int item) {
    if (top == n - 1) {
        printf("Stack is Full. Cannot push.\n");
    } else {
        top++;
        stack[top] = item;
        printf("Pushed %d onto the stack.\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is Empty. Cannot pop.\n");
    } else {
        printf("Popped %d from the stack.\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is Empty. Cannot peek.\n");
    } else {
        printf("Top of the stack: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is Empty.\n");
    } else {
        printf("Stack elements from top to bottom:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, item;

    printf("Enter the maximum size of the stack: ");
    scanf("%d", &n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
