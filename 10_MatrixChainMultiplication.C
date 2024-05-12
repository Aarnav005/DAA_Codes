#include<stdio.h>
#include<stdlib.h>

int memo[10][10][2];

int MatrixChainOrder(int p[], int i, int j){
    int k;
    int min = 9999;
    int count;
    int k1;
    if (i == j)
	return 0;
    if(memo[i][j][0] != 0){
	return memo[i][j][1];
    }
    for (k = i; k < j; k++)
    {
	count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

	if (count < min){
	    min = count;
	    k1 = k;
	}
    }
    memo[i][j][0] = k1;
    memo[i][j][1] = min;
    return min;
}

void main(){
    int n = 4,k,i,j;
    int cost[] = {5,4,2,3,4};
    int M[4][4] = {0};
    clrscr();
    for(i=0;i<10;i++){
	for(j=0;j<n;j++){
	    memo[i][j][0] = 0;
	    memo[i][j][1] = 0;
	}
    }
    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	    if(j>=i){
		printf("%d ", MatrixChainOrder(cost, i+1, j+1));
	    }else{
		printf("0 ");
	    }
	}
	printf("\n");
    }
    printf("\n");printf("\n");
    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	    if(j>=i){
		printf("%d ", memo[i+1][j+1][0]);
	    }else{
		printf("0 ");
	    }
	}
	printf("\n");
    }
    getch();
}