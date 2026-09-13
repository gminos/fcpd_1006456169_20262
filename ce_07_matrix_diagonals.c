#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

void get_matrix_size(int *size) {
  printf(COLOR_YELLOW "Enter matrix size (N x N): " COLOR_RESET);
  scanf("%d", size);
  printf("---------------------------------------\n");
}

void fill_matrix_with_random_values(int **matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[i][j] = (rand() % 100) + 1;
    }
  }
}

void print_matrix(int **matrix, int size) {
  printf(COLOR_GREEN "Generated Matrix (%dx%d):\n" COLOR_RESET, size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
  printf("---------------------------------------\n");
}

int calculate_main_diagonal_sum(int **matrix, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += matrix[i][i];
  }
  return sum;
}

int calculate_secondary_diagonal_sum(int **matrix, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += matrix[i][size - 1 - i];
  }
  return sum;
}

void compare_diagonals(int main_sum, int secondary_sum) {
  printf("Main diagonal sum: %d\n", main_sum);
  printf("Secondary diagonal sum: %d\n", secondary_sum);
  if (main_sum > secondary_sum) {
    printf(COLOR_GREEN "The main diagonal has a greater sum\n" COLOR_RESET);
  } else if (secondary_sum > main_sum) {
    printf(COLOR_GREEN
           "The secondary diagonal has a greater sum\n" COLOR_RESET);
  } else {
    printf(COLOR_GREEN "Both diagonal sums are equal\n" COLOR_RESET);
  }
}

int main(void) {
  srand(time(NULL));
  int size;

  get_matrix_size(&size);

  int **matrix = malloc(size * sizeof(int *));

  for (int i = 0; i < size; i++) {
    matrix[i] = malloc(size * sizeof(int));
    if (matrix[i] == NULL) {
      for (int k = 0; k < i; k++) {
        free(matrix[k]);
      }
      free(matrix);
      return EXIT_FAILURE;
    }
  }

  fill_matrix_with_random_values(matrix, size);
  print_matrix(matrix, size);

  int main_sum = calculate_main_diagonal_sum(matrix, size);
  int secondary_sum = calculate_secondary_diagonal_sum(matrix, size);

  compare_diagonals(main_sum, secondary_sum);

  for (int i = 0; i < size; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return EXIT_SUCCESS;
}
