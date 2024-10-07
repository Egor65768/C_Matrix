#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int operation = -1;
  return help_add_or_sub(A, B, result, operation);
}