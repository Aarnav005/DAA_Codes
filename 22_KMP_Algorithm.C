#include <stdio.h>
#include <string.h>

void KMP_prefix(char* P, int m, int* pi) {
    int i = 1, j = 0;
    pi[0] = -1;
    while (i < m) {
        while (j >= 0 && P[i] != P[j]) {
            j = pi[j];
        }
        i++;
        j++;
        pi[i] = j;
    }
}
void KMP_match(char* P, char* T, int m, int n, int* pi) {
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) {
            j = pi[j];
        }
        i++;
        j++;

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = pi[j];
        }
    }

    if (j == m) {
        printf("Pattern found at index %d\n", i - j);
    } else {
        printf("Pattern not found in text/Pattern Ended\n");
    }
}

void main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "AB";
    int m = strlen(pattern);
    int n = strlen(text);
    int *pi = (int *)malloc((m + 1) * sizeof(int));
    clrscr();
    KMP_prefix(pattern, m, pi);
    KMP_match(pattern, text, m, n, pi);
    free(pi);
    getch();
}
