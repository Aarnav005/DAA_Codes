#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_V 10  

int V;                                            
int graph[MAX_V][MAX_V];         

void printSolution(int path[]) {
    int i ;
    printf("Hamiltonian Cycle: \n");
    for ( i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);                        
}

int isSafe(int v, int path[], int pos) {
    int i;
    if (graph[path[pos - 1]][v] == 0)
        return 0;                         

    for ( i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;                       

    return 1;
}

int hamCycleUtil(int path[], int pos) {
    int count,v;
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            printSolution(path);                               
            return 1;                                                   
        }
        return 0;
    }

     count = 0;                                      
    for ( v = 1; v < V; v++) {
        if (isSafe(v, path, pos)) {
            path[pos] = v;
            count += hamCycleUtil(path, pos + 1);                   

            path[pos] = -1;            
        }
    }
    return count;
}

void hamCycle() {
    int i;
    int cycleCount;
    int path[MAX_V];
    for (i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; 
    cycleCount = hamCycleUtil(path, 1);

    if (cycleCount == 0)
        printf("No Hamiltonian Cycle exists\n");
    else
        printf("Total Hamiltonian Cycles found: %d\n", cycleCount);
}

int main() {
    int i , j;
    clrscr();
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for ( i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    hamCycle();
    getch();
    return 0;
}