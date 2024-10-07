#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  matrix_t buf;
  double calc_complements = 0.0;
  if (A == NULL || result == NULL) {
    res = invalid_matrix;
  } else if (A->columns != A->rows) {
    res = calculation_error;
  }
  if (res == OK) {
    res = matrix_nan_or_inf(*A, *A);
  }
  if (res == OK && A->rows > 1) {
    s21_create_matrix(A->rows, A->columns, result);
    s21_create_matrix(A->rows - 1, A->columns - 1, &buf);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        help_matrix_formation(*A, &buf, i, j);
        s21_determinant(&buf, &calc_complements);
        result->matrix[i][j] = calc_complements;
      }
    }
    help_calc_complements(result);
    s21_remove_matrix(&buf);
  } else if (res == OK && A->rows == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1.0;
  }
  return res;
}
