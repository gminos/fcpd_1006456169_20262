/**
 * @file omp_08_matrix_multiplication.c
 * @brief Practice logic exercises in C focusing on OpenMP parallel matrix multiplication
 * @author Jose Belarmino Hernandez Giraldo
 * @date 2026-09-29
 *
 * FUNCTIONALITY:
 * This program multiplies two 3x3 matrices both sequentially and in parallel using
 * OpenMP (`#pragma omp parallel for`). Elements are accessed via 2D pointer arithmetic
 * (*(*(matrix + i) + j)). Execution times are measured using `omp_get_wtime()` for comparison,
 * and the resulting matrices are printed to verify correctness.
 *
 * EXPECTED OUTPUT:
 * Sequential matrix multiplication result:
 *    30   24   18
 *    84   69   54
 *   138  114   90
 * Sequential time: X.XXXXXXXXXsg
 * -----------------------------------
 * Thread X of Y processing i = ...
 * ...
 * Parallel matrix multiplication result:
 *    30   24   18
 *    84   69   54
 *   138  114   90
 * Parallel time: X.XXXXXXXXXsg
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 3

void matrix_multiply_sequential(int matrix_one[][MATRIX_SIZE],
                                int matrix_two[][MATRIX_SIZE],
                                int matrix_result[][MATRIX_SIZE]) {
  for (int i = 0; i < MATRIX_SIZE; i++) {
    for (int j = 0; j < MATRIX_SIZE; j++) {
      for (int k = 0; k < MATRIX_SIZE; k++) {
        *(*(matrix_result + i) + j) +=
            *(*(matrix_one + i) + k) * *(*(matrix_two + k) + j);
      }
    }
  }
}

void matrix_multiply_parallel(int matrix_one[][MATRIX_SIZE],
                              int matrix_two[][MATRIX_SIZE],
                              int matrix_result[][MATRIX_SIZE]) {
#pragma omp parallel for
  for (int i = 0; i < MATRIX_SIZE; i++) {
    printf("Thread %d of %d processing i = %d\n", omp_get_thread_num(),
           omp_get_num_threads(), i);
    for (int j = 0; j < MATRIX_SIZE; j++) {
      for (int k = 0; k < MATRIX_SIZE; k++) {
        *(*(matrix_result + i) + j) +=
            *(*(matrix_one + i) + k) * *(*(matrix_two + k) + j);
      }
    }
  }
}

void print_matrix(int matrix[][MATRIX_SIZE]) {
  for (int i = 0; i < MATRIX_SIZE; i++) {
    for (int j = 0; j < MATRIX_SIZE; j++) {
      printf("%5d", *(*(matrix + i) + j));
    }
    printf("\n");
  }
}

int main(void) {
  int matrix_one[MATRIX_SIZE][MATRIX_SIZE] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
  int matrix_two[MATRIX_SIZE][MATRIX_SIZE] = {
      {9, 8, 7},
      {6, 5, 4},
      {3, 2, 1}};
  int matrix_result_seq[MATRIX_SIZE][MATRIX_SIZE] = {{0}};
  int matrix_result_par[MATRIX_SIZE][MATRIX_SIZE] = {{0}};

  double start_seq = omp_get_wtime();
  matrix_multiply_sequential(matrix_one, matrix_two, matrix_result_seq);
  double elapsed_seq = omp_get_wtime() - start_seq;

  double start_par = omp_get_wtime();
  matrix_multiply_parallel(matrix_one, matrix_two, matrix_result_par);
  double elapsed_par = omp_get_wtime() - start_par;

  printf("Sequential matrix multiplication result:\n");
  print_matrix(matrix_result_seq);
  printf("Sequential time: %.9fsg\n", elapsed_seq);
  printf("-----------------------------------\n");
  printf("Parallel matrix multiplication result:\n");
  print_matrix(matrix_result_par);
  printf("Parallel time: %.9fsg\n", elapsed_par);

  return EXIT_SUCCESS;
}
