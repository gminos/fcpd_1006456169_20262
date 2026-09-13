/**
 * @file ce_01_prime_array.c
 * @brief Count prime numbers in a dynamically allocated array of random integers
 * @author Jose Hernandez Giraldo
 * @date 2026-09-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

void fill_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    array[i] = (rand() % 100) + 1;
  }
}

int is_prime(int number) {
  if (number == 1) {
    return 1;
  }

  for (int k = 2; k * k <= number; k++) {
    if (number % k == 0) {
      return 1;
    }
  }

  return 0;
}

int count_primes(int *array, int size) {
  int count = 0;
  for (int l = 0; l < size; l++) {
    if (is_prime(array[l]) == 0) {
      count++;
    }
  }

  return count;
}

void print_array(int *array, int size) {
  printf("%sAutomatically generated array: %s[", COLOR_GREEN, COLOR_RESET);
  for (int h = 0; h < size; h++) {
    if (h == size - 1) {
      printf("%d", array[h]);
    } else {
      printf("%d, ", array[h]);
    }
  }
  printf("]\n");
}

int main(void) {
  srand(time(NULL));

  int size;
  int *array;

  printf("%sEnter array size: %s", COLOR_YELLOW, COLOR_RESET);
  scanf("%d", &size);

  array = malloc(size * sizeof(int));

  fill_array(array, size);
  print_array(array, size);

  printf("%sNumber of primes in the array: %s", COLOR_YELLOW, COLOR_RESET);
  printf("%d\n", count_primes(array, size));

  free(array);

  return EXIT_SUCCESS;
}
