#include <stdio.h>

int Q[100];
int front = -1, rear = -1;
int n, item;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((rear + 1) % n == front);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        rear = (rear + 1) % n;
        Q[rear] = item;
        if (front == -1) {
            front = rear;
        }
        printf("Enqueued %d onto the queue.\n", item);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        item = Q[front];
        printf("Dequeued %d from the queue.\n", item);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % n;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Queue elements\n");
        do {
            printf("%d\n", Q[i]);
            i = (i + 1) % n;
        } while (i != (rear + 1) % n);
    }
}

int main() {
    int choice;

    printf("Enter the number of max elements: ");
    scanf("%d", &n);

    printf("\nMENU:\n1. Enqueue\n2. Dequeue\n3. Is Empty\n4. Is Full\n5. Display\n6. Exit\n");

    while (1) {
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            }
            case 2: {
                dequeue();
                break;
            }
            case 3: {
                if (isEmpty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            }
            case 4: {
                if (isFull()) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            }
            case 5: {
                display();
                break;
            }
            case 6: {
                printf("Terminating.\n");
                return 0;
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }
}
