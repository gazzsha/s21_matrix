#include "s21_matrix.h"

int main() {
  //     matrix_t A = {0};
  //     matrix_t result = {0};
  //     matrix_t result2 = {0};
  //     printf("%d\n",s21_create_matrix(3,3,&A));

  //     for (int i = 0; i < A.rows; i++) {
  //         for (int j = 0; j < A.columns ; ++j) {
  //             A.matrix[i][j] = 1 * j;
  //         }
  //     }
  //       print_matrix(A);
  //      matrix_t B;
  //     s21_create_matrix(3,3,&B);
  //     for (int i = 0; i < B.rows; i++) {
  //         for (int j = 0; j < B.columns ; ++j) {
  //             B.matrix[i][j] = 2 * j;
  //         }
  //     }
  //     print_matrix(B);
  //    printf("%d\n",s21_sub_matrix(&A,&B,&result));
  // //    printf("%d\n",s21_ы_matrix(&A,&B));
  //     print_matrix(result);
  //     double n = 1.99954;
  //     printf("%d\n",s21_mult_number(&A,n,&result2));
  //     print_matrix(result2);
  //      s21_remove_matrix(&A);
  //      s21_remove_matrix(&B);
  //    s21_remove_matrix(&result);
  //    s21_remove_matrix(&result2);
  //    printf("--------------------\n");
  //    matrix_t a ={0};
  //    matrix_t b = {0};
  //    matrix_t c = {0};
  //     printf("%d\n",s21_create_matrix(1,3,&a));
  //     printf("%d\n",s21_create_matrix(3,3,&b));

  //     double m  = 1;
  //     for (int i = 0; i < a.rows; i++) {
  //         for (int j = 0; j < a.columns ; ++j,m++) {
  //             a.matrix[i][j] = m ;
  //         }
  //     }
  //     double  v = 1;
  //      for (int i = 0; i < b.rows; i++) {
  //         for (int j = 0; j < b.columns ; ++j,v++) {
  //             b.matrix[i][j] = v;
  //         }
  //     }
  //     print_matrix(a);
  //     printf("%d\n",s21_mult_matrix(&a,&b,&c));
  //     s21_remove_matrix(&a);
  //     matrix_t d = {0};
  //     printf("%d\n",s21_transpose(&c,&d));
  //     print_matrix(d);
  //     print_matrix(c);
  //     printf("--------------------\n");
  //     print_matrix(b);
  //     printf("%f\n",s21_matrix_determinant(&b));
  //       s21_remove_matrix(&b);
  //     s21_remove_matrix(&c);
  //     s21_remove_matrix(&d);
  //   printf("--------------------\n");

  matrix_t aa = {0}, cc = {0}, dd = {0};
  s21_create_matrix(3, 3, &aa);
  aa.matrix[0][0] = 2;
  aa.matrix[0][1] = 5;
  aa.matrix[0][2] = 7;
  aa.matrix[1][0] = 6;
  aa.matrix[1][1] = 3;
  aa.matrix[1][2] = 4;
  aa.matrix[2][0] = 5;
  aa.matrix[2][1] = -2;
  aa.matrix[2][2] = -3;
  print_matrix(aa);
  // double  res = 0;
  printf("%d\n", s21_calc_complements(&aa, &cc));
  printf("%d\n", s21_inverse_matrix(&aa, &dd));
  print_matrix(cc);
  print_matrix(dd);
  s21_remove_matrix(&aa);
  s21_remove_matrix(&cc);
  s21_remove_matrix(&dd);

  return 0;
}