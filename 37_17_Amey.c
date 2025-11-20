#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

void addEdge(int u, int v) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = v;
    n->next = adj[u];
    adj[u] = n;

    n = malloc(sizeof(struct Node));
    n->data = u;
    n->next = adj[v];
    adj[v] = n;
}

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->data])
            DFS(temp->data);
        temp = temp->next;
    }
}
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n = 5;  

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    printf("DFS starting from node 0: ");
    for (int i = 0; i < n; i++) visited[i] = 0;
    DFS(0);

    printf("\nBFS starting from node 0: ");
    for (int i = 0; i < n; i++) visited[i] = 0;
    BFS(0);

    return 0;
}
