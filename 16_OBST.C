#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100

// Function to calculate optimal BST cost
void optimalBST(float p[], int n) {
    // Cost table for storing optimal BST costs
    float C[MAX_NODES][MAX_NODES];

    // Initialize cost table and sum table
    float sum[MAX_NODES + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        C[i][i] = p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    // Fill the cost table using dynamic programming
    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            C[i][j] = INT_MAX; // Initialize cost to infinity
            // Calculate optimal cost for subtree rooted at k
            for (int k = i; k <= j; k++) {
                float cost = C[i][k - 1] + C[k + 1][j] + sum[j] - sum[i - 1];
                if (cost < C[i][j]) {
                    C[i][j] = cost;
                }
            }
        }
    }

    // Print the optimal BST cost
    printf("Optimal BST cost: %.2f\n", C[1][n]);
}

int main() {
    int n;
    float p[MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the probabilities for each node:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%f", &p[i]);
    }

    // Call function to calculate optimal BST cost
    optimalBST(p, n);

    return 0;
}
