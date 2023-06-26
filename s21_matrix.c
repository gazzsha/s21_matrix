#include "s21_matrix.h"

// 0 - ОК
// 1 - Ошибка, неправильная матрица
// 2 - Ошибка расчета (несоответствие размеров матриц; матрица, для которой
// невозможно произвести расчеты и т.д.)
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_value = 0;
  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; ++i) {
      result->matrix[i] = malloc(columns * sizeof(double));
    }
    s21_set_null_matrix(result);
  } else
    return_value = 1;
  return return_value;
}

void s21_remove_matrix(matrix_t *A) {
  if (!s21_is_null_matrix(A)) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_value = SUCCESS;
  if (s21_is_null_matrix(A) || s21_is_null_matrix(B)) {
    return_value = FAILURE;
  } else if (s21_wrong_matrix(A) || s21_wrong_matrix(B)) {
    return_value = FAILURE;
  } else if (!s21_check_accuracy_size(A, B)) {
    return_value = FAILURE;
  } else {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        if (!comparison_double(A->matrix[i][j], B->matrix[i][j])) {
          return_value = FAILURE;
        }
      }
    }
  }
  return return_value;
}

// 0 - ОК
// 1 - Ошибка, неправильная матрица
// 2 - Ошибка расчета (несоответствие размеров матриц; матрица, для которой
// невозможно произвести расчеты и т.д.)
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = 0;
  if (s21_is_null_matrix(A) || s21_is_null_matrix(B)) {
    return_value = 1;
  } else if (s21_wrong_matrix(A) || s21_wrong_matrix(B)) {
    return_value = 1;
  } else if (!s21_check_accuracy_size(A, B)) {
    return_value = 2;
  } else {
    return_value = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return return_value;
}

// 0 - ОК
// 1 - Ошибка, неправильная матрица
// 2 - Ошибка расчета (несоответствие размеров матриц; матрица, для которой
// невозможно произвести расчеты и т.д.)
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = 0;
  if (s21_is_null_matrix(A) || s21_is_null_matrix(B)) {
    return_value = 1;
  } else if (s21_wrong_matrix(A) || s21_wrong_matrix(B)) {
    return_value = 1;
  } else if (!s21_check_accuracy_size(A, B)) {
    return_value = 2;
  } else {
    return_value = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return return_value;
}

// 0 - ОК
// 1 - Ошибка, неправильная матрица
// 2 - Ошибка расчета (несоответствие размеров матриц; матрица, для которой
// невозможно произвести расчеты и т.д.)
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_value = 0;
  if (s21_is_null_matrix(A)) {
    return_value = 1;
  } else if (s21_wrong_matrix(A)) {
    return_value = 1;
  } else {
    return_value = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        if (A->matrix[i][j] != 0.0f && number != 0.0f) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return return_value;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = 0;
  if (s21_is_null_matrix(A) || s21_is_null_matrix(B)) {
    return_value = 1;
  } else if (s21_wrong_matrix(A) || s21_wrong_matrix(B)) {
    return_value = 1;
  } else if (A->columns != B->rows) {
    return_value = 2;
  } else {
    return_value = s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int k = 0; k < B->columns; k++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][k] += A->matrix[i][j] * B->matrix[j][k];
        }
      }
    }
  }
  return return_value;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_value = 0;
  if (s21_is_null_matrix(A)) {
    return_value = 1;
  } else if (s21_wrong_matrix(A)) {
    return_value = 1;
  } else {
    return_value = s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return return_value;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_value = 0;
  if (s21_is_null_matrix(A) || !result) {
    return_value = 1;
  } else if (s21_wrong_matrix(A)) {
    return_value = 1;
  } else if (A->rows != A->columns) {
    return_value = 2;
  } else if (A->rows == 1) {
    return_value = 2;
  } else {
    double sign = 1.0f;
    return_value = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t intermediate_matrix = {0};
        getNewMatrix(A, &intermediate_matrix, i, j, A->rows - 1);
        if (((i + j) % 2) == 0)
          sign = 1.0f;
        else
          sign = (-1.0f);
        double matrix_determinant =
            s21_matrix_determinant(&intermediate_matrix);
        result->matrix[i][j] =
            (matrix_determinant == 0.0f ? 1 : sign) * matrix_determinant;
        s21_remove_matrix(&intermediate_matrix);
      }
    }
  }
  return return_value;
}

int s21_determinant(matrix_t *A, double *result) {
  int return_value = 0;
  if (s21_is_null_matrix(A) || !result) {
    return_value = 1;
  } else if (s21_wrong_matrix(A)) {
    return_value = 1;
  } else if (A->rows != A->columns) {
    return_value = 2;
  } else {
    *result = s21_matrix_determinant(A);
  }
  return return_value;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_value = 0;
  if (s21_is_null_matrix(A) || !result) {
    return_value = 1;
  } else if (s21_wrong_matrix(A)) {
    return_value = 1;
  } else if (A->rows != A->columns) {
    return_value = 2;
  } else if (A->rows == 1) {
    if ((A->matrix[0][0]) == 0.0f)
      return_value = 2;
    else {
      return_value = s21_create_matrix(A->rows, A->columns, result);
      result->matrix[0][0] = 1.0f / A->matrix[0][0];
    }
  } else {
    double determitant = 0.0f;
    determitant = s21_matrix_determinant(A);
    if (determitant == 0) {
      return_value = 2;
    } else {
      matrix_t algebraic_additions = {0};
      s21_calc_complements(A, &algebraic_additions);
      matrix_t algebraic_additions_transpoce = {0};
      s21_transpose(&algebraic_additions, &algebraic_additions_transpoce);
      s21_mult_number(&algebraic_additions_transpoce, 1.0f / determitant,
                      result);
      s21_remove_matrix(&algebraic_additions);
      s21_remove_matrix(&algebraic_additions_transpoce);
    }
  }
  return return_value;
}
