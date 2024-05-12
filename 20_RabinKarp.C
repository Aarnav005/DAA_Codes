#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define d 256
#define q 13
int sp = 0;
void rabin_karp(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int p=0, t=0, h=1, j;
    int i;

    for(i=1 ; i<=m-1 ; i++)
        h = (h * d) % q;

    for(i=0 ; i<m ; i++) {
        t = (d * t + text[i]) % q;
        p = (d * p + pattern[i]) % q;
    }

    for(i=0 ; i<=n-m ; i++) {
        if(p == t) {
            for(j=0 ; j<m ; j++) {
                if(text[i+j] != pattern[j]) 
                    break;
            }
            if(j == m)
                printf("\nPattern found at index %d", i);
            else 
                sp++;
        }
        if(i < n-m) {
            t = (d * (t - text[i] * h) + text[i+m]) % q;
            if(t < 0)
                t = (t + q) % q;
        }
    }
    printf("\nSpurious Hits: %d", sp);
}

void main() {
    char *text = (char *) malloc (MAX * sizeof(char));
    char *pattern = (char *) malloc (MAX * sizeof(char));
    clrscr();
    printf("Enter the text: ");
    scanf("%99s", text);
    printf("Enter the pattern: ");
    scanf("%99s", pattern);
    rabin_karp(text, pattern);
    getch();
}