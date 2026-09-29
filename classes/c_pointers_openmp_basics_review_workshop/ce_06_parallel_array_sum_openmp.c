/**
 * @file ce_06_parallel_array_sum_openmp.c
 * @brief Practice logic exercises in C focusing on OpenMP parallel reduction
 * and execution time comparison
 * @author Jose Belarmino Hernandez Giraldo
 * @date 2026-09-29
 *
 * FUNCTIONALITY:
 * This program dynamically allocates an array of 300,000,000 integers (N =
 * 300,000,000) and populates it. It calculates the sum of all elements
 * sequentially and in parallel using OpenMP reduction (`#pragma omp parallel
 * for reduction(+:total_sum)`). Execution times for both approaches are
 * measured using `omp_get_wtime()` for performance comparison.
 *
 * EXPECTED OUTPUT:
 * Total sum sequential: 14850000000
 * Sequential time: X.XXXsg
 * -----------------------------------
 * Total sum parallel: 14850000000
 * Parallel time: X.XXXsg
 * Speedup: X.XXx
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 300000000

long long sum_array_sequential(int *array, int size) {
  long long total_sum = 0;

  for (int i = 0; i < size; i++) {
    total_sum += *(array + i);
  }

  return total_sum;
}

long long sum_array_parallel(int *array, int size) {
  long long total_sum = 0;

#pragma omp parallel for reduction(+ : total_sum)
  for (int i = 0; i < size; i++) {
    total_sum += *(array + i);
  }

  return total_sum;
}

void fill_array(int *array, int size) {
  for (int j = 0; j < size; j++) {
    *(array + j) = j % 100;
  }
}

int main(void) {
  int size = N;
  int *array = malloc(size * sizeof(int));

  if (array == NULL) {
    perror("Memory allocation failed for array");
    return EXIT_FAILURE;
  }

  fill_array(array, size);

  double start_seq = omp_get_wtime();
  long long sum_seq = sum_array_sequential(array, size);
  double elapsed_seq = omp_get_wtime() - start_seq;

  double start_par = omp_get_wtime();
  long long sum_par = sum_array_parallel(array, size);
  double elapsed_par = omp_get_wtime() - start_par;

  double speedup = elapsed_seq / elapsed_par;

  printf("Total sum sequential: %lld\n", sum_seq);
  printf("Sequential time: %.3fsg\n", elapsed_seq);
  printf("-----------------------------------\n");
  printf("Total sum parallel: %lld\n", sum_par);
  printf("Parallel time: %.3fsg\n", elapsed_par);
  printf("Speedup: %.2fx\n", speedup);

  free(array);

  return EXIT_SUCCESS;
}
