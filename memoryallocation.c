#include<stdio.h>

int main()
{
    int b[20], p[20], temp[20];
    int m, n, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter sizes of %d memory blocks:\n", m);
    for(i = 0; i < m; i++)
        scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter sizes of %d processes:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    // ---------------- FIRST FIT ----------------
    for(i = 0; i < m; i++)
        temp[i] = b[i];

    printf("\n--- First Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < n; i++)
    {
        int allocated = 0;

        for(j = 0; j < m; j++)
        {
            if(temp[j] >= p[i])
            {
                printf("%d\t\t%d\t\t%d\n", i + 1, p[i], j + 1);
                temp[j] = temp[j] - p[i];
                allocated = 1;
                break;
            }
        }

        if(allocated == 0)
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, p[i]);
    }

    // ---------------- BEST FIT ----------------
    for(i = 0; i < m; i++)
        temp[i] = b[i];

    printf("\n--- Best Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < n; i++)
    {
        int best = -1;

        for(j = 0; j < m; j++)
        {
            if(temp[j] >= p[i])
            {
                if(best == -1 || temp[j] < temp[best])
                    best = j;
            }
        }

        if(best != -1)
        {
            printf("%d\t\t%d\t\t%d\n", i + 1, p[i], best + 1);
            temp[best] = temp[best] - p[i];
        }
        else
        {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, p[i]);
        }
    }

    // ---------------- WORST FIT ----------------
    for(i = 0; i < m; i++)
        temp[i] = b[i];

    printf("\n--- Worst Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < n; i++)
    {
        int worst = -1;

        for(j = 0; j < m; j++)
        {
            if(temp[j] >= p[i])
            {
                if(worst == -1 || temp[j] > temp[worst])
                    worst = j;
            }
        }

        if(worst != -1)
        {
            printf("%d\t\t%d\t\t%d\n", i + 1, p[i], worst + 1);
            temp[worst] = temp[worst] - p[i];
        }
        else
        {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, p[i]);
        }
    }

    return 0;
}
