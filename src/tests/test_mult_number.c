#include "test.h"

START_TEST(mult_number_1) {
  matrix_t A, res, otv;
  double mul = 1.0;
  double arr1[] = {12.312, 424.244, 234.324, 24.5443};
  double res1[] = {12.312, 424.244, 234.324, 24.5443};
  int n = 2, m = 2;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &res), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr1[count];
      res.matrix[i][j] = res1[count];
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, mul, &otv), OK);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ck_assert(fabs(round(res.matrix[i][j] * 1000000) -
                     round(otv.matrix[i][j] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&otv);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t A, res, otv;
  double mul = 0.0;
  double arr1[] = {12.312, 424.244, 234.324, 24.5443};
  double res1[] = {0.0, 0.0, 0.0, 0.0};
  int n = 2, m = 2;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &res), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr1[count];
      res.matrix[i][j] = res1[count];
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, mul, &otv), OK);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ck_assert(fabs(round(res.matrix[i][j] * 1000000) -
                     round(otv.matrix[i][j] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&otv);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t A, res, otv;
  double mul = 2.212;
  double arr1[] = {12.312, 424.244, 234.324, 24.5443};
  double res1[4];
  for (int i = 0; i < 4; i++) {
    res1[i] = arr1[i] * mul;
  }
  int n = 2, m = 2;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &res), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr1[count];
      res.matrix[i][j] = res1[count];
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, mul, &otv), OK);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ck_assert(fabs(round(res.matrix[i][j] * 1000000) -
                     round(otv.matrix[i][j] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&otv);
}
END_TEST

START_TEST(mult_number_4) {
  matrix_t A, otv;
  double mul = INFINITY;
  double arr1[] = {12.312, 424.244, 234.324, 24.5443};
  int n = 2, m = 2;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr1[count];
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, mul, &otv), calculation_error);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_5) {
  matrix_t A, otv;
  double mul = NAN;
  double arr1[] = {12.312, 424.244, 234.324, 24.5443};
  int n = 2, m = 2;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr1[count];
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, mul, &otv), calculation_error);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_6) {
  matrix_t A, otv;
  double mul = NAN;
  double arr1[] = {12.312, 424.244, 234.324, 24.5443};
  int n = 2, m = 2;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr1[count];
    }
  }
  ck_assert_int_eq(s21_mult_number(NULL, mul, &otv), invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_mult_number(void) {
  Suite *s = suite_create("\033[45m-=s21_mult_number=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, mult_number_1);
  tcase_add_test(tc_core, mult_number_2);
  tcase_add_test(tc_core, mult_number_3);
  tcase_add_test(tc_core, mult_number_4);
  tcase_add_test(tc_core, mult_number_5);
  tcase_add_test(tc_core, mult_number_6);

  suite_add_tcase(s, tc_core);

  return s;
}
