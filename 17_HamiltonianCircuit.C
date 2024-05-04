#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int n; // Number of vertices
int path[MAX_VERTICES]; // Current path
bool visited[MAX_VERTICES]; // Array to track visited vertices
int adjacency[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix

// Function to check if vertex v can be added to the path
bool isPromising(int v, int pos) {
    if (!visited[v] && adjacency[path[pos - 1]][v]) {
        // Check if vertex v is adjacent to the previous vertex in the path
        return true;
    }
    return false;
}

// Function to print the Hamiltonian circuit
void printHamiltonianCircuit() {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); // Return to starting vertex to complete the circuit
}

// Function to find the Hamiltonian Circuit
bool hamiltonianCircuit(int pos) {
    if (pos == n) {
        // All vertices visited, check if the last vertex is adjacent to the starting vertex
        if (adjacency[path[pos - 1]][path[0]]) {
            printHamiltonianCircuit();
            return true;
        }
        return false;
    }

    for (int v = 1; v < n; v++) {
        if (isPromising(v, pos)) {
            path[pos] = v; // Add vertex v to the path
            visited[v] = true; // Mark vertex v as visited
            if (hamiltonianCircuit(pos + 1)) {
                return true;
            }
            // Backtrack
            visited[v] = false;
        }
    }
    return false;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjacency[i][j]);
        }
    }

    // Initialize path and visited arrays
    for (int i = 0; i < n; i++) {
        path[i] = -1;
        visited[i] = false;
    }

    // Start with the first vertex as the starting point
    path[0] = 0;
    visited[0] = true;

    if (!hamiltonianCircuit(1)) {
        printf("No Hamiltonian Circuit found.\n");
    }

    return 0;
}
