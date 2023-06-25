#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;


// support functions 
void s21_set_null_matrix(matrix_t * result );
void print_matrix(matrix_t result);
int comparison_double(double x, double y);
int s21_is_null_matrix(matrix_t * result);
int s21_check_accuracy_size(matrix_t * A,matrix_t * B);
int s21_wrong_matrix(matrix_t * result);
double s21_matrix_determinant(matrix_t * result);
void getNewMatrix(matrix_t * A, matrix_t * result,int n,int m, int new_size);
// main functions
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);