#include <stdio.h>

int main() {
    int a[20], flag = 0, i, n, item, l = 0, u, mid;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) 
    { scanf("%d", &a[i]); }

    printf("Enter the element to be searched: ");
    scanf("%d", &item);

    u = n - 1; 

    while (l <= u) 
    {
        mid = (l + u) / 2;
        if (item > a[mid]) 
        { l = mid + 1; } 
        else if (item < a[mid]) 
        { u = mid - 1; } 
        else if (item == a[mid]) 
        {   flag = 1;
            printf("Element %d found at index %d\n", item, mid);
            break;  }
    }

    if (flag == 0) 
    { printf("Element not found\n"); }

    return 0;
}

