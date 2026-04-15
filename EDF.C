#include <stdio.h>

#define MAX 50

// Function to find GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    int C[MAX], T[MAX], D[MAX];
    int remaining[MAX], deadline[MAX];
    float U = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter capacity, period and deadline for P%d : ", i + 1);
        scanf("%d%d%d", &C[i],&T[i],&D[i]);

        remaining[i] = 0;
        deadline[i] = 0;

        U += (float)C[i] / T[i];
    }

    printf("\nCPU Utilization = %.2f\n", U);

    if (U > 1)
        printf("Not feasible\n");
    else
        printf("Feasible\n");

    // ✅ Compute hyperperiod (LCM of all periods)
    int endTime = T[0];
    for (int i = 1; i < n; i++) {
        endTime = lcm(endTime, T[i]);
    }

    printf("\nSimulation runs till time = %d\n\n", endTime);

    int t = 0;

    while (t < endTime) {

        // Release new jobs
        for (int i = 0; i < n; i++) {
            if (t % T[i] == 0) {
                remaining[i] = C[i];
                deadline[i] = t + D[i];
            }
        }

        int idx = -1, minDeadline = 100000;

        // Select task with earliest deadline
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                if (deadline[i] < minDeadline) {
                    minDeadline = deadline[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            printf("Time %d: CPU Idle\n", t);
        } else {
            printf("Time %d: P%d\n", t, idx + 1);
            remaining[idx]--;
        }

        t++;
    }

    return 0;
}

