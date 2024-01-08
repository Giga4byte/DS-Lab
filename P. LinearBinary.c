# include <stdio.h>

void linearSearch ()
{
	int n, i, sk, flag = 0;
	printf ("Enter the limit: ");
	scanf ("%d", &n);
	int a[n];
	printf ("Enter the elements: ");
	for (i=0; i<n; i++)
	{ scanf ("%d", &a[i]); }
	printf ("Enter the element to be searched: ");
	scanf ("%d", &sk);
	for (i=0; i<n; i++)
	{
		if (a[i] == sk)
		{ flag = 1;
		  printf ("Element found at %d\n", i+1); }
	}
	if (flag == 0)
	{ printf ("Element not found\n"); }
}

void binarySearch ()
{
	int n, i, sk, flag = 0, mid, s;
	printf ("Enter the limit: ");
	scanf ("%d", &n);
	int a[n];
	printf ("Enter the elements: ");
	for (i=0; i<n; i++)
	{ scanf ("%d", &a[i]); }
	printf ("Enter the element to be searched: ");
	scanf ("%d", &sk);
	int l = 0, u = n-1;
	while (l<=u)
	{
		mid = (l+u)/2;
		if (sk>a[mid])
		{ l = mid+1; }
		else if (sk<a[mid])
		{ u = mid-1; }
		else
		{ flag = 1;
		  printf ("Element found at %d\n", mid+1);
		  break; }
	}
	if (flag == 0)
	{ printf ("Element not found\n"); }
}

int main ()
{
	int c = 0;
	printf ("MENU:\n1. Linear Search\n2. Binary Search\n3. Exit\n");
	while (1)
	{
		printf ("\nEnter the choice: ");
		scanf ("%d", &c);
		
		switch (c)
		{
			case 1: linearSearch ();
					break;
			case 2: binarySearch ();
					break;
			case 3: printf ("TERMINATED\n");
					return 0;
			default: printf ("Invalid choice. Choose again\n");
		}
	}
}
