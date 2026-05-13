#include <stdio.h>

int main()
{
    int n, m;
    int i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[n][m];
    int max[n][m];
    int need[n][m];
    int available[m];

    int process;
    int request[m];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nEnter process number making request: ");
    scanf("%d", &process);

    printf("Enter request for process P%d:\n", process);
    for(i = 0; i < m; i++)
    {
        scanf("%d", &request[i]);
    }

    for(i = 0; i < m; i++)
    {
        if(request[i] > need[process][i])
        {
            printf("\nError: Request exceeds need.\n");
            return 0;
        }
    }

    for(i = 0; i < m; i++)
    {
        if(request[i] > available[i])
        {
            printf("\nResources not available.\n");
            return 0;
        }
    }

    for(i = 0; i < m; i++)
    {
        available[i] = available[i] - request[i];
        allocation[process][i] = allocation[process][i] + request[i];
        need[process][i] = need[process][i] - request[i];
    }

    int work[m];
    int finish[n];
    int safeSeq[n];
    int count = 0;

    for(i = 0; i < m; i++)
    {
        work[i] = available[i];
    }

    for(i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible == 1)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] = work[k] + allocation[i][k];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            break;
        }
    }

    if(count == n)
    {
        printf("\nSystem is in SAFE state.\n");

        printf("Safe Sequence: ");
        for(i = 0; i < n; i++)
        {
            printf("P%d ", safeSeq[i]);
        }
    }
    else
    {
        printf("\nSystem is in DEADLOCK state.\n");

        printf("Deadlocked Processes: ");
        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                printf("P%d ", i);
            }
        }
    }

    return 0;
}
