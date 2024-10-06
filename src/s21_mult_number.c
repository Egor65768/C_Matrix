#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;
  if (A == NULL || result == NULL) {
    res = invalid_matrix;
  } else if (isnan(number) != 0 || isinf(number) != 0) {
    res = calculation_error;
  } else {
    res = matrix_nan_or_inf(*A, *A);
    if (res == OK) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = number * A->matrix[i][j];
        }
      }
    }
  }
  return res;
}