#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

void printOptimalParenthesis(int s[][MAX_SIZE], int i, int j); // Forward declaration

void matrixChainOrder(int p[], int n) {
    int m[MAX_SIZE][MAX_SIZE]; // m[i][j] stores minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j]
    int s[MAX_SIZE][MAX_SIZE]; // s[i][j] stores the index of the matrix after which the product is split

    // Initialize m[i][i] to 0 as it costs nothing to multiply one matrix
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    // Calculate m[i][j] and s[i][j] for all possible chain lengths l
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print the minimum number of scalar multiplications
    printf("Minimum number of scalar multiplications: %d\n", m[1][n]);

    // Print the optimal parenthesization
    printf("Optimal parenthesization: ");
    printOptimalParenthesis(s, 1, n);
    printf("\n");
}

void printOptimalParenthesis(int s[][MAX_SIZE], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[MAX_SIZE]; // Array to store dimensions of matrices
    printf("Enter the dimensions of matrices (including dimensions of result matrix): ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    matrixChainOrder(p, n);

    return 0;
}
