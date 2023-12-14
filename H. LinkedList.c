#include <stdio.h>
#include <stdlib.h>

int item;

struct node {
	int data;
	struct node *next;
};

struct node *p, *head, *tail, *pointer, *previous;

void insertAtEnd ()
{
	p = (struct node*)malloc(sizeof(struct node));
	printf ("Enter the element to be inserted: ");
	scanf ("%d", &p->data);
	p->next = NULL;
	if (head == NULL)
	{
		head = p;
		tail = p;
	}
	else
	{
		tail->next = p;
		tail = p;
	}
}

void insertAtBeginning () 
{
	p = (struct node*)malloc(sizeof(struct node));
	printf ("Enter the element to be inserted: ");
	scanf ("%d", &p->data);
	p->next = NULL;
	if (head == NULL)
	{
		head =p;
		tail = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
}

void insertAfterNode ()
{
	p = (struct node*)malloc(sizeof(struct node));
	printf ("Enter the element to be inserted: ");
	scanf ("%d", &p->data);
	p->next = NULL;
	pointer = head;
	printf ("Enter the node: ");
	scanf ("%d", &item);
	while (pointer->data != item)
	{
		pointer  = pointer->next;
	}
	p->next=pointer->next;
	pointer->next=p;
}

void deleteFromBeginning ()
{
	if (head == NULL)
	{ printf ("LIST IS EMPTY\n"); }
	else
	{
		pointer = head;
		head = pointer->next;
		free (pointer);
	}
}

void deleteFromEnd ()
{
	if (head == NULL)
	{ printf ("LIST IS EMPTY"); }
	else
	{
		pointer = head;
		while (pointer->next != NULL)
		{
			previous = pointer;
			pointer = pointer->next;
		}
		previous->next = NULL;
		tail = previous;
		free (pointer);
	}
}

void deleteNode ()
{
	printf ("Enter the node: ");
	scanf ("%d", &item);
	pointer = head;
	//previous = head;
	if (head == NULL) {
	printf ("Empty list.\n"); }
	else {
	while (pointer->data != item);
	{
		previous = pointer;
		pointer = pointer->next;
	}
	previous->next = pointer->next;
	free (pointer); }
}

void display ()
{
	if (head == NULL)
	{ printf ("LIST IS EMPTY\n"); }
	else
	{
		pointer = head;
		while (pointer->next != NULL)
		{
			printf ("%d\t", pointer->data);
			pointer = pointer->next;
		}
		printf ("%d\t", pointer->data);
	}
}

int main ()
{
	int choice = -1; head = NULL;
	printf ("MENU\n1. End Insert\n2. Beginning Insert\n3. Node Insert\n4. End Delete\n5. Beginning Delete\n6. Node Delete\n7. Display\n8. Exit\n");
	while (1)
	{
		printf ("\nEnter choice: ");
		scanf ("%d", &choice);
		switch (choice)
		{
			case 1: insertAtEnd();
					break;
			case 2: insertAtBeginning();
					break;
			case 3: insertAfterNode();
					break;
			case 4: deleteFromBeginning();
					break;
			case 5: deleteFromEnd();
					break;
			case 6: deleteNode();
					break;
			case 7: display();
					break;
			case 8: printf ("TERMINATED\n");
					return 0;
			default: printf ("INVALID CHOICE\n");
		}
	}
	return 0;
}
