#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
int minDistance(int dist[], int Q[], int V);
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int source);

int minDistance(int dist[], int Q[], int V) {
    int minDist = INT_MAX, minIndex;
    int i;
    for (i = 0; i < V; i++) {
        if (Q[i] == 1 && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int source) {
    int dist[MAX_VERTICES];
    int prev[MAX_VERTICES];
    int Q[MAX_VERTICES];
    int i,count,v;
    // Initialize distances and predecessors
    for (i = 0; i < V; i++) {
	dist[i] = INT_MAX;
	prev[i] = -1;
	Q[i] = 1;  // All vertices are initially in Q
    }

    dist[source] = 0;  // Distance to source is 0

    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, Q, V);
        Q[u] = 0;  // Remove u from Q
        for (v = 0; v < V; v++) {
            if (graph[u][v] && Q[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
            dist[v] = dist[u] + graph[u][v];
            prev[v] = u;
            }
        }
    }
    // Print shortest distances
    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < V; i++) {
	printf("%d\t\t%d\n", i, dist[i]);
    }
}

void main() {
    int V, source;
    int graph[MAX_VERTICES][MAX_VERTICES];
    int i,j;
    clrscr();
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(graph, V, source);
    getch();
}