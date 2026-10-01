/**
 * @file omp_07_dot_product_reduction.c
 * @brief Practice logic exercises in C focusing on OpenMP parallel dot product reduction
 * and performance metrics
 * @author Jose Belarmino Hernandez Giraldo
 * @date 2026-09-29
 *
 * FUNCTIONALITY:
 * This program calculates the dot product (scalar product) of two integer vectors
 * both sequentially and in parallel using OpenMP reduction (`#pragma omp parallel for reduction(+:result)`).
 * Execution times are measured using `omp_get_wtime()`, and performance metrics
 * (Ts, Tp, Speedup, and Efficiency) are computed and printed.
 *
 * EXPECTED OUTPUT:
 * Total dot product sequential: 80
 * Total dot product parallel:   80
 * -----------------------------------
 * Ts (Secuencial): X.XXXXXX s
 * Tp (Paralelo):   X.XXXXXX s
 * Speedup:         X.XXx
 * Eficiencia:      X.XX%
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int dot_product_sequential(int *array_one, int *array_two, int size) {
  int result = 0;

  for (int i = 0; i < size; i++) {
    result += *(array_one + i) * *(array_two + i);
  }

  return result;
}

int dot_product_parallel(int *array_one, int *array_two, int size) {
  int result = 0;

#pragma omp parallel for reduction(+ : result)
  for (int i = 0; i < size; i++) {
    result += *(array_one + i) * *(array_two + i);
    printf("Thread %d of %d processing i = %d\n", omp_get_thread_num(),
           omp_get_num_threads(), i);
  }

  return result;
}

int main(void) {
  int array_one[SIZE] = {1, 2, 3, 4};
  int array_two[SIZE] = {6, 7, 8, 9};

  double start_seq = omp_get_wtime();
  int result_seq = dot_product_sequential(array_one, array_two, SIZE);
  double elapsed_seq = omp_get_wtime() - start_seq;

  double start_par = omp_get_wtime();
  int result_par = dot_product_parallel(array_one, array_two, SIZE);
  double elapsed_par = omp_get_wtime() - start_par;

  printf("Total dot product sequential: %d\n", result_seq);
  printf("Total dot product parallel:   %d\n", result_par);
  printf("-----------------------------------\n");

  int num_hilos = omp_get_max_threads();
  double speedup = elapsed_seq / elapsed_par;
  double eficiencia = speedup / num_hilos;

  printf("Ts (Secuencial): %.6f s\n", elapsed_seq);
  printf("Tp (Paralelo):   %.6f s\n", elapsed_par);
  printf("Speedup:         %.2fx\n", speedup);
  printf("Eficiencia:      %.2f%%\n", eficiencia * 100);

  return EXIT_SUCCESS;
}
