/**
 * @file ce_04_swap_pointers.c
 * @brief Practice logic exercises in C focusing on pointers, double pointers,
 * and pointer arithmetic
 * @author Jose Belarmino Hernandez Giraldo
 * @date 2026-09-28
 *
 * FUNCTIONALITY:
 * This program initializes two integer variables, `a` and `b`, with values 2 and 3.
 * It passes their memory addresses to `swap_values()`, which uses a temporary variable
 * and pointer dereferencing to swap their values in memory.
 *
 * EXPECTED OUTPUT:
 * a: 3
 * b: 2
 */

#include <stdio.h>
#include <stdlib.h>

void swap_values(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void) {
  int a = 2;
  int b = 3;

  swap_values(&a, &b);

  printf("a: %d\n", a);
  printf("b: %d\n", b);

  return EXIT_SUCCESS;
}
