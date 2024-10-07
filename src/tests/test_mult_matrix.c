#include "test.h"

START_TEST(mult_matrix_1) {
  matrix_t A, B, res, otv;

  double arr1[] = {12.312, 424.244, 234.324, 24.5443, 12.34, 34.424};
  double arr2[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  double res1[] = {436.556,  436.556, 436.556, 258.8683, 258.8683,
                   258.8683, 46.764,  46.764,  46.764};
  int n1 = 2, m1 = 3;
  int n2 = 3, m2 = 2;
  ck_assert_int_eq(s21_create_matrix(m1, n1, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m2, n2, &B), OK);
  ck_assert_int_eq(s21_create_matrix(m1, n2, &res), OK);
  for (int i = 0, count = 0; i < m1; i++) {
    for (int j = 0; j < n1; j++, count++) {
      A.matrix[i][j] = arr1[count];
      B.matrix[j][i] = arr2[count];
    }
  }
  for (int i = 0, count = 0; i < m1; i++) {
    for (int j = 0; j < n2; j++, count++) {
      res.matrix[i][j] = res1[count];
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &otv), OK);
  for (int i = 0; i < m1; i++) {
    for (int j = 0; j < n1; j++) {
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

START_TEST(mult_matrix_2) {
  matrix_t A, B, otv;
  ck_assert_int_eq(s21_create_matrix(4, 4, &A), OK);
  ck_assert_int_eq(s21_create_matrix(3, 4, &B), OK);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &otv), calculation_error);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t A, B;
  ck_assert_int_eq(s21_create_matrix(4, 4, &A), OK);
  ck_assert_int_eq(s21_create_matrix(4, 4, &B), OK);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), invalid_matrix);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t A, B, res, otv;

  double arr1[] = {12.312, 424.244, 234.324, 24.5443};
  double arr2[] = {24.455, 0.424, 244.522, 13.3321};
  double res1[] = {104038.081328, 5661.2837204, 11732.0147446, 426.58043803};
  int n1 = 2, m1 = 2;
  int n2 = 2, m2 = 2;
  ck_assert_int_eq(s21_create_matrix(m1, n1, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m2, n2, &B), OK);
  ck_assert_int_eq(s21_create_matrix(m1, n2, &res), OK);
  for (int i = 0, count = 0; i < m1; i++) {
    for (int j = 0; j < n1; j++, count++) {
      A.matrix[i][j] = arr1[count];
      B.matrix[i][j] = arr2[count];
    }
  }
  for (int i = 0, count = 0; i < m1; i++) {
    for (int j = 0; j < n2; j++, count++) {
      res.matrix[i][j] = res1[count];
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &otv), OK);
  for (int i = 0; i < m1; i++) {
    for (int j = 0; j < n1; j++) {
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

START_TEST(mult_matrix_5) {
  matrix_t A, B, otv;
  ck_assert_int_eq(s21_create_matrix(4, 4, &A), OK);
  ck_assert_int_eq(s21_create_matrix(4, 4, &B), OK);
  ck_assert_int_eq(s21_mult_matrix(NULL, &B, &otv), invalid_matrix);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_6) {
  matrix_t A, B, otv;
  ck_assert_int_eq(s21_create_matrix(4, 4, &A), OK);
  ck_assert_int_eq(s21_create_matrix(4, 4, &B), OK);
  A.matrix[0][0] = INFINITY;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &otv), calculation_error);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_7) {
  matrix_t A, B, otv;
  ck_assert_int_eq(s21_create_matrix(4, 4, &A), OK);
  ck_assert_int_eq(s21_create_matrix(4, 4, &B), OK);
  B.matrix[1][0] = NAN;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &otv), calculation_error);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *s = suite_create("\033[45m-=s21_mult_matrix=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, mult_matrix_1);
  tcase_add_test(tc_core, mult_matrix_2);
  tcase_add_test(tc_core, mult_matrix_3);
  tcase_add_test(tc_core, mult_matrix_4);
  tcase_add_test(tc_core, mult_matrix_5);
  tcase_add_test(tc_core, mult_matrix_6);
  tcase_add_test(tc_core, mult_matrix_7);
  suite_add_tcase(s, tc_core);

  return s;
}
