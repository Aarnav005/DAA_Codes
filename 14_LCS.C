#include <stdio.h>
#include <string.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to compute the Longest Common Subsequence (LCS) of strings x and y
int LCS_computation(char *x, char *y) {
    int m = strlen(x);
    int n = strlen(y);

    // Initialize LCS matrix
    int LCS[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    // LCS value is stored in LCS[m][n]
    return LCS[m][n];
}

int main() {
    char x[] = "ABCBDAB";
    char y[] = "BDCAB";
    
    int lcs_length = LCS_computation(x, y);
    printf("Length of Longest Common Subsequence: %d\n", lcs_length);

    return 0;
}
