/**
 * @file ce_02_array_sum_pointers.c
 * @brief Practice logic exercises in C focusing on pointers, double pointers,
 * and pointer arithmetic
 * @author Jose Belarmino Hernandez Giraldo
 * @date 2026-09-28
 *
 * FUNCTIONALITY:
 * This program initializes an array of 10 integers from 1 to 10.
 * It passes the array and a pointer to an accumulator variable to `sum_array()`,
 * which calculates the sum of all elements using pointer arithmetic (*(array + i))
 * and dereferences the accumulator pointer to update the total sum.
 *
 * EXPECTED OUTPUT:
 * Result: 55
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void sum_array(int *array, int *sum_result) {
  for (int i = 0; i < SIZE; i++) {
    *sum_result += (*(array + i));
  }
}

int main(void) {
  int sum_result = 0;
  int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  sum_array(array, &sum_result);

  printf("Result: %d\n", sum_result);

  return EXIT_SUCCESS;
}
