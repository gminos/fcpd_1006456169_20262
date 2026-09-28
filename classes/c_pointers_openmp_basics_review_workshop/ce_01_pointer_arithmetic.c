/**
 * @file ce_01_pointer_arithmetic.c
 * @brief Practice logic exercises in C focusing on pointers, double pointers,
 * and pointer arithmetic
 * @author Jose Belarmino Hernandez Giraldo
 * @date 2026-09-28
 *
 * FUNCTIONALITY:
 * This program initializes an array of 10 integers from 1 to 10.
 * It passes the array to `print_array()`, which iterates through
 * the elements using pointer arithmetic (*(array + i)) instead of standard
 * array indexing to print them in bracketed format.
 *
 * EXPECTED OUTPUT:
 * [1,2,3,4,5,6,7,8,9,10]
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void print_array(int *array) {
  printf("[");
  for (int i = 0; i < SIZE; i++) {
    if (i == SIZE - 1) {
      printf("%d", (*(array + i)));
    } else {
      printf("%d,", (*(array + i)));
    }
  }
  printf("]");
}

int main(void) {
  int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print_array(array);

  return EXIT_SUCCESS;
}
