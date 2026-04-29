#include <stdio.h>

#define MAX 10

int chopstick[5] = {1,1,1,1,1};
int room;
int n, hungry;
int pos[MAX];

// function prototypes
void think(int p);
void eat(int p);
void wait(int *s);
void signal(int *s);

void wait(int *s) {
    while(*s <= 0); // busy wait
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void think(int p) {
    // just placeholder
}

void eat(int p) {
    printf("P %d is granted to eat\n", p);
    printf("P %d has finished eating\n", p);
}

void philosopher(int i) {
    printf("P %d is waiting\n", i);

    wait(&room);

    wait(&chopstick[i-1]);              // left
    wait(&chopstick[i % 5]);            // right

    eat(i);

    signal(&chopstick[i-1]);            // release left
    signal(&chopstick[i % 5]);          // release right

    signal(&room);
}

int main() {
    int i, choice;

    printf("Enter the total number of philosophers: ");
    scanf("%d", &n);

    printf("How many are hungry: ");
    scanf("%d", &hungry);

    for(i = 0; i < hungry; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i+1, n);
        scanf("%d", &pos[i]);
    }

    do {
        printf("\n1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                room = 1;
                printf("Allow one philosopher to eat at any time\n");
                for(i = 0; i < hungry; i++) {
                    philosopher(pos[i]);
                }
                break;

            case 2:
                room = 2;
                printf("Allow two philosophers to eat at any time\n");
                for(i = 0; i < hungry; i++) {
                    philosopher(pos[i]);
                }
                break;

            case 3:
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 3);

    return 0;
}




