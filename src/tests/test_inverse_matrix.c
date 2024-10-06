#include "test.h"

START_TEST(inverse_matrix_1) {
  matrix_t A, result;
  double arr[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
  double res[] = {1.0, -1.0, 1.0, -38.0, 41.0, -34.0, 27.0, -29.0, 24.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      ck_assert(fabs(round(result.matrix[i][j] * 1000000) -
                     round(res[count] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

// свойство обратной матрицы произведение обратной на обычную дает единичную
START_TEST(inverse_matrix_2) {
  matrix_t A, result, B;
  double arr[] = {2.0, 5.0, 7.0, 6.0, 3.0, 4.0, 5.0, -2.0, -3.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_mult_matrix(&A, &result, &B), OK);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        ck_assert(fabs(round(B.matrix[i][j] * 1000000) - round(1.0 * 1000000)) <
                  1);
      } else {
        ck_assert(fabs(round(B.matrix[i][j] * 1000000) - round(0.0 * 1000000)) <
                  1);
      }
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t A, result;
  double arr[] = {2.0, 0.0, 1.0, 0.0, -3.0, -1.0, -2.0, 4.0, 0.0};
  double res[] = {2.0, 2.0, 1.5, 1.0, 1.0, 1.0, -3.0, -4.0, -3.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      ck_assert(fabs(round(result.matrix[i][j] * 1000000) -
                     round(res[count] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_4) {
  ck_assert_int_eq(s21_inverse_matrix(NULL, NULL), invalid_matrix);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t A;
  double arr[] = {2.0, 0.0, 1.0, 0.0, -3.0, -1.0, -2.0, 4.0, 0.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t A, result;
  double arr[] = {1.0, 1.0, 3.0, 1.0, 1.0, 3.0, 2.0, -1.0, 4.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), calculation_error);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_7) {
  matrix_t A;
  ck_assert_int_eq(s21_inverse_matrix(NULL, &A), invalid_matrix);
}
END_TEST

START_TEST(inverse_matrix_8) {
  matrix_t A, result;
  double arr[] = {NAN, 1.0, 3.0, 1.0, 1.0, 3.0, 2.0, -1.0, 4.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), calculation_error);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_9) {
  matrix_t A, result;
  double arr[] = {123.3, 1.0, 3.0, INFINITY, 1.0, 3.0, 2.0, -1.0, 4.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), calculation_error);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_10) {
  matrix_t A, result;
  double arr[] = {123.3, 1.0, 3.0, INFINITY, 1.0, 3.0, 2.0, -1.0, 4.0};
  int n = 2, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), calculation_error);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_11) {
  matrix_t A, result;
  double arr[] = {13.2, 13.0, 3.0, 1.0};
  double res[] = {-5.0 / 129.0, 65.0 / 129.0, 5.0 / 43.0, -22.0 / 43.0};
  int n = 2, m = 2;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      ck_assert(fabs(round(result.matrix[i][j] * 1000000) -
                     round(res[count] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_12) {
  matrix_t A, result;
  double arr[] = {2.0};
  int n = 1, m = 1;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  A.matrix[0][0] = arr[0];
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert(fabs(round(result.matrix[0][0] * 1000000) - round(0.5 * 1000000)) <
            1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_13) {
  matrix_t A, result;
  double arr[] = {13.2, 13.0, 3.0, 1.0};
  double res[] = {-5.0 / 129.0, 65.0 / 129.0, 5.0 / 43.0, -22.0 / 43.0};
  int n = 2, m = 2;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      ck_assert(fabs(round(result.matrix[i][j] * 1000000) -
                     round(res[count] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_14) {
  matrix_t A, result;
  double arr[] = {2.0, 1.0, 0.0, 0.0, 3.0, 2.0,  0.0, 0.0,
                  1.0, 1.0, 3.0, 4.0, 2.0, -1.0, 2.0, 3.0};
  double res[] = {2.0,  -1.0,  0.0, 0.0,  -3.0,  2.0,  0.0,  0.0,
                  31.0, -19.0, 3.0, -4.0, -23.0, 14.0, -2.0, 3.0};
  int n = 4, m = 4;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      ck_assert(fabs(round(result.matrix[i][j] * 1000000) -
                     round(res[count] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *test_inverse_matrix(void) {
  Suite *s = suite_create("\033[45m-=s21_inverse_matrix=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, inverse_matrix_1);
  tcase_add_test(tc_core, inverse_matrix_2);
  tcase_add_test(tc_core, inverse_matrix_3);
  tcase_add_test(tc_core, inverse_matrix_4);
  tcase_add_test(tc_core, inverse_matrix_5);
  tcase_add_test(tc_core, inverse_matrix_6);
  tcase_add_test(tc_core, inverse_matrix_7);
  tcase_add_test(tc_core, inverse_matrix_8);
  tcase_add_test(tc_core, inverse_matrix_9);
  tcase_add_test(tc_core, inverse_matrix_10);
  tcase_add_test(tc_core, inverse_matrix_11);
  tcase_add_test(tc_core, inverse_matrix_12);
  tcase_add_test(tc_core, inverse_matrix_13);
  tcase_add_test(tc_core, inverse_matrix_14);

  suite_add_tcase(s, tc_core);

  return s;
}
