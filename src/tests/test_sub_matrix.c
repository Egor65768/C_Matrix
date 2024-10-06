#include "test.h"

START_TEST(sub_matrix_1) {
  matrix_t A, B, res, otv;
  double arr1[] = {12.312, 424.244, 234.324, 24.5443};
  double arr2[] = {0.123, 12.3121, 9.9999, -123.123};
  double res1[] = {12.189, 411.9319, 224.3241, 147.6673};
  int n = 2, m = 2;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &B), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &res), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr1[count];
      B.matrix[i][j] = arr2[count];
      res.matrix[i][j] = res1[count];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &otv), OK);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ck_assert(fabs(round(res.matrix[i][j] * 1000000) -
                     round(otv.matrix[i][j] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&otv);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t A, B, res, otv;
  double arr1[] = {12.312, 424.244, 234.324, 24.5443};
  double arr2[] = {0.123, 12.3121, 9.9999, -123.123};
  double res1[] = {12.189, 411.9319, 224.3241, 147.6673};
  int n = 2, m = 1;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &B), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &res), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr1[count];
      B.matrix[i][j] = arr2[count];
      res.matrix[i][j] = res1[count];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &otv), OK);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ck_assert(fabs(round(res.matrix[i][j] * 1000000) -
                     round(otv.matrix[i][j] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&otv);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t A, B, res, otv;
  double arr1[] = {12.312, 424.244, 234.324, 24.5443};
  double arr2[] = {0.123, 12.3121, 9.9999, -123.123};
  double res1[] = {12.189, 411.9319, 224.3241, 147.6673};
  int n = 1, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &B), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &res), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr1[count];
      B.matrix[i][j] = arr2[count];
      res.matrix[i][j] = res1[count];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &otv), OK);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ck_assert(fabs(round(res.matrix[i][j] * 1000000) -
                     round(otv.matrix[i][j] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&otv);
}
END_TEST

START_TEST(sub_matrix_4) {
  matrix_t A, B, res, otv;
  double arr1[] = {12.312, 424.244, 234.324, 24.5443};
  double arr2[] = {0.123, 12.3121, 9.9999, -123.123};
  double res1[] = {12.189, 411.9319, 224.3241, 147.6673};
  int n = 1, m = 1;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &B), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &res), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr1[count];
      B.matrix[i][j] = arr2[count];
      res.matrix[i][j] = res1[count];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &otv), OK);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ck_assert(fabs(round(res.matrix[i][j] * 1000000) -
                     round(otv.matrix[i][j] * 1000000)) < 1);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&otv);
}
END_TEST

START_TEST(sub_matrix_5) {
  matrix_t B, otv;
  ck_assert_int_eq(s21_sub_matrix(NULL, &B, &otv), invalid_matrix);
}
END_TEST

Suite *test_sub_matrix(void) {
  Suite *s = suite_create("\033[45m-=s21_sub_matrix=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, sub_matrix_1);
  tcase_add_test(tc_core, sub_matrix_2);
  tcase_add_test(tc_core, sub_matrix_3);
  tcase_add_test(tc_core, sub_matrix_4);
  tcase_add_test(tc_core, sub_matrix_5);

  suite_add_tcase(s, tc_core);

  return s;
}
