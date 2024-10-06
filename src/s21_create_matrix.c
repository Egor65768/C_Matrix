#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;
  if (rows <= 0 || columns <= 0 || result == NULL) {
    result->columns = result->rows = 0;
    res = invalid_matrix;
  } else {
    result->matrix = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = malloc(columns * sizeof(double));
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0;
      }
    }
    result->columns = columns;
    result->rows = rows;
  }
  return res;
}