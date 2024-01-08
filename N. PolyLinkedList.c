# include <stdio.h>
# include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node *next;
};

struct node *p, *q, *r, *s, *head1, *head2, *head3, *tail1, *tail2, *tail3, *head4, *tail4, *ptr;


void PolyA (int n)
{
    int i = 0;
    while (i<n)
    {
        p = (struct node*)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent: ");
        scanf("%d%d", &p->coeff, &p->exp);
        p->next = NULL;

        if (head1 == NULL) {
            head1 = p;
            tail1 = p;
        } else {
            tail1->next = p;
            tail1 = p;
        }
        i++;
    }
}

void PolyB (int m)
{
    int j = 0;
    while (j<m)
    {
        q = (struct node*)malloc(sizeof(struct node));
        printf("Enter the coefficient and exponent: ");
        scanf("%d%d", &q->coeff, &q->exp);
        q->next = NULL;

        if (head2 == NULL) {
            head2 = q;
            tail2 = q;
        } else {
            tail2->next = q;
            tail2 = q;
        }
        j++;
    }
}

void Add ()
{
    p = head1;
    q = head2;

    while (p != NULL && q != NULL) {
        r = (struct node*)malloc(sizeof(struct node));

        if (head3 == NULL) {
            head3 = r;
            tail3 = r;
        } else {
            tail3->next = r;
            tail3 = r;
        }

        if (p->exp > q->exp) {
            r->exp = p->exp;
            r->coeff = p->coeff;
            p = p->next;
        } 
        else if (p->exp < q->exp) {
            r->exp = q->exp;
            r->coeff = q->coeff;
            q = q->next;
        } 
        else {
            if ((p->coeff + q->coeff) != 0) {
            r->exp = p->exp;
            r->coeff = p->coeff + q->coeff;
            }
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL) {
        r = (struct node*)malloc(sizeof(struct node));

        if (head3 == NULL) {
            head3 = r;
            tail3 = r;
        } else {
            tail3->next = r;
            tail3 = r;
        }
        r->exp = p->exp;
        r->coeff = p->coeff;
        p = p->next;
    }

    while (q != NULL) {
        r = (struct node*)malloc(sizeof(struct node));

        if (head3 == NULL) {
            head3 = r;
            tail3 = r;
        } else {
            tail3->next = r;
            tail3 = r;
        }
        r->exp = q->exp;
        r->coeff = q->coeff;
        q = q->next;
    }
    r = head3;
    ptr = head3;
    printf("\nThe resultant polynomial is:\n");
    while (r != NULL) {
        if (r->coeff != 0) {
            printf("%d  %d\t", r->coeff, r->exp);
            r = r->next;
        }
    }
}

void Multiply () 
{
    p = head1;
    
    while (p != NULL)
    {
        q = head2;
        while (q != NULL)
        {
            s = (struct node *) malloc (sizeof (struct node));
            if (head4 == NULL)
            {
                head4 = s;
                tail4 = s;
            }
            else
            {
                tail4->next = s;
                tail4 = s;
            }
            
            s->coeff = p->coeff * q->coeff;
            s->exp = p->exp + q->exp;
            q = q->next;
        } // while for q
        p = p->next;
    } // while for p
    
    s = head4;
    ptr = head4;
    printf ("The resultant polynomial is:\n");
    while (ptr != NULL)
    {
        printf ("%d  %d\t", ptr->coeff, ptr->exp);
        ptr = ptr->next;
    }
}

int main ()
{
    int choice, termA, termB; 
    head1 = NULL; head2 = NULL; head3 = NULL; 
    
    printf ("MENU:\n1. Polynomial A\n2. Polynomial B\n3. Add and display\n4. Multiply and display\n");
    
    while (1)
    {
        printf ("\nEnter the choice: ");
        scanf ("%d", &choice);
        
        switch (choice)
        {
            case 1: printf ("Enter terms in A: ");
                    scanf ("%d", &termA);
                    PolyA (termA);
                    p = head1;
                    printf("Polynomial 1:\n");
                    while (p != NULL) {
                        printf("%d  %d\t", p->coeff, p->exp);
                        p = p->next;
                    }
                    break;
            case 2: printf ("Enter terms in B: ");
                    scanf ("%d", &termB);
                    PolyB (termB);
                    q = head2;
                    printf("Polynomial 2:\n");
                    while (q != NULL) {
                        printf("%d  %d\t", q->coeff, q->exp);
                        q = q->next;
                    }
                    break;
            case 3: Add ();
            	    return 0;
                    break;
            case 4: Multiply ();
                    return 0;
                    break;
            /*case 5: printf ("Terminating\n");
                    return 0;*/
            default: printf ("Invalid choice\n");
        }// switch case
    }
    
    return 0;
}
