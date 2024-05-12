#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int coin_change_dynamic(int *coins_value, int total_value, int coins) {
  int *result_matrix = (int*) malloc ((total_value + 1) * sizeof(int));
  int *solution_matrix = (int*) malloc ((total_value + 1) * sizeof(int));
  int i, j;
  int value;
  result_matrix[0] = 0;
  solution_matrix[0] = 0;
  for(j = 1; j <= total_value; j++) {
    int minimum = 10000;
    int coin = 0;
    for(i = 0; i < coins; i++) {
      if(j >= coins_value[i]) {
        if((1 + result_matrix[j - coins_value[i]]) < minimum) {
          minimum = 1 + result_matrix[j - coins_value[i]];
          coin = i;
        }
      }
    }
    result_matrix[j] = minimum;
    solution_matrix[j] = coin;
  }
  printf("Selected coins:\n");
  value = total_value;
  while(value > 0) {
    printf("%d\n", coins_value[solution_matrix[value]]);
    value -= coins_value[solution_matrix[value]];
  }
  free(solution_matrix);
  return result_matrix[total_value];
}

void main() {
    int coins, total_value;
    int min_coins,i;
    int *coins_value = (int*) malloc (coins * sizeof(int));
    clrscr();
    printf("Enter the number of coins: ");
    scanf("%d", &coins);
    printf("\nEnter the total value: ");
    scanf("%d", &total_value);
    printf("\nEnter the value of coins:\n");
    for(i = 0 ; i < coins ; i++)
        scanf("%d", &coins_value[i]);
    min_coins = coin_change_dynamic(coins_value, total_value, coins);
    printf("Minimum number of coins required: %d\n", min_coins);
    free(coins_value);
    getch();
}