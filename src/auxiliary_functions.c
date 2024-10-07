#include "s21_matrix.h"

int matrix_nan_or_inf(matrix_t A, matrix_t B) {
  int res = OK;
  if ((A.columns != B.columns || A.rows != B.rows)) {
    res = calculation_error;
  }
  for (int i = 0; i < A.rows && res == OK; i++) {
    for (int j = 0; j < A.columns && res == OK; j++) {
      if (isnan(A.matrix[i][j]) != 0 || isinf(A.matrix[i][j]) != 0 ||
          isnan(B.matrix[i][j]) != 0 || isinf(B.matrix[i][j]) != 0) {
        res = calculation_error;
      }
    }
  }

  return res;
}

int help_add_or_sub(matrix_t *A, matrix_t *B, matrix_t *result, int operation) {
  int res = OK;
  if (A == NULL || B == NULL || result == NULL) {
    res = invalid_matrix;
  } else {
    res = matrix_nan_or_inf(*A, *B);
  }
  if (res == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + (B->matrix[i][j]) * operation;
      }
    }
  }
  return res;
}

void help_matrix_formation(matrix_t A, matrix_t *buf, int delite_row,
                           int delite_columns) {
  int i1 = 0, j1 = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      if (i != delite_row && j != delite_columns) {
        buf->matrix[j1][i1] = A.matrix[i][j];
        i1++;
        if (i1 == buf->rows) {
          j1++;
          i1 = 0;
        }
      }
    }
  }
}

double calculating_minor_two_by_two(matrix_t A) {
  double res = 0;
  res = A.matrix[0][0] * A.matrix[1][1] - A.matrix[1][0] * A.matrix[0][1];
  return res;
}

void help_calc_complements(matrix_t *result) {
  int sign = -1;
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      if ((i + j + 2) % 2 == 0) {
        sign = 1;
      } else {
        sign = -1;
      }
      result->matrix[i][j] = result->matrix[i][j] * sign;
    }
  }
}