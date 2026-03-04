#include <stdio.h>
int main()
{
    int n;
    int at[20], bt[20], ct[20], wt[20], tat[20];
    int completed[20];
    int i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        completed[i] = 0;
    }
    int time = 0, count = 0;
    while(count < n)
    {
        int min_bt = 9999, min_index = -1;
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && completed[i] == 0)
            {
                if(bt[i] < min_bt)
                {
                    min_bt = bt[i];
                    min_index = i;
                }
            }
        }
        if(min_index == -1)
        {
            time++;
        }
        else
        {
            ct[min_index] = time + bt[min_index];
            tat[min_index] = ct[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];
            time = ct[min_index];
            completed[min_index] = 1;
            count++;
        }
    }
    float twt = 0, ttat = 0;
    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");
    for(i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
        twt += wt[i];
        ttat += tat[i];
    }
    printf("\nAverage Waiting Time = %.2f", twt / n);
    printf("\nAverage Turnaround Time = %.2f", ttat / n);
    return 0;
}
