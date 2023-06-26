// #include "s21_matrix.h"

// double get_rand(double min, double max) {
//   double val = (double)rand() / RAND_MAX;
//   return min + val * (max - min);
// }

// int main() {
//  int res = 0;
//   matrix_t A = {0};
//   matrix_t Z = {0};
//   matrix_t X = {0};

//   s21_create_matrix(3, 3, &A);
//   A.matrix[0][0] = 1.0;
//   A.matrix[0][1] = 2.0;
//   A.matrix[0][2] = 3.0;
//   A.matrix[1][0] = 4.0;
//   A.matrix[1][1] = 5.0;
//   A.matrix[1][2] = 6.0;
//   A.matrix[2][0] = 8.0;
//   A.matrix[2][1] = 6.0;
//   A.matrix[2][2] = 9.0;

//   s21_inverse_matrix(&A, &Z);

//   s21_create_matrix(3, 3, &X);

//   X.matrix[0][0] = -3.0 / 5.0;
//   X.matrix[0][1] = 0.0;
//   X.matrix[0][2] = 1.0 / 5.0;
//   ;
//   X.matrix[1][0] = -4.0 / 5.0;
//   X.matrix[1][1] = 1.0;
//   X.matrix[1][2] = -2.0 / 5.0;
//   X.matrix[2][0] = 16.0 / 15.0;
//   X.matrix[2][1] = -2.0 / 3.0;
//   X.matrix[2][2] = 1.0 / 5.0;

//   res = s21_eq_matrix(&X, &Z);
//   print_matrix(X);
//   print_matrix(Z);
//   s21_remove_matrix(&A);
//   s21_remove_matrix(&X);
//   s21_remove_matrix(&Z);
//   printf("%d\n",res);

//   return 0;
// }