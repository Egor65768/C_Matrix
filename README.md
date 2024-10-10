# C_Matrix

Библиотека для работы с матрицами, реализованная на языке C

При реализации библиотеки я использовал структуру
```
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```

Все операции (кроме сравнения матриц) должны возвращать результирующий код:  
- 0 - OK
- 1 - Ошибка, некорректная матрица   
- 2 - Ошибка вычисления

## Руководство по использованию

### Для сборки библиотеки и исполняемого файла тестов, а так же формирования отчета о покрытии кода используй следующие команды:

```make all```

### Для создания статической библиотеки:

```make s21_matrix.a```

### Для запуска тестов:

```make test```

### Для запуска тестов и проверки утечек памяти:

```make leaks```

### Для отчистки проекта от всех временных и промежуточных файлов:

```make clean```

### Для удаления статической библиотеки:

```make clean_lib```

### Для начиная с удаления старых файлов и создания новой версии библиотеки и запуска тестов:

```make rebuild```

### Для создания отчета о покрытии кода:

```make gcov_report```

### Для проверки стиля кода:

```make style```

### Для применения стиля форматирования Google к коду:

```make format```

## Функции библиотеки  

### Создание матриц (create_matrix)

```c
int s21_create_matrix(int rows, int columns, matrix_t *result);
```

### Очистка матриц (remove_matrix)

```c
void s21_remove_matrix(matrix_t *A);
```

### Сравнение матриц (eq_matrix)

```c
#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B);
```

### Сложение (sum_matrix) и вычитание матриц (sub_matrix)

```c
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

### Умножение матрицы на число (mult_number). Умножение двух матриц (mult_matrix)

```c
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

### Транспонирование матрицы (transpose)

```c
int s21_transpose(matrix_t *A, matrix_t *result);
```

### Минор матрицы и матрица алгебраических дополнений (calc_complements)

```c
int s21_calc_complements(matrix_t *A, matrix_t *result);
```

### Определитель матрицы (determinant)

```c
int s21_determinant(matrix_t *A, double *result);
```

### Обратная матрица (inverse_matrix)

```c
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
```