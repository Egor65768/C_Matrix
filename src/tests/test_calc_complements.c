#include "test.h"

START_TEST(create_calc_complements_1) {
  matrix_t A, result;
  double arr[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};
  double res[] = {0.0, 10.0, -20.0, 4.0, -14.0, 8.0, -8.0, -2.0, 4.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
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

START_TEST(create_calc_complements_2) {
  matrix_t A, result;
  double arr[] = {5.0, 7.0, 1.0, -4.0, 1.0, 0.0, 2.0, 0.0, 3.0};
  double res[] = {3.0, 12.0, -2.0, -21.0, 13.0, 14.0, -1.0, -4.0, 33.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
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

START_TEST(create_calc_complements_3) {
  matrix_t A, result;
  double arr[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_calc_complements(NULL, &result), invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_calc_complements_4) {
  matrix_t A;
  double arr[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, NULL), invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_calc_complements_5) {
  matrix_t A, result;
  double arr[] = {1.0, 2.0, 3.0, 0.0, 4.0, 2.0, 5.0, 2.0, 1.0};
  int n = 2, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), calculation_error);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_calc_complements_6) {
  matrix_t A, result;
  int n = 1, m = 1;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  A.matrix[0][0] = 12.4;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert(fabs(round(result.matrix[0][0] * 1000000) - round(1.0 * 1000000)) <
            1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_calc_complements_7) {
  matrix_t A, result;
  double arr[] = {6.0, 36.0, 96.0, 27.0};
  double res[] = {27.0, -96.0, -36.0, 6.0};
  int n = 2, m = 2;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
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

Suite *test_calc_complements(void) {
  Suite *s = suite_create("\033[45m-=s21_calc_complements=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, create_calc_complements_1);
  tcase_add_test(tc_core, create_calc_complements_2);
  tcase_add_test(tc_core, create_calc_complements_3);
  tcase_add_test(tc_core, create_calc_complements_4);
  tcase_add_test(tc_core, create_calc_complements_5);
  tcase_add_test(tc_core, create_calc_complements_6);
  tcase_add_test(tc_core, create_calc_complements_7);
  suite_add_tcase(s, tc_core);

  return s;
}