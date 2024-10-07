#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  matrix_t buf;
  double calc_complements = 0.0;
  int res = OK;
  *result = 0;
  int sign = 1;
  if (A == NULL || result == NULL) {
    res = invalid_matrix;
  } else if (A->columns != A->rows) {
    res = calculation_error;
  }
  if (res == OK) {
    res = matrix_nan_or_inf(*A, *A);
  }
  if (res == OK) {
    if (A->rows == 3) {
      for (int i = 0; i < A->rows; i++) {
        s21_create_matrix(A->rows - 1, A->columns - 1, &buf);
        if ((i + 2) % 2 == 0) {
          sign = 1;
        } else {
          sign = -1;
        }
        help_matrix_formation(*A, &buf, 0, i);
        *result = *result +
                  sign * A->matrix[0][i] * calculating_minor_two_by_two(buf);
        s21_remove_matrix(&buf);
      }
    } else if (A->rows == 2) {
      *result = calculating_minor_two_by_two(*A);
    } else if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows > 3) {
      for (int i = 0; i < A->rows; i++) {
        s21_create_matrix(A->rows - 1, A->columns - 1, &buf);
        help_matrix_formation(*A, &buf, 0, i);
        s21_determinant(&buf, &calc_complements);
        if ((i + 2) % 2 == 0) {
          sign = 1;
        } else {
          sign = -1;
        }
        *result = *result + sign * A->matrix[0][i] * calc_complements;
        s21_remove_matrix(&buf);
      }
    }
  }
  return res;
}
