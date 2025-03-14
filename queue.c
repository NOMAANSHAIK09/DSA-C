#include <stdio.h>

#define SIZE 5  // Define the size of the queue

int ar[SIZE];
int eflag, dflag;

void enque(int element) {
    if (eflag < SIZE - 1) {  // Check if the queue is full
        eflag++;
        ar[eflag] = element;
    } else {
        printf("Queue is full\n");
    }
}

int deque() {
    int element;
    if (dflag < eflag) {  // Check if the queue is empty
        dflag++;
        element = ar[dflag];
        return element;
    } else {
        printf("Queue is empty\n");
        return -1;  // Return an invalid value when queue is empty
    }
}

void main() {
    int x;
    eflag = dflag = -1;  // Initialize both flags to -1 (empty state)

    enque(10);
    enque(20);
    enque(30);
    enque(40);
    enque(50);
    enque(60);  // This will print "Queue is full"

    x = deque();
    if (x != -1) {
        printf("%d\n", x);
    }
}
