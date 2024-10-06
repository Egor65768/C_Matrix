#include "test.h"

START_TEST(transpose_1) {
  matrix_t A, otv;
  int n = 3, m = 3;
  double arr[] = {13.243, 123.342, 0.1233, 123.34, 1242.34,
                  0.242,  123.44,  123.44, 33.313};
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &otv), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      ck_assert_double_eq(otv.matrix[j][i], arr[count]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&otv);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A, otv;
  int n = 3, m = 2;
  double arr[] = {13.43, 23.342, 0.13, 9823.34, 1442.34, 110.242, 32.2};
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &otv), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      ck_assert_double_eq(otv.matrix[j][i], arr[count]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&otv);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t otv;
  ck_assert_int_eq(s21_transpose(NULL, &otv), invalid_matrix);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t res;
  ck_assert_int_eq(s21_transpose(&res, NULL), invalid_matrix);
}
END_TEST

START_TEST(transpose_5) {
  matrix_t A, otv;
  int m = 3, n = 4;
  double arr[] = {1.23, 32.3,    53.1,  0.01,      244.323, 132.3, 3.1,
                  3.4,  356.632, 0.423, 3204.2423, 432.44,  32.4};
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &otv), OK);
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; count++, j++) {
      ck_assert_double_eq(otv.matrix[j][i], arr[count]);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&otv);
}
END_TEST

Suite *test_transpose(void) {
  Suite *s = suite_create("\033[45m-=s21_transpose=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, transpose_1);
  tcase_add_test(tc_core, transpose_2);
  tcase_add_test(tc_core, transpose_3);
  tcase_add_test(tc_core, transpose_4);
  tcase_add_test(tc_core, transpose_5);

  suite_add_tcase(s, tc_core);

  return s;
}
