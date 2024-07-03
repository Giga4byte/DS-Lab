# include <stdio.h>

void main () 
{
    int a[10],i,n,sk,flag=1,*p;
    p = a; 
    
    printf ("Number of elements <10: ");
    scanf ("%d",&n);
    
    printf ("Enter elements: ");
    for (i=0;i<n;i++) {
        scanf ("%d",(p+i));
    }
    
    for (i=0;i<n;i++) {
        printf ("%d\t",*(p+i));
    }
    
    printf ("\nEnter the element to be searched: ");
    scanf ("%d", &sk);
    
    for (i=0;i<n;i++) {
        if (a[i]==sk)
        {
            printf ("Element %d found at %d.", sk, i+1);
            flag = 0;
        }
    }
    
    if (flag == 1)
    {
        printf("Element not found.");
    }
} //void main ()
