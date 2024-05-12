#include <stdio.h>
#include <limits.h>
#include <conio.h>
#define vertices 5

int minimum_key(int k[], int mst[]) {
    int minimum = INT_MAX, min, i;
    for (i = 0; i < vertices; i++) {
        if (mst[i] == 0 && k[i] < minimum) {
            minimum = k[i];
            min = i;
        }
    }
    return min;
}
void prim(int g[vertices][vertices]) {
    int parent[vertices];  
    int k[vertices];       
    int mst[vertices];     
    int i, count, edge, v; 
    int sum = 0;           
    
    for (i = 0; i < vertices; i++) {
        k[i] = INT_MAX;
        mst[i] = 0;
    }
    k[0] = 0;        
    parent[0] = -1;  
  
    for (count = 0; count < vertices - 1; count++) {
       
        edge = minimum_key(k, mst);
        mst[edge] = 1;    
      
        for (v = 0; v < vertices; v++) {
            if (g[edge][v] && mst[v] == 0 && g[edge][v] < k[v]) {
                parent[v] = edge;
                k[v] = g[edge][v];
            }
        }
    }
    
    printf("\n Edge \t Weight\n");
    for (i = 1; i < vertices; i++) {
        printf(" %d <-> %d %d \n", parent[i], i, g[i][parent[i]]);
        sum += g[i][parent[i]];
    }
    
    printf("Total Cost = %d", sum);
}
void main() {
    int g[vertices][vertices];
    int i, j;
    clrscr();  
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    prim(g);
    getch();  
}