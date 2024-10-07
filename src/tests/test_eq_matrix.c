#include "test.h"

START_TEST(eq_matrix_1) {
  matrix_t A, B;
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &B), OK);
  double arr[] = {64.234455, 1234.432,  213.221, 332.2344, 0.12343,
                  123.333,   88109.331, 1223.13, 0.21233};
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
      B.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t A, B;
  int n = 3, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &B), OK);
  double arr[] = {64.234455, 1234.432,  213.221, 332.2344, 0.12343,
                  123.333,   88109.331, 1223.13, 0.21233};
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
      B.matrix[i][j] = arr[count];
    }
  }
  B.matrix[0][0] = 1.212334;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t A, B;
  int n = 3, m = 3, k = 2;

  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, k, &B), OK);
  double arr[] = {64.234455, 1234.432,  213.221, 332.2344, 0.12343,
                  123.333,   88109.331, 1223.13, 0.21233};
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < k; j++, count++) {
      B.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_4) {
  matrix_t A, B;
  int n = 3, m = 3, k = 2;

  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(k, n, &B), OK);
  double arr[] = {64.234455, 1234.432,  213.221, 332.2344, 0.12343,
                  123.333,   88109.331, 1223.13, 0.21233};
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  for (int i = 0, count = 0; i < k; i++) {
    for (int j = 0; j < n; j++, count++) {
      B.matrix[i][j] = arr[count];
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_5) {
  matrix_t A, B;
  int n = 3, m = 3;

  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &B), OK);
  double arr[] = {64.234455, 1234.432,  213.221, 332.2344, 0.12343,
                  123.333,   88109.331, 1223.13, 0.21233};
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
    }
  }
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      B.matrix[i][j] = arr[count] + 0.00001;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_6) {
  matrix_t A, B;
  int n = 3, m = 3;

  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &B), OK);
  double arr[] = {64.234455, 1234.432,  213.221, 332.2344, 0.12343,
                  123.333,   88109.331, 1223.13, 0.21233};
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
      B.matrix[i][j] = arr[count];
    }
  }
  B.matrix[2][2] = B.matrix[2][2] + 0.0000001;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_7) {
  matrix_t A, B;
  int n = 3, m = 3;

  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &B), OK);
  double arr[] = {64.233,  1234.432,  213.221, 332.2344, 0.12343,
                  123.333, 88109.331, 1223.13, 0.2233};
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
      B.matrix[i][j] = arr[count];
    }
  }
  B.matrix[0][0] = B.matrix[0][0] + 1e-8;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_8) {
  matrix_t A, B;
  int n = 3, m = 3;

  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  ck_assert_int_eq(s21_create_matrix(m, n, &B), OK);
  double arr[] = {64.233,  1234.432,  213.221, 332.2344, 0.12343,
                  123.333, 88109.331, 1223.13, 0.2233};
  for (int i = 0, count = 0; i < m; i++) {
    for (int j = 0; j < n; j++, count++) {
      A.matrix[i][j] = arr[count];
      B.matrix[i][j] = arr[count];
    }
  }
  B.matrix[0][0] = B.matrix[0][0] + 1e-6;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_eq_matrix(void) {
  Suite *s = suite_create("\033[45m-=s21_eq_matrix=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, eq_matrix_1);
  tcase_add_test(tc_core, eq_matrix_2);
  tcase_add_test(tc_core, eq_matrix_3);
  tcase_add_test(tc_core, eq_matrix_4);
  tcase_add_test(tc_core, eq_matrix_5);
  tcase_add_test(tc_core, eq_matrix_6);
  tcase_add_test(tc_core, eq_matrix_7);
  tcase_add_test(tc_core, eq_matrix_8);
  suite_add_tcase(s, tc_core);

  return s;
}
