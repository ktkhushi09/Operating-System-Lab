#include<stdio.h>
int n,m;
int alloc[10][10],max[10][10],need[10][10];
int avail[10],finish[10],safe[10];
void calculateNeed()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
}
void bankers()
{
    int i,j,k=0;
    int work[10];
    int found;
    for(i=0;i<m;i++)
    {
        work[i]=avail[i];
    }
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    while(k<n)
    {
        found=0;
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int flag=1;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag==1)
                {
                    for(j=0;j<m;j++)
                    {
                        work[j]=work[j]+alloc[i][j];
                    }
                    printf("P%d is visited(",i);
                    for(j=0;j<m;j++)
                    {
                        printf("%d",work[j]);
                        if(j!=m-1)
                        {
                            printf(" ");
                        }
                    }
                    printf(")\n");
                    safe[k]=i;
                    k++;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(found==0)
        {
            break;
        }
    }
    if(k==n)
    {
        printf("SYSTEM IS IN SAFE STATE\n");
        printf("The Safe Sequence is -- (");
        for(i=0;i<n;i++)
        {
            printf(" P%d",safe[i]);
        }
        printf(" )\n\n");
        printf("Process\tAllocation\tMax\t\tNeed\n");
        for(i=0;i<n;i++)
        {
            printf("P%d\t",i);
            for(j=0;j<m;j++)
            {
                printf("%d ",alloc[i][j]);
            }
            printf("\t");
            for(j=0;j<m;j++)
            {
                printf("%d ",max[i][j]);
            }
            printf("\t");
            for(j=0;j<m;j++)
            {
                printf("%d ",need[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("SYSTEM IS NOT IN SAFE STATE");
    }
}
void request()
{
    int pid;
    int req[10];
    int i;
    printf("Enter New Request Details --\n");
    printf("Enter pid\t--\t");
    scanf("%d",&pid);
    printf("Enter Request for Resources\t--\t");
    for(i=0;i<m;i++)
    {
        scanf("%d",&req[i]);
    }
    for(i=0;i<m;i++)
    {
        if(req[i]>need[pid][i])
        {
            printf("Error: Process exceeded maximum claim\n");
            return;
        }
    }
    for(i=0;i<m;i++)
    {
        if(req[i]>avail[i])
        {
            printf("Resources not available\n");
            return;
        }
    }
    for(i=0;i<m;i++)
    {
        avail[i]=avail[i]-req[i];
        alloc[pid][i]=alloc[pid][i]+req[i];
        need[pid][i]=need[pid][i]-req[i];
    }
}
void main()
{
    int i,j;
    printf("Enter number of processes\t\t--\t");
    scanf("%d",&n);
    printf("Enter number of resources\t\t--\t");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        printf("\nEnter details for P%d\n",i);
        printf("Enter allocation\t\t--\t");
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
        printf("Enter Max\t\t\t--\t");
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("\nEnter Available Resources --\t");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
    calculateNeed();
    request();
    printf("\nOUTPUT\n\n");
    bankers();
}
