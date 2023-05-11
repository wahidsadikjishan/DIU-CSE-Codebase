/*
Program to check if a matrix is orthogonal or not

Author: Wahid Sadik
Created: 31-10-2022
*/

#include <stdio.h>
#include <stdlib.h>

void transpose_matrix(int matrix_size, int matrix[matrix_size][matrix_size]);

int main() {
  int matrix_size;
  // get size of matrix from user
  printf("Enter the size of the square matrix: ");
  scanf("%d", &matrix_size);
  int matrix[matrix_size][matrix_size];
  // get values of matrix from user
  printf("Enter the values of the matrix:\n");
  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  // transpose matrix
  transpose_matrix(matrix_size, matrix);
  // check if matrix is orthogonal
  int product_matrix[matrix_size][matrix_size];
  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      int dot_product = 0;
      for (int k = 0; k < matrix_size; k++) {
        dot_product += matrix[i][k] * matrix[j][k];
      }
      product_matrix[i][j] = dot_product;
    }
  }
  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      if (i == j && product_matrix[i][j] != 1) {
        printf("The matrix is not orthogonal.\n");
        return 0;
      } else if (i != j && product_matrix[i][j] != 0) {
        printf("The matrix is not orthogonal.\n");
        return 0;
      }
    }
  }
  printf("The matrix is orthogonal.\n");
  return 0;
}

void transpose_matrix(int matrix_size, int matrix[matrix_size][matrix_size]) {
  for (int i = 0; i < matrix_size; i++) {
    for (int j = i + 1; j < matrix_size; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
}
