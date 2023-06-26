#include "s21_matrix.h"

void s21_set_null_matrix(matrix_t* result) {
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = 0;
    }
  }
}

void print_matrix(matrix_t result) {
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      printf("%f ", result.matrix[i][j]);
    }
    printf("\n");
  }
}

// срравние чисел double, 1 -OK, 0 - NOT OK
int comparison_double(double x, double y) {
  int flag = 0;
  char str_x[1000] = {0};
  char str_y[1000] = {0};
  sprintf(str_x, "%.6f", x);
  sprintf(str_y, "%.6f", y);
  if (strcmp(str_x, str_y) == 0)
    flag = 1;
  else
    flag = 0;
  return flag;
}

// 1 - NULL, 0 - NOT NULL
int s21_is_null_matrix(matrix_t* result) {
  int return_value = 0;
  if (!result)
    return_value = 1;
  else if (result->matrix == NULL)
    return_value = 1;
  return return_value;
}

// 0 - OK, 1 - NOT OK, неправильные rows or cols <= 0
int s21_wrong_matrix(matrix_t* result) {
  int return_value = 0;
  if (!s21_is_null_matrix(result)) {
    if (result->rows <= 0 || result->columns <= 0) return_value = 1;
  } else
    return_value = 1;
  return return_value;
}

// 1 - rows and cols is equal 0 - NOT SQUARD
int s21_check_accuracy_size(matrix_t* A, matrix_t* B) {
  return (A->rows == B->rows && A->columns == B->columns) ? 1 : 0;
}

double s21_matrix_determinant(matrix_t* result) {
  double return_value = 0.0f;
  int sign = 1;
  int matrix_order = result->rows;
  if (result->rows == 1) {
    return_value = result->matrix[0][0];
  } else if (result->rows == 2) {
    return_value = result->matrix[0][0] * result->matrix[1][1] -
                   result->matrix[0][1] * result->matrix[1][0];
  } else {
    for (int i = 0; i < result->columns; i++) {
      matrix_t new_matrix = {0};
      getNewMatrix(result, &new_matrix, 0, i, matrix_order - 1);
      return_value +=
          sign * result->matrix[0][i] * s21_matrix_determinant(&new_matrix);
      s21_remove_matrix(&new_matrix);
      sign = -sign;
    }
  }
  return return_value;
}

// n - строка которую надо обходить, m - столбец который надо обходить, new_size
// - размер новой матрицы
void getNewMatrix(matrix_t* A, matrix_t* result, int n, int m, int new_size) {
  s21_create_matrix(new_size, new_size, result);
  int h = 0, k = 0;  // индексы новой матрицы
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (i != n && j != m) {
        result->matrix[h][k++] = A->matrix[i][j];
        if (k == (A->columns - 1)) {
          h++;
          k = 0;
        }
      }
    }
  }
}