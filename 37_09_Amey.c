#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed to stack.\n", value);
}
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* temp = top;
    int popped = temp->data;
    top = top->next;

    free(temp);
    return popped;
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void display() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    printf("Top element is %d\n", peek());

    printf("%d popped from stack\n", pop());
    display();

    return 0;
}
