#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *p, *front, *rear, *ptr;

void enqueue() {
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &p->data);
    if (front == NULL && rear == NULL) {
        front = p;
        rear = p;
        printf("Element entered\n");
    } else {
        rear->next = p;
        rear = p;
        printf("Element entered\n");
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty, cannot dequeue\n");
    } else if (front == rear) {
        front = NULL;
        rear = NULL;
        printf("Element deleted\n");
    } else {
        ptr = front;
        front = ptr->next;
        free(ptr);
        printf("Element deleted\n");
    }
}

void display() {
    ptr = front;
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    int choice = 0;
    front = NULL;
    rear = NULL;
    printf("NAME: GIRIBALA\tROLL NO:28\n");
    printf("MENU\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("TERMINATED\n");
            return 0;
        default:
            printf("INVALID CHOICE, TRY AGAIN\n");
        }
    }
    return 0;
}
