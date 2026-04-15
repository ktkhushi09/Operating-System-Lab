#include <stdio.h>
#define MAX 50
int main() {
    int n;
    int burst[MAX], remaining[MAX], weight[MAX];
    float time_slice[MAX];
    int completed[MAX] = {0};
    int total_weight = 0;
    int TIME_QUANTUM;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Enter weight for P%d: ", i + 1);
        scanf("%d", &weight[i]);
        remaining[i] = burst[i];
        total_weight += weight[i];
    }
    printf("Enter total TIME QUANTUM: ");
    scanf("%d", &TIME_QUANTUM);
    printf("\n--- Proportional Share Scheduling ---\n");
    while (1) {
        int all_done = 1;
        for (int i = 0; i < n; i++) {
            if (!completed[i]) {
                all_done = 0;
                time_slice[i] = ((float)weight[i] / total_weight) * TIME_QUANTUM;
                int exec_time = (int)time_slice[i];
                if (exec_time <= 0)
                    exec_time = 1;
                if (remaining[i] < exec_time)
                    exec_time = remaining[i];
                printf("Process P%d runs for %d units\n", i + 1, exec_time);
                remaining[i] -= exec_time;
                if (remaining[i] <= 0) {
                    completed[i] = 1;
                    total_weight -= weight[i];
                    printf("Process P%d completed\n", i + 1);
                }
            }
        }
        if (all_done)
            break;
    }
    return 0;
}
