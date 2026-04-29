#include <stdio.h>
#include <stdlib.h>

// Semaphore and buffer variables
int mutex = 1, full = 0, empty = 3;
int x = 0; // item count

// wait function
void wait() {
    mutex--;
}

// signal function
void signal() {
    mutex++;
}

// Producer function
void producer() {
    wait();
    full++;
    empty--;
    x++;
    printf("Producer has produced: Item %d\n", x);
    signal();
}

// Consumer function
void consumer() {
    wait();
    if(full > 0) {
        full--;
        empty++;
        printf("Consumer has consumed: Item %d\n", x);
        x--;
    } else {
        printf("Buffer is empty!\n");
    }
    signal();
}

// Main function with menu
int main() {
    int choice;
    while(1) {
        printf("\nEnter 1.Producer 2.Consumer 3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(empty == 0)
                    printf("Buffer is full!\n");
                else
                    producer();
                break;
            case 2:
                if(full == 0)
                    printf("Buffer is empty!\n");
                else
                    consumer();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
