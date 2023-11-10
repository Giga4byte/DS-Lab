#include <stdio.h>
#include <stdlib.h>

int item;

struct node {
    int data;
    struct node *next;
};

struct node *p, *top, *pointer;

void push ()
{
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &p->data);
    if (top == NULL)
    {   p->next = NULL;
        top = p;
        printf ("Element entered\n");   }
    else
    {   p->next = top;
        top = p;    
        printf ("Element entered\n");   }
}

void pop ()
{
    if (top == NULL)
    {   printf ("Stack is empty\n");  }
    else
    {   top = top->next;
        free (p);
        p = top;
        printf ("Element deleted\n");   }
}

void display () 
{
    if (top == NULL)
    {   printf ("Stack is empty\n");  }
    else
    {   while (p!=NULL)
        {   printf ("%d\t", p->data);
            p = p->next;    }    }
}

int main() {
    int choice = 0;
    top = NULL;
    printf ("NAME: GIRIBALA\tROLL NO:28\n");
    printf("MENU\n1. Push\n2. Pop\n3. Display\n4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(); break;
            case 2:
                pop(); break;
            case 3:
                display(); break;
            case 4:
                printf("TERMINATED\n");
                return 0;
            default:
                printf ("INVALID CHOICE, TRY AGAIN\n");
        }
    }
    return 0;
}
