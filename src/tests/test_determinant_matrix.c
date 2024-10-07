#include "test.h"

START_TEST(determinant_matrix_1) {
  matrix_t A;
  double res = 0.0;
  double arr[] = {12.0, 3.0, 3.0, 6.0, 5.0, 4.0, 9.0, 32.0, 5.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert(fabs(round(res * 1000000) - round(-777.0 * 1000000)) < 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_matrix_2) {
  matrix_t A;
  double res = 0.0;
  double arr[] = {12.0, 3.0, 3.0, 6.0, 5.0, 4.0, 9.0, 32.0, 5.0};
  int n = 2, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &res), calculation_error);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_matrix_3) {
  matrix_t A;
  double res = 0.0;
  double arr[] = {12.0, 3.0, 3.0, 6.0};
  int n = 2, m = 2;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert(fabs(round(res * 1000000) - round(63.0 * 1000000)) < 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_matrix_4) {
  matrix_t A;
  double res = 0.0;
  double arr[] = {12.0};
  int n = 1, m = 1;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert(fabs(round(res * 1000000) - round(12.0 * 1000000)) < 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_matrix_5) {
  matrix_t A;
  double res = 0.0;
  double arr[] = {12.0};
  int n = 1, m = 1;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_determinant(NULL, &res), invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_matrix_6) {
  matrix_t A;
  double res = 0.0;
  double arr[] = {12.0, 3.0, 14.0, 2.0, 6.0, 5.0, 5.0,  6.0,
                  4.0,  6.0, 8.0,  9.0, 4.0, 6.0, -2.0, -13.0};
  int n = 4, m = 4;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert(fabs(round(res * 1000000) - round(-5220.0 * 1000000)) < 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_matrix_7) {
  matrix_t A;
  double res = 0.0;
  double arr[] = {12.0,  3.0, 14.0, 2.0, 1.0, 6.0, 5.0, 5.0, 6.0,
                  2.0,   4.0, 6.0,  8.0, 9.0, 3.0, 4.0, 6.0, -2.0,
                  -13.0, 4.0, 5.0,  6.0, 4.0, 3.0, 4.0};
  int n = 5, m = 5;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert(fabs(round(res * 1000000) - round(-5391.0 * 1000000)) < 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_matrix_8) {
  matrix_t A;
  double res = 0.0;
  double arr[] = {12.12, 3.3, 3.4, 6.0, 5.0, 4.0, 9.01, 32.10, 5.4};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &res), OK);
  ck_assert(fabs(round(res * 1000000) - round(-715.286 * 1000000)) < 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_matrix_9) {
  matrix_t A;
  double res = 0.0;
  double arr[] = {NAN, 3.3, 3.4, 6.0, 5.0, 4.0, 9.01, 32.10, 5.4};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &res), calculation_error);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_matrix_10) {
  matrix_t A;
  double res = 0.0;
  double arr[] = {INFINITY, 3.3, 3.4, 6.0, 5.0, 4.0, 9.01, 32.10, 5.4};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &res), calculation_error);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_determinant_matrix(void) {
  Suite *s = suite_create("\033[45m-=s21_determinant_matrix=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, determinant_matrix_1);
  tcase_add_test(tc_core, determinant_matrix_2);
  tcase_add_test(tc_core, determinant_matrix_3);
  tcase_add_test(tc_core, determinant_matrix_4);
  tcase_add_test(tc_core, determinant_matrix_5);
  tcase_add_test(tc_core, determinant_matrix_6);
  tcase_add_test(tc_core, determinant_matrix_7);
  tcase_add_test(tc_core, determinant_matrix_8);
  tcase_add_test(tc_core, determinant_matrix_9);
  tcase_add_test(tc_core, determinant_matrix_10);
  suite_add_tcase(s, tc_core);

  return s;
}
