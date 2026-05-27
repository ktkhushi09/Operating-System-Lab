#include<stdio.h>
int main()
{
    int frames, n, i, j, k;
    int pages[50];

    printf("Enter the number of Frames: ");
    scanf("%d", &frames);

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    int fifo[10], index = 0, faults = 0, found;

    for(i = 0; i < frames; i++)
        fifo[i] = -1;

    printf("\nFIFO Page Replacement Process:\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < frames; j++)
        {
            if(fifo[j] == pages[i])
            {
                found = 1;
                break;
            }
        }
    if(found == 0)
        {
            fifo[index] = pages[i];
            index = (index + 1) % frames;
            faults++;

            printf("PF No. %d: ", faults);

            for(j = 0; j < frames; j++)
            {
                if(fifo[j] == -1)
                    printf("- ");
                else
                    printf("%d ", fifo[j]);
            }
            printf("\n");
        }
    }
    printf("FIFO Page Faults: %d\n", faults);
    int lru[10], time[10], count = 0;
    faults = 0;

    for(i = 0; i < frames; i++)
    {
        lru[i] = -1;
        time[i] = 0;
    }
    printf("\nLRU Page Replacement Process:\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < frames; j++)
        {
            if(lru[j] == pages[i])
            {
                count++;
                time[j] = count;
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            int pos = 0;

            for(j = 1; j < frames; j++)
            {
                if(time[j] < time[pos])
                    pos = j;
            }

            count++;
            lru[pos] = pages[i];
            time[pos] = count;
            faults++;

            printf("PF No. %d: ", faults);

            for(j = 0; j < frames; j++)
            {
                if(lru[j] == -1)
                    printf("- ");
                else
                    printf("%d ", lru[j]);
            }
            printf("\n");
        }
    }

    printf("LRU Page Faults: %d\n", faults);
    int opt[10];
    faults = 0;

    for(i = 0; i < frames; i++)
        opt[i] = -1;

    printf("\nOptimal Page Replacement Process:\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < frames; j++)
        {
            if(opt[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            int pos = -1, farthest = i + 1;

            for(j = 0; j < frames; j++)
            {
                int next = -1;

                for(k = i + 1; k < n; k++)
                {
                    if(opt[j] == pages[k])
                    {
                        next = k;
                        break;
                    }
                }

                if(next == -1)
                {
                    pos = j;
                    break;
                }

                if(next > farthest)
                {
                    farthest = next;
                    pos = j;
                }
            }

            if(pos == -1)
                pos = 0;

            opt[pos] = pages[i];
            faults++;

            printf("PF No. %d: ", faults);

            for(j = 0; j < frames; j++)
            {
                if(opt[j] == -1)
                    printf("- ");
                else
                    printf("%d ", opt[j]);
            }
            printf("\n");
        }
    }

    printf("Optimal Page Faults: %d\n", faults);

    return 0;
}
