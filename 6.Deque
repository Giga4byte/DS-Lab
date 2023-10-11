#include <stdio.h>

int n, item;
int front = -1;
int rear = -1;
int deque[30];  // Declare an array to hold the deque elements

void insertFront(int item) {
    if (front == (rear-1)%n) {
        printf("Deque is full\n");
    } else if (front == 0) {
        front = n - 1;
        deque[front] = item;
        printf("Element %d has been inserted\n", deque[front]);
    } else {
        front = (front - 1 + n) % n; // Handle negative values correctly
        deque[front] = item;
        printf("Element %d has been inserted\n", deque[front]);
    }
}

void insertRear(int item) {
    if (front == (rear-1)%n) {
        printf("Deque is full\n");
    }
    else {
        rear = (rear+1)%n;
        deque[rear] = item;
        printf("Element %d has been inserted\n", deque[rear]);
    }
}

void deleteFront() {
    if (front == rear) {
        printf("Deque is empty\n");
    } else {
        item = deque[front];
        front = (front + 1) % n; // Wrap around if front reaches the end
        printf("Element %d has been deleted\n", item);
    }
}

void deleteRear() {
    if (front == rear) {
        printf("Deque is empty\n");
    } else {
        item = deque[rear];
        rear = (rear - 1 + n) % n; // Wrap around if rear reaches the beginning
        printf("Element %d has been deleted\n", item);
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", deque[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;
    printf("Enter the max number of elements: ");
    scanf("%d", &n);
    
    printf("\nMenu:\n");
    printf("1. Insert at Front\n");
    printf("2. Insert at Rear\n");
    printf("3. Delete from Front\n");
    printf("4. Delete from Rear\n");
    printf("5. Display\n");
    printf("6. Quit\n");
    
    while (1) {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert at the front: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter element to insert at the rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Quitting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
