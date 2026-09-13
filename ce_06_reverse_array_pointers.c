#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

void fill_array_with_random_values(int *array, int size) {
  for (int i = 0; i < size; i++) {
    array[i] = (rand() % 100) + 1;
  }
}

void print_array(const int *array, int size) {
  printf("[");
  for (int j = 0; j < size; j++) {
    if (j == size - 1) {
      printf("%d", array[j]);
    } else {
      printf("%d, ", array[j]);
    }
  }
  printf("]\n");
}

void get_array_size(int *size) {
  printf(COLOR_YELLOW "Enter array size: " COLOR_RESET);
  scanf("%d", size);
  printf("---------------------------------------\n");
}

void reverse_array(const int *array, int size, int *reversed_array) {
  int limit = 0;
  while (limit < size) {
    *(reversed_array++) = *(array + (size - limit - 1));
    limit++;
  }
}

int main(void) {
  srand(time(NULL));
  int size;

  get_array_size(&size);
  int *array = malloc(size * sizeof(int));
  int *reversed_array = malloc(size * sizeof(int));

  fill_array_with_random_values(array, size);
  printf(COLOR_GREEN "Generated array: " COLOR_RESET);
  print_array(array, size);

  reverse_array(array, size, reversed_array);
  printf(COLOR_GREEN "Reversed array: " COLOR_RESET);
  print_array(reversed_array, size);

  free(array);
  free(reversed_array);

  return EXIT_SUCCESS;
}
