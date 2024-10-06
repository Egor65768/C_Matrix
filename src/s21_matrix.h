#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define invalid_matrix 1
#define calculation_error 2

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  // строки
  int rows;
  // столбцы
  int columns;
} matrix_t;

// создание матрицы
int s21_create_matrix(int rows, int columns, matrix_t *result);

//  удаление матрицы
void s21_remove_matrix(matrix_t *A);

// сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// суммирование матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// вычитание матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// умножение двух матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// функция возвращает i и j ячейку в матрице, полученной умножением A и B
double help_mult_matrix(matrix_t A, matrix_t B, int i, int j);

// транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result);

// вычисляет определитель матрицы
int s21_determinant(matrix_t *A, double *result);

// вычисляет определитель матрицы 2 на 2
double calculating_minor_two_by_two(matrix_t A);

// матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);

// делает знаки правильными в матрице алгебраических дополнений
void help_calc_complements(matrix_t *result);

// обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// help_func

// проверка на наличия nan или inf в матрице
int matrix_nan_or_inf(matrix_t A, matrix_t B);

// функция складывает или вычитает матрицы в зависимости от переменой operation
// (-1 или 1)
int help_add_or_sub(matrix_t *A, matrix_t *B, matrix_t *result, int operation);

// функция изменяет buf. buf это матрица полученная из A вычеркиванием
// переданной строки и столбца
void help_matrix_formation(matrix_t A, matrix_t *buf, int delite_row,
                           int delite_columns);

#endif