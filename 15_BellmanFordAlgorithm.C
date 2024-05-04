#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

// Bellman-Ford algorithm with adjacency matrix
void BellmanFord(int graph[MAX_VERTICES][MAX_VERTICES], int V, int src) {
    int d[MAX_VERTICES]; // Array to store distances

    // Initialize distances from src to all other vertices as INFINITY
    for (int i = 0; i < V; i++) {
        d[i] = INT_MAX;
    }
    d[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && d[u] != INT_MAX && d[u] + graph[u][v] < d[v]) {
                    d[v] = d[u] + graph[u][v];
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && d[u] != INT_MAX && d[u] + graph[u][v] < d[v]) {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }

    // Print the distances from src to all vertices
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, d[i]);
    }
}

int main() {
    int V = 5; // Number of vertices
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, -1, 4, 0, 0},
        {0, 0, 3, 2, 2},
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, -3, 0}
    };
    int src = 0; // Source vertex

    BellmanFord(graph, V, src);

    return 0;
}
