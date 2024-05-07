#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int arr1[] = {1,0,0,1};
int arr2[] = {1,2,3,4};
int ans[4];

void stressons(int X[], int Y[])
{
	int A, B, C, D, E, F, G, H, P1, P2, P3, P4, P5, P6, P7;
	A = X[0];
	B = X[1];
	C = X[2];
	D = X[3];
	E = Y[0];
	F = Y[1];
	G = Y[2];
	H = Y[3];
	P1 = A*(F-H);
	P2 = H*(A+B);
	P3 = E*(C+D);
	P4 = D*(G-E);
	P5 = (A+D)*(E+H);
	P6 = (B-D)*(G+H);
	P7 = (A-C)*(E+F);
	ans[0] = P4+P5+P6-P2;
	ans[1] = P1+P2;
	ans[2] = P3+P4;
	ans[3] = P1-P3+P5-P7;
}
void multiplication(int A[],int B[]){
	int i,j,k;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			ans[i * 2 + j] = 0;
			for(k=0;k<2;k++){
				ans[i * 2 + j] += A[i*2+k]*B[k*2+j];
			}
		}
	}
}

void printmat(char wat,int mat[]){
	int i;
	printf("The array %c is: \n",wat);
	for(i=0;i<4;i++){
		printf("%d ",mat[i]);
		if(i==1)
			printf("\n");
	}
	printf("\n");
	printf("\n");
}

int main(){
	clrscr();
	printmat('A',arr1);
	printmat('B',arr2);
	stressons(arr1,arr2);
	printf("The answer is: ");
	printmat('C',ans);
	getch();
	return 0;
}
 
