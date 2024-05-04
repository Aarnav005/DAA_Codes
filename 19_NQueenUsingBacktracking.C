#include <stdio.h>
#include <stdbool.h>

#define MAX_N 20

// Function prototypes
bool solveNQueens(int n);
bool Nqueen(int x[], int k, int n);
bool isSafe(int x[], int k, int i, int n);
void printSolution(int x[], int n);

// Helper function to print the solution
void printSolution(int x[], int n) {
    printf("Solution:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

// Function to check if a queen can be placed on the board
bool isSafe(int x[], int k, int i, int n) {
    // Check for the same column
    for (int j = 1; j < k; j++) {
        if (x[j] == i)
            return false;
    }

    // Check for the left diagonal
    for (int j = 1; j < k; j++) {
        if (x[j] == i - k + j)
            return false;
    }

    // Check for the right diagonal
    for (int j = 1; j < k; j++) {
        if (x[j] == i + k - j)
            return false;
    }

    return true;
}

// Recursive backtracking function to solve the N-Queens problem
bool Nqueen(int x[], int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (isSafe(x, k, i, n)) {
            x[k] = i;  // Place the queen in the current position
            if (k == n) {
                printSolution(x, n);  // Print the solution
            } else {
                Nqueen(x, k + 1, n);  // Recursively call for the next row
            }
        }
    }
    return false;  // No solution exists if the function reaches here
}

// Driver function to solve the N-Queens problem
bool solveNQueens(int n) {
    int x[MAX_N + 1];  // Array to store column positions of queens
    return Nqueen(x, 1, n);
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (solveNQueens(n)) {
        printf("Solutions found.\n");
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}