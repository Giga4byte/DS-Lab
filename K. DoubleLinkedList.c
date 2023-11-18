#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};

struct node *p, *head, *tail;

void InsertAtBeginning() {
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &p->data);
    if (head == NULL) {
        head = p;
        tail = p;
        p->prev = NULL;
        p->next = NULL;
        printf("Element has been inserted.\n");
    } else {
        p->next = head;
        p->prev = NULL;
        head->prev = p;
        head = p;
        printf("Element has been inserted.\n");
    }
}

void InsertAtEnd() {
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &p->data);
    if (head == NULL) {
        head = p;
        tail = p;
        p->prev = NULL;
        p->next = NULL;
        printf("Element has been inserted.\n");
    } else {
        p->next = NULL;
        tail->next = p;
        p->prev = tail;
        tail = p;
        printf("Element has been inserted.\n");
    }
}

void DeleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        ptr = head;
        head = ptr->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(ptr);
        printf("Element has been deleted.\n");
    }
}

void DeleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        ptr = tail;
        tail = ptr->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        free(ptr);
        printf("Element has been deleted.\n");
    }
}

void display() {
    printf("DISPLAYING DLL:\n");
    ptr = head;
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    int choice = 0;
    printf("MENU:\n1. Insert at the beginning\n2. Insert at the end\n5. Delete from the beginning\n6. Delete from the end\n7. Delete a specified node\n8. Display\n9. Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                InsertAtBeginning();
                break;
            case 2:
                InsertAtEnd();
                break;
            case 3:
                InsertAfterNode();
                break;
            case 4:
                InsertBeforeNode();
                break;
            case 8:
                display();
                break;
            case 9:
                printf("TERMINATING.\n");
                return 0;
        }
    }
    return 0;
}
