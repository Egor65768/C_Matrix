#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (A == NULL || B == NULL || result == NULL) {
    res = invalid_matrix;
  } else if (A->columns != B->rows) {
    res = calculation_error;
  } else {
    res = matrix_nan_or_inf(*A, *A);
    if (res == OK) {
      res = matrix_nan_or_inf(*B, *B);
    }
    if (res == OK) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          result->matrix[i][j] = help_mult_matrix(*A, *B, i, j);
        }
      }
    }
  }
  return res;
}

double help_mult_matrix(matrix_t A, matrix_t B, int i, int j) {
  double res = 0.0;
  for (int k = 0; k < A.columns; k++) {
    res = res + A.matrix[i][k] * B.matrix[k][j];
  }
  return res;
}