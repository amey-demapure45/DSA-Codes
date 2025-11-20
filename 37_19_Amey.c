#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n;                    
int graph[MAX][MAX];         
int visited[MAX];
int disc[MAX], low[MAX], parent[MAX];
int timeD = 0;
int articulation = 0;

void DFS(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeD;
    int child = 0;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (!visited[v]) {
                child++;
                parent[v] = u;

                DFS(v);

                low[u] = (low[v] < low[u]) ? low[v] : low[u];

                if (parent[u] != -1 && low[v] >= disc[u])
                    articulation = 1;

                if (parent[u] == -1 && child > 1)
                    articulation = 1;
            }
            else if (v != parent[u]) {
                low[u] = (disc[v] < low[u]) ? disc[v] : low[u];
            }
        }
    }
}

void checkConnected(int start) {
    DFS(start);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) articulation = 1;
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    checkConnected(0);

    if (articulation == 0)
        printf("\nGraph is **Biconnected**\n");
    else
        printf("\nGraph is **NOT Biconnected**\n");

    return 0;
}
