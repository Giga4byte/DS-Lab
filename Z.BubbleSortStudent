# include <stdio.h>

void bubble_sort (int n, int a[]) {
    int i,j, temp;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {
            if (a[j]>a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            } // if block
        } // for j block
    } // for i block
} // bubble sort block

struct student {
    char name [50];
    int rollno;
    int m1,m2,m3,m4,m5,mtot;
};

void main ()
{
    struct student s[100];
    int n,i;
    
    printf ("Enter the number of student details: ");
    scanf ("%d",&n);
    
    for (i=0; i<n ; i++)
    {
        printf("Name: ");
        scanf(" %[^\n]s", s[i].name);

        printf("Roll number: ");
        scanf("%d", &s[i].rollno);

        printf("Marks of 5 subs: ");
        scanf("%d%d%d%d%d", &s[i].m1, &s[i].m2, &s[i].m3, &s[i].m4, &s[i].m5);
    }
    
    for (i=0; i<n ; i++) 
    {
        s[i].mtot = s[i].m1 + s[i].m2 + s[i].m3 + s[i].m4 + s[i].m5;
        printf("Total marks of student %d: %d\n", i+1, s[i].mtot);
    }
    
    int mtot_array [100];
    
    for (i=0; i<n ; i++) 
    {mtot_array[i] = s[i].mtot;}

    bubble_sort (n,mtot_array); // function call
    
    printf ("MARK ORDER\n");
    for (i=0; i<n; i++) 
    {
        printf ("%d\t",mtot_array[i]);
    }
}
