/**
 * @file omp_07_dot_product_reduction.c
 * @brief Practice logic exercises in C focusing on OpenMP parallel dot product reduction
 * @author Jose Belarmino Hernandez Giraldo
 * @date 2026-09-29
 *
 * FUNCTIONALITY:
 * This program calculates the dot product (scalar product) of two integer vectors
 * of size 4 using OpenMP parallel reduction (`#pragma omp parallel for reduction(+:result)`).
 * Each thread processes a portion of the element-wise multiplications using pointer
 * arithmetic, printing its thread ID and current index.
 *
 * EXPECTED OUTPUT:
 * Thread X of Y processing i = ...
 * ...
 * Dot product result: 80
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int dot_product(int *array_one, int *array_two) {
  int result = 0;

#pragma omp parallel for reduction(+ : result)
  for (int i = 0; i < SIZE; i++) {
    result += *(array_one + i) * *(array_two + i);
    printf("Thread %d of %d processing i = %d\n", omp_get_thread_num(),
           omp_get_num_threads(), i);
  }

  return result;
}

int main(void) {
  int array_one[SIZE] = {1, 2, 3, 4};
  int array_two[SIZE] = {6, 7, 8, 9};

  printf("Dot product result: %d\n", dot_product(array_one, array_two));

  return EXIT_SUCCESS;
}
