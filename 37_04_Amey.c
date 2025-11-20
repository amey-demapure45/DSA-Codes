#include <stdio.h>
#define SIZE 20

int arr[SIZE];
int front1 = -1, rear1 = -1;
int front2 = SIZE, rear2 = SIZE;

void enqueue1(int x) {
    if (rear1 + 1 == rear2) {
        printf("Queue Overflow\n");
        return;
    }

    if (front1 == -1) front1 = 0;  

    arr[++rear1] = x;
}

void enqueue2(int x) {
    if (rear1 + 1 == rear2) {
        printf("Queue Overflow\n");
        return;
    }

    if (front2 == SIZE) front2 = SIZE - 1; 

    arr[--rear2] = x;
}

int dequeue1() {
    if (front1 == -1) {
        printf("Queue 1 Underflow\n");
        return -1;
    }

    int val = arr[front1++];

    if (front1 > rear1) { 
        front1 = rear1 = -1;
    }

    return val;
}

int dequeue2() {
    if (front2 == SIZE) {
        printf("Queue 2 Underflow\n");
        return -1;
    }

    int val = arr[front2--];

    if (front2 < rear2) {  
        front2 = rear2 = SIZE;
    }

    return val;
}

int main() {
    enqueue1(10);
    enqueue1(20);
    enqueue2(100);
    enqueue2(200);

    printf("Dequeued from Q1: %d\n", dequeue1());
    printf("Dequeued from Q2: %d\n", dequeue2());

    return 0;
}
