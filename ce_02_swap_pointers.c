/**
 * @file ce_02_swap_pointers.c
 * @brief Swap values of two variables using pointers
 * @author Jose Hernandez Giraldo
 * @date 2026-09-13
 */

#include <stdio.h>
#include <stdlib.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

void swap_values(int *first_number, int *second_number) {
  int temp = *first_number;
  *first_number = *second_number;
  *second_number = temp;
}

void print_values(int *first_number, int *second_number) {
  printf(COLOR_GREEN "Value of a: " COLOR_RESET);
  printf("%d\n", *first_number);
  printf(COLOR_GREEN "Value of b: " COLOR_RESET);
  printf("%d\n", *second_number);
}

void get_values(int *first_number, int *second_number) {
  printf(COLOR_YELLOW "Enter the value of a: " COLOR_RESET);
  scanf("%d", first_number);

  printf(COLOR_YELLOW "Enter the value of b: " COLOR_RESET);
  scanf("%d", second_number);

  printf("----------------------------\n");
}

int main(void) {
  int first_number;
  int second_number;

  get_values(&first_number, &second_number);
  swap_values(&first_number, &second_number);
  print_values(&first_number, &second_number);

  return EXIT_SUCCESS;
}

