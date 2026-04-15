#include <stdio.h>
#include <math.h>

#define MAX 50

void sortByPeriod(int id[], float C[], float T[], int n) {
    int tempId;
    float tempC, tempT;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (T[i] > T[j]) {
                tempId = id[i];
                id[i] = id[j];
                id[j] = tempId;

                tempC = C[i];
                C[i] = C[j];
                C[j] = tempC;

                tempT = T[i];
                T[i] = T[j];
                T[j] = tempT;
            }
        }
    }
}

int main() {
    int n;
    int id[MAX];
    float C[MAX], T[MAX];
    int remaining[MAX];
    float U = 0.0, bound;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        id[i] = i + 1;
        printf("Enter execution time (C%d): ", i + 1);
        scanf("%f", &C[i]);
        printf("Enter period (T%d): ", i + 1);
        scanf("%f", &T[i]);
        remaining[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        U += (C[i] / T[i]);
    }

    bound = n * (pow(2, (1.0 / n)) - 1);

    printf("\nCPU Utilization (U) = %.4f\n", U);
    printf("RMS Bound = %.4f\n", bound);

    if (U <= bound)
        printf("Schedulable using RMS\n");
    else
        printf("Not guaranteed schedulable\n");

    sortByPeriod(id, C, T, n);

    printf("\nTask Priorities:\n");
    for (int i = 0; i < n; i++) {
        printf("Priority %d -> Task %d (T = %.2f)\n", i + 1, id[i], T[i]);
    }

    int time = 0, endTime = 20;

    while (time < endTime) {

        for (int i = 0; i < n; i++) {
            if (time % (int)T[i] == 0) {
                remaining[i] = (int)C[i];
            }
        }

        int executed = 0;

        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                printf("Time %d: T%d\n", time, id[i]);
                remaining[i]--;
                executed = 1;
                break;
            }
        }

        if (!executed) {
            printf("Time %d: CPU Idle\n", time);
        }

        time++;
    }

    return 0;
}
