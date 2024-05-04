#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adjacency[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix of the graph
int colors[MAX_VERTICES]; // Array to store colors of vertices
int numVertices, numColors; // Number of vertices and colors

// Function to check if coloring of vertex 'v' is valid
bool promising_colouring(int v) {
    for (int i = 0; i < v; i++) {
        if (adjacency[v][i] && colors[i] == colors[v]) {
            return false; // If adjacent vertices have same color, return false
        }
    }
    return true;
}

// Recursive function to color vertices of the graph
void colouring(int v) {
    if (v == numVertices) { // If all vertices are colored
        // Print the coloring
        printf("Vertex Colors: ");
        for (int i = 0; i < numVertices; i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
        return;
    }

    // Try assigning colors to vertex 'v'
    for (int c = 1; c <= numColors; c++) {
        colors[v] = c; // Assign color 'c' to vertex 'v'
        if (promising_colouring(v)) { // If coloring is promising
            colouring(v + 1); // Recur for next vertex
        }
        colors[v] = 0; // Backtrack: reset color of vertex 'v'
    }
}

int main() {
    // Input the number of vertices and colors
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of colors: ");
    scanf("%d", &numColors);

    // Input the adjacency matrix of the graph
    printf("Enter the adjacency matrix (%d x %d):\n", numVertices, numVertices);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacency[i][j]);
        }
    }

    // Initialize colors of all vertices to 0 (unassigned)
    for (int i = 0; i < numVertices; i++) {
        colors[i] = 0;
    }

    // Start coloring from vertex 0
    colouring(0);

    return 0;
}
