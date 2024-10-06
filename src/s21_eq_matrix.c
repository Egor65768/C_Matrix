#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns || A == NULL ||
      B == NULL) {
    res = FAILURE;
  }
  for (int i = 0; i < A->rows && res != FAILURE; i++) {
    for (int j = 0; j < A->columns && res != FAILURE; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
        res = FAILURE;
      }
    }
  }
  return res;
}
