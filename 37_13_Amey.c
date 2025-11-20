#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* head = NULL;

void create(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    n->prev = NULL;

    if (!head) { head = n; return; }

    struct Node* t = head;
    while (t->next) t = t->next;

    t->next = n;
    n->prev = t;
}

void insertBegin(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->prev = NULL;
    n->next = head;

    if (head) head->prev = n;

    head = n;
}

void deleteBegin() {
    if (!head) return;

    struct Node* t = head;
    head = head->next;

    if (head) head->prev = NULL;

    free(t);
}

void reverse() {
    struct Node *cur = head, *temp = NULL;

    while (cur) {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }

    if (temp) head = temp->prev;
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
    for (struct Node *i = head; i; i = i->next)
        for (struct Node *j = i->next; j; j = j->next)
            if (i->data > j->data) {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
}

void detectLoop() {
    struct Node *s = head, *f = head;
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
        if (s == f) { printf("Loop detected\n"); return; }
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

    printf("\nOdd: ");
    t = head;
    while (t) { if (t->data % 2 != 0) printf("%d ", t->data); t = t->next; }

    printf("\n");
}

void display() {
    struct Node* t = head;
    while (t) { printf("%d <-> ", t->data); t = t->next; }
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
