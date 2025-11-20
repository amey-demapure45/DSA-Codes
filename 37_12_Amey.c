#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x; 
    n->next = NULL;

    if (!head) { head = n; return; }

    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

void insertBegin(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = head;
    head = n;
}

void deleteBegin() {
    if (!head) return;
    struct Node* t = head;
    head = head->next;
    free(t);
}

void reverse() {
    struct Node *prev = NULL, *cur = head, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

void findMiddle() {
    struct Node *s = head, *f = head;
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
    }
    if (s) printf("Middle = %d\n", s->data);
}

void sort() {
    for (struct Node* i = head; i; i = i->next)
        for (struct Node* j = i->next; j; j = j->next)
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
}

void detectLoop() {
    struct Node *s = head, *f = head;
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
        if (s == f) { printf("Loop found\n"); return; }
    }
    printf("No loop\n");
}

void sumData() {
    int sum = 0;
    struct Node* t = head;
    while (t) { sum += t->data; t = t->next; }
    printf("Sum = %d\n", sum);
}

void printOddEven() {
    struct Node* t = head;
    printf("Even: ");
    while (t) { if (t->data % 2 == 0) printf("%d ", t->data); t = t->next; }

    t = head;
    printf("\nOdd: ");
    while (t) { if (t->data % 2 != 0) printf("%d ", t->data); t = t->next; }
    printf("\n");
}

void display() {
    struct Node* t = head;
    while (t) { printf("%d -> ", t->data); t = t->next; }
    printf("NULL\n");
}

int main() {
    create(10);
    create(20);
    create(30);
    insertBegin(5);

    printf("List: ");
    display();

    findMiddle();
    sumData();
    printOddEven();

    reverse();
    printf("Reversed: ");
    display();

    sort();
    printf("Sorted: ");
    display();

    detectLoop();

    return 0;
}
