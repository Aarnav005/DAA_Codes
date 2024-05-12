#include<stdio.h>

void frac(int p[] , int w[] , int cap , int n);

void main() {
    int n;
    int p[] = {24, 15, 25};
    int w[] = {15, 10, 18};
    int cap = 20;
    clrscr();
    n = sizeof(p) / sizeof(p[0]);
    frac(p , w, cap , n);
    getch();
}

void frac(int p[], int w[], int cap, int n) {
    float *pw;
    float tempratio;
    int i, j, temprofit, tempweight;
    float totalprofit = 0;
    pw = (float *)malloc(n * sizeof(float)); // Allocate memory dynamically for pw array
    for(i = 0; i < n; i++) {
        pw[i] = (float)p[i] / w[i];
    }
    for(i = 0; i <= n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(pw[j] < pw[j + 1]) {
                tempratio = pw[j];
                pw[j] = pw[j + 1];
                pw[j + 1] = tempratio;

                temprofit = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temprofit;

                tempweight = w[j];
                w[j] = w[j + 1];
                w[j + 1] = tempweight;
            }
        }
    }
    for(i = 0; i < n; i++) {
        if(cap > w[i]) {
            cap = cap - w[i];
            totalprofit = totalprofit + p[i];
        } else {
            totalprofit = totalprofit + (cap * pw[i]);
            break;
        }
    }
    printf("The total profit is %.2f", totalprofit);
}