#include <stdio.h>
#include <stdlib.h>

// All denominations of Indian Currency
int denomination[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int n = sizeof(denomination) / sizeof(denomination[0]);

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

void findMin(int V) {
    qsort(denomination, n, sizeof(int), compare); // Sort denominations

    // Initialize result
    int ans[100];
    int ans_index = 0;

    // Traverse through all denominations
    for (int i = 0; i < n; i++) {
        // Find denominations
        while (V >= denomination[i]) {
            V -= denomination[i];
            ans[ans_index++] = denomination[i];
        }
    }

    // Print result
    for (int i = 0; i < ans_index; i++) {
        printf("%d ", ans[i]);
    }
}

// Driver code
int main() {
    int n = 93;
    printf("Following is minimal number of change for %d: ", n);
    
    // Function call
    findMin(n);
    return 0;
}
