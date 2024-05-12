#include <stdio.h>
#include <conio.h>  
#include <stdlib.h> 

#define MAX_N 20 

int board[MAX_N][MAX_N]; 
int N; 

int isSafe(int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;
    return 1;
}

void printSolution() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int solveNQUtil(int col) {
    int res = 0, i;
    if (col >= N) {
        printSolution();
        printf("\n");
        return 1;  // Return 1 to count this solution
    }
   
    for (i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;
            res += solveNQUtil(col + 1);               
            board[i][col] = 0;
        }
    }
    return res;
}

void solveNQ() {
    int totalSolutions = solveNQUtil(0);                  
    if (totalSolutions == 0) {
        printf("No solution exists\n");
    } else {
        printf("Total number of solutions: %d\n", totalSolutions);
    }
}

int main() {
    clrscr();
    printf("Enter the number of queens (Max %d): ", MAX_N);
    scanf("%d", &N);
    if (N > MAX_N) {
        printf("Number of queens is too large!\n");
        getch();
        return 0;
    }
    solveNQ();
    getch();
    return 0;
}