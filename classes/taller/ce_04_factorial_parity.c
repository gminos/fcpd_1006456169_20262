/**
 * @file ce_04_factorial_parity.c
 * @brief Calculate factorial of a number and determine its parity
 * @author Jose Hernandez Giraldo
 * @date 2026-09-13
 */

#include <stdio.h>
#include <stdlib.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

void get_value(int *number) {
  printf(COLOR_YELLOW "Enter a number to calculate its factorial: " COLOR_RESET);
  scanf("%d", number);

  printf("---------------------------------------------------\n");
}

int calculate_factorial(const int *number) {
  int result = 1;
  for (int i = 1; i <= *number; i++) {
    result *= i;
  }

  printf(COLOR_GREEN "Factorial of the entered number: " COLOR_RESET);
  printf("%d\n", result);

  return result;
}

void check_parity(int number) {
  number % 2 == 0
      ? printf(COLOR_GREEN "The factorial is an even number\n" COLOR_RESET)
      : printf(COLOR_GREEN "The factorial is an odd number\n" COLOR_RESET);
}

int main(void) {
  int number;

  get_value(&number);
  check_parity(calculate_factorial(&number));

  return EXIT_SUCCESS;
}

