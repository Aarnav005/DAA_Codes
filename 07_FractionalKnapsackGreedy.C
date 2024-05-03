#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    double cost;
} Item;

int compare(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    return (int)((itemB->cost - itemA->cost) * 1000000);  // Scale up to avoid precision loss
}

double fractionalKnapsack(int W, int V[], int W_arr[], int n) {
    Item* items = (Item*)malloc(n * sizeof(Item));
    double totalValue = 0.0;

    // Calculate cost and store in items array
    for (int i = 0; i < n; i++) {
        items[i].value = V[i];
        items[i].weight = W_arr[i];
        items[i].cost = (double)V[i] / W_arr[i];
    }

    // Sort items based on cost in descending order
    qsort(items, n, sizeof(Item), compare);

    // Iterate over sorted items and add to knapsack
    int i = 0;
    while (i < n && W > 0) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += (double)W * items[i].cost;
            W = 0;
        }
        i++;
    }

    free(items);
    return totalValue;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int* V = (int*)malloc(n * sizeof(int));
    int* W_arr = (int*)malloc(n * sizeof(int));

    printf("Enter the values of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &V[i]);
    }

    printf("Enter the weights of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &W_arr[i]);
    }

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    double maxValue = fractionalKnapsack(W, V, W_arr, n);
    printf("Maximum value that can be obtained: %.2lf\n", maxValue);

    free(V);
    free(W_arr);
    return 0;
}