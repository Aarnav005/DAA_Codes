#include <stdio.h>

void greedy(int coin[], int sum, int n);

void main() {
    int coin[] = {5, 4, 2};
    int sum = 12;
    int n = sizeof(coin) / sizeof(coin[0]);
    clrscr();
    greedy(coin, sum, n);
    getch();
}

void greedy(int coin[], int sum, int n) {
    int i, j, temp;
    // Sort the coins in descending order
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (coin[j] < coin[j + 1]) {
            temp = coin[j];
            coin[j] = coin[j + 1];
            coin[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        while (coin[i] <= sum) {
            printf("%d ", coin[i]);
            sum = sum - coin[i];
        }
    }
}