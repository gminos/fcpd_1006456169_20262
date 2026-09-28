/**
 * @file ce_03_matrix_pointer_to_pointer.c
 * @brief Practice logic exercises in C focusing on pointers, double pointers,
 * and pointer arithmetic
 * @author Jose Belarmino Hernandez Giraldo
 * @date 2026-09-28
 *
 * FUNCTIONALITY:
 * This program dynamically allocates a 3x3 2D matrix using a pointer to pointer
 * (int **matrix). It populates the matrix elements using double pointer
 * arithmetic
 * (*(*(matrix + i) + j)), prints the matrix in a formatted layout, and safely
 * frees all allocated memory (rows and row pointer array).
 *
 * EXPECTED OUTPUT:
 *    0   1   2
 *    1   2   3
 *    2   3   4
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void fill_matrix(int **matrix) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      *(*(matrix + i) + j) = (i + j) % 100;
    }
  }
}

void print_matrix(int **matrix) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%4d", *(*(matrix + i) + j));
    }
    printf("\n");
  }
}

int main(void) {
  int **matrix = malloc(SIZE * sizeof(int *));

  if (matrix == NULL) {
    printf("Failed to allocate memory for matrix");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < SIZE; i++) {
    *(matrix + i) = malloc(SIZE * sizeof(int));

    if (*(matrix + i) == NULL) {
      printf("Failed to allocate memory for matrix row");
      for (int k = 0; k < i; k++) {
        free(*(matrix + k));
      }

      free(matrix);
      return EXIT_FAILURE;
    }
  }

  fill_matrix(matrix);
  print_matrix(matrix);

  for (int i = 0; i < SIZE; i++) {
    free(*(matrix + i));
  }

  free(matrix);

  return EXIT_SUCCESS;
}
