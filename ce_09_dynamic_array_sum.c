#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR_YELLOW "\033[33m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

void get_array_size(int *size) {
  printf(COLOR_YELLOW "Enter array size: " COLOR_RESET);
  scanf("%d", size);
  printf("---------------------------------------\n");
}

int calculate_array_sum(const int *array, int size) {
  int total_sum = 0;
  for (int i = 0; i < size; i++) {
    total_sum += array[i];
  }

  return total_sum;
}

void fill_array(int *array, int size) {
  for (int j = 0; j < size; j++) {
    array[j] = (rand() % 100) + 1;
  }
}

void print_array(const int *array, int size) {
  printf("%sGenerated array: %s[", COLOR_GREEN, COLOR_RESET);
  for (int h = 0; h < size; h++) {
    if (h == size - 1) {
      printf("%d", array[h]);
    } else {
      printf("%d, ", array[h]);
    }
  }
  printf("]\n");
}

void print_result(const int *array, int size) {
  int total_sum = calculate_array_sum(array, size);
  printf(COLOR_GREEN "Sum of the array: " COLOR_RESET);
  printf("%d\n", total_sum);
}

int main(void) {
  srand(time(NULL));

  int size;
  get_array_size(&size);

  int *array = malloc(size * sizeof(int));

  fill_array(array, size);
  print_array(array, size);
  print_result(array, size);

  free(array);

  return EXIT_SUCCESS;
}
