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

/*
Alternate Code

#include <stdio.h>
#include <stdlib.h>

int main() {
    int length, total_weight, ctr = 0;
    float sum = 0;
    printf("Enter the length: ");
    scanf("%d", &length);

    printf("\nEnter the total weight: ");
    scanf("%d", &total_weight);

    float *weight = (float*) malloc (length * sizeof(float));
    float *profit = (float*) malloc (length * sizeof(float));
    int *index = (int*) malloc (length * sizeof(int));
    float *pw = (float*) malloc (length * sizeof(float));
    float *x = (float*) malloc (length * sizeof(float));

    printf("\nEnter the Profits:\n");
    for(int i = 0 ; i < length ; i++) {
        scanf("%f", &profit[i]);
        index[i] = i;
        x[i] = 0.0;
    }

    printf("\nEnter the Weights:\n");
    for(int i = 0 ; i < length ; i++) {
        scanf("%f", &weight[i]);
        pw[i] = profit[i] / weight[i];
    }

    for(int i = 0 ; i < length - 1 ; i++) {
        for(int j = 0 ; j < length - i - 1 ; j++) {
            if(pw[j] < pw[j+1]) {
                float temp = pw[j];
                pw[j] = pw[j+1];
                pw[j+1] = temp;
                
                temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;

                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;

                int temp1 = index[j];
                index[j] = index[j+1];
                index[j+1] = temp1;
            }
        }
    }

    int temp = total_weight;

    int i = 0;
    while(temp > 0) {
        if(weight[i] <= temp) {
            x[i] = 1;
            temp -= weight[i];
        }
        else {
            x[i] = temp / weight[i];
            temp = 0;
        }
        i++;
    }
    
    for(int i = 0 ; i < length ; i++) 
        sum += (x[i] * profit[i]);

    printf("\nMaximum Profit: %.4f", sum);

    free(weight);
    free(profit);
    free(index);
    free(pw);
    free(x);

    return 0;
}


*/