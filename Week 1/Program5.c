#include <stdio.h>
int main()
{
    int a[100], n, i;
    int largest, secondLargest;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    if(a[0] > a[1])
    {
        largest = a[0];
        secondLargest = a[1];
    }
    else
    {
        largest = a[1];
        secondLargest = a[0];
    }
    for(i = 2; i < n; i++)
    {
        if(a[i] > largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        else if(a[i] > secondLargest && a[i] != largest)
        {
            secondLargest = a[i];
        }
    }
    printf("Second largest element = %d\n", secondLargest);
    return 0;
}
