#include "test.h"

START_TEST(create_matrix_1) {
  matrix_t A;
  int n = 0, m = 3;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t A;
  int n = 3, m = 0;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_3) {
  matrix_t A;
  int n = 1, m = -1;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_4) {
  matrix_t A;
  int n = -223, m = 1;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), invalid_matrix);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_5) {
  matrix_t A;
  int n = 1, m = 1;
  ck_assert_int_eq(s21_create_matrix(m, n, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *s = suite_create("\033[45m-=s21_create_matrix=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, create_matrix_1);
  tcase_add_test(tc_core, create_matrix_2);
  tcase_add_test(tc_core, create_matrix_3);
  tcase_add_test(tc_core, create_matrix_4);
  tcase_add_test(tc_core, create_matrix_5);
  suite_add_tcase(s, tc_core);

  return s;
}
