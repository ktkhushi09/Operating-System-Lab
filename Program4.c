#include <stdio.h>
int main()
{
    int a[100], n, i, j, count = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                count++;
                break;
            }
        }
    }
    printf("Total number of duplicate elements = %d\n", count);
    return 0;
}
