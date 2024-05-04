#include <stdio.h>
#include <limits.h>
#include <math.h> // Include math.h for fmin function

#define MAX_COINS 100

// Function to find the number of ways to make the sum using the given coins
int coinChange(int coins[], int m, int V) {
    int table[m + 1][V + 1];

    // Initialize the table
    for (int i = 0; i <= m; i++) {
        table[i][0] = 0; // Base case: 0 coins needed for sum 0
    }

    for (int j = 1; j <= V; j++) {
        table[0][j] = INT_MAX; // Impossible state for uninitialized entries
    }

    // Compute the minimum number of coins required for each sum from 1 to V
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= V; j++) {
            if (coins[i - 1] > j) {
                table[i][j] = table[i - 1][j]; // Cannot use the current coin
            } else {
                table[i][j] = table[i - 1][j]; // Don't use the current coin
                if (table[i][j - coins[i - 1]] != INT_MAX) {
                    table[i][j] = fmin(table[i][j], 1 + table[i][j - coins[i - 1]]); // Use the current coin
                }
            }
        }
    }

    // Reconstruction of one of the optimal solutions
    int sol[MAX_COINS];
    int p = 0;
    int i = m, j = V;
    
    while (j > 0) {
        if (table[i][j] == table[i - 1][j]) {
            i = i - 1;
        } else {
            sol[p++] = coins[i - 1];
            j = j - coins[i - 1];
        }
    }

    // Print the solution (optional)
    printf("One of the optimal solutions: ");
    for (int k = 0; k < p; k++) {
        printf("%d ", sol[k]);
    }
    printf("\n");

    return table[m][V]; // Return the number of ways to make the sum V
}

int main() {
    int coins[] = {1, 2, 3};
    int m = sizeof(coins) / sizeof(coins[0]); // Number of different coin denominations
    int sum = 4;

    int ways = coinChange(coins, m, sum);
    printf("Number of ways to make the sum %d: %d\n", sum, ways);

    return 0;
}
