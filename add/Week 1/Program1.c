#include <stdio.h>
int main()
{
    int a[100], n, i;
    int smallest, secondSmallest;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    if(a[0] < a[1])
    {
        smallest = a[0];
        secondSmallest = a[1];
    }
    else
    {
        smallest = a[1];
        secondSmallest = a[0];
    }
    for(i = 2; i < n; i++)
    {
        if(a[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = a[i];
        }
        else if(a[i] < secondSmallest && a[i] != smallest)
        {
            secondSmallest = a[i];
        }
    }
    printf("Second smallest element = %d\n", secondSmallest);
    return 0;
}

