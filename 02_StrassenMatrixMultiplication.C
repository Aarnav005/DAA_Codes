#include <stdio.h>
#include <stdlib.h>
#define ROW_1 4
#define COL_1 4
#define ROW_2 4
#define COL_2 4
void print(char *display, int **matrix, int start_row, int start_column, int end_row, int end_column)
{
 printf("\n%s =>\n", display);
 for (int i = start_row; i <= end_row; i++) {
 for (int j = start_column; j <= end_column; j++) {
 printf("%10d", matrix[i][j]);
 }
 printf("\n");
 }
 printf("\n");
}
void add_matrix(int **matrix_A, int **matrix_B, int **matrix_C, int split_index) {
 for (int i = 0; i < split_index; i++) {
 for (int j = 0; j < split_index; j++) {
 matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
 }
 }
}
int **multiply_matrix(int **matrix_A, int **matrix_B, int n) {
 int **result_matrix = (int **)malloc(n * sizeof(int *));
 for (int i = 0; i < n; i++) {
 result_matrix[i] = (int *)malloc(n * sizeof(int));
 }
 if (n == 1) {
 result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
 } else {
 int split_index = n / 2;
 int **result_matrix_00 = multiply_matrix(matrix_A, matrix_B, split_index);
 int **result_matrix_01 = multiply_matrix(matrix_A, matrix_B + split_index, split_index);
 int **result_matrix_10 = multiply_matrix(matrix_A + split_index, matrix_B, split_index);
 int **result_matrix_11 = multiply_matrix(matrix_A + split_index, matrix_B + split_index,
split_index);
 int **temp_matrix = (int **)malloc(split_index * sizeof(int *));
 for (int i = 0; i < split_index; i++) {
 temp_matrix[i] = (int *)malloc(split_index * sizeof(int));
 }
 add_matrix(result_matrix_00, result_matrix_01, temp_matrix, split_index);
 add_matrix(result_matrix_10, result_matrix_11, result_matrix_00, split_index);
 for (int i = 0; i < split_index; i++) {
 for (int j = 0; j < split_index; j++) {
 result_matrix[i][j] = result_matrix_00[i][j];
 result_matrix[i][j + split_index] = result_matrix_01[i][j];
 result_matrix[i + split_index][j] = result_matrix_10[i][j];
 result_matrix[i + split_index][j + split_index] = result_matrix_11[i][j];
 }
 }
 for (int i = 0; i < split_index; i++) {
 free(temp_matrix[i]);
 }
 free(temp_matrix);
 for (int i = 0; i < split_index; i++) {
 free(result_matrix_00[i]);
 free(result_matrix_01[i]);
 free(result_matrix_10[i]);
 free(result_matrix_11[i]);
 }
 free(result_matrix_00);
 free(result_matrix_01);
 free(result_matrix_10);
 free(result_matrix_11);
 }
 return result_matrix;
}
int main() {
 int **matrix_A = (int **)malloc(ROW_1 * sizeof(int *));
 for (int i = 0; i < ROW_1; i++) {
 matrix_A[i] = (int *)malloc(COL_1 * sizeof(int));
 }
 matrix_A[0][0] = 1; matrix_A[0][1] = 1; matrix_A[0][2] = 1; matrix_A[0][3] = 1;
 matrix_A[1][0] = 2; matrix_A[1][1] = 2; matrix_A[1][2] = 2; matrix_A[1][3] = 2;
 matrix_A[2][0] = 3; matrix_A[2][1] = 3; matrix_A[2][2] = 3; matrix_A[2][3] = 3;
 matrix_A[3][0] = 2; matrix_A[3][1] = 2; matrix_A[3][2] = 2; matrix_A[3][3] = 2;
 print("Array A", matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);
 int **matrix_B = (int **)malloc(ROW_2 * sizeof(int *));
 for (int i = 0; i < ROW_2; i++) {
 matrix_B[i] = (int *)malloc(COL_2 * sizeof(int));
 }
 matrix_B[0][0] = 1; matrix_B[0][1] = 1; matrix_B[0][2] = 1; matrix_B[0][3] = 1;
 matrix_B[1][0] = 2; matrix_B[1][1] = 2; matrix_B[1][2] = 2; matrix_B[1][3] = 2;
 matrix_B[2][0] = 3; matrix_B[2][1] = 3; matrix_B[2][2] = 3; matrix_B[2][3] = 3;
 matrix_B[3][0] = 2; matrix_B[3][1] = 2; matrix_B[3][2] = 2; matrix_B[3][3] = 2;
 print("Array B", matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);
 int **result_matrix = multiply_matrix(matrix_A, matrix_B, ROW_1);
 print("Result Array", result_matrix, 0, 0, ROW_1 - 1, COL_2 - 1);
 for (int i = 0; i < ROW_1; i++) {
 free(matrix_A[i]);
 }
 free(matrix_A);
 for (int i = 0; i < ROW_2; i++) {
 free(matrix_B[i]);
 }
 free(matrix_B);
 for (int i = 0; i < ROW_1; i++) {
 free(result_matrix[i]);
 }
 free(result_matrix);
 return 0;
}
