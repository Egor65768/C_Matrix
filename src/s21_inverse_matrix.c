#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (A == NULL || result == NULL) {
    res = invalid_matrix;
  } else if (A->columns != A->rows) {
    res = calculation_error;
  }
  if (res == OK) {
    res = matrix_nan_or_inf(*A, *A);
  }
  if (res == OK) {
    double determinant = 0.0;
    s21_determinant(A, &determinant);
    if (determinant != 0) {
      matrix_t compl_mat, trans;
      s21_calc_complements(A, &compl_mat);
      s21_transpose(&compl_mat, &trans);
      determinant = 1.0 / determinant;
      s21_mult_number(&trans, determinant, result);
      s21_remove_matrix(&compl_mat);
      s21_remove_matrix(&trans);
    } else {
      res = calculation_error;
    }
  }
  return res;
}