// THIS IS INCOMPLETE. DON'T BOTHER COPY-PASTING.

#include <stdio.h>
int item;

struct node {
    int data;
    struct node *next;
};

struct node *p, *head, *tail, *pointer;

void insertAtEnd() {
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &p->data);
    p->next = NULL;
    if (head == NULL) {
        head = p;
        tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
}

void insertAtBeginning() {
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &p->data);
    p->next = NULL;
    if (head == NULL) {
        head = p;
        tail = p;
    } else {
        p->next = head;
        head = p;
    }
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("The linked list is empty\n");
    } else {
        pointer = head;
        head = pointer->next;
        free(pointer);
    }
}

void display() {
    pointer = head;
    printf("GIRIBALA'S LINKED LIST IS\n");
    while (pointer != NULL) {
        printf("%d ", pointer->data);
        pointer = pointer->next;
    }
    if (pointer == NULL) {
        return 0;
    }
}

int main() {
    int choice = 0;
    printf ("NAME: GIRIBALA\tROLL NO:28\n");
    head = NULL;
    printf("MENU\n1. Insert at the end\n2. Insert at the beginning\n3. Insert after a specified node\n4. Delete from the end\n5. Delete from the beginning\n6. Delete a specified node\n7. Display\n8. EXIT\n\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtEnd();
                break;
            case 2:
                insertAtBeginning();
                break;
            case 3:
                insertAfterNode();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteAfterNode();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("TERMINATED\n");
                return 0;
        }
    }
}
