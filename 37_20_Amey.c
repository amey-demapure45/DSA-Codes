#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX], top = -1;
int n;

void topoDFS(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            topoDFS(i);
    }

    stack[++top] = v;  
}
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of DAG:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            topoDFS(i);

    printf("\nTopological Sort (DFS): ");
    while (top >= 0)
        printf("%d ", stack[top--]);

    return 0;
}
