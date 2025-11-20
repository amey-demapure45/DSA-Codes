#include <stdio.h>
#define SIZE 20

int arr[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int x) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow\n");
        return;
    }
    arr[++top1] = x;
}

void push2(int x) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow\n");
        return;
    }
    arr[--top2] = x;
}

int pop1() {
    if (top1 == -1) {
        printf("Stack 1 Underflow\n");
        return -1;
    }
    return arr[top1--];
}

int pop2() {
    if (top2 == SIZE) {
        printf("Stack 2 Underflow\n");
        return -1;
    }
    return arr[top2++];
}

int main() {
    push1(10);
    push1(20);
    push2(100);
    push2(200);

    printf("Popped from stack1: %d\n", pop1());
    printf("Popped from stack2: %d\n", pop2());

    return 0;
}
