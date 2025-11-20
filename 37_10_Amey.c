#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d enqueued to queue.\n", value);
}

int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node* temp = front;
    int removed = temp->data;

    front = front->next;

    if (front == NULL) 
        rear = NULL;

    free(temp);
    return removed;
}

int peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    printf("Front element = %d\n", peek());

    printf("%d dequeued\n", dequeue());
    display();

    return 0;
}
