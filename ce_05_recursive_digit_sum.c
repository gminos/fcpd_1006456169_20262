/**
 * @file ce_05_recursive_digit_sum.c
 * @brief Calculate the sum of digits of a number recursively
 * @author Jose Hernandez Giraldo
 * @date 2026-09-13
 */

#include <stdio.h>
#include <stdlib.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"
#define ZERO 0

void get_value(int *number) {
  printf(COLOR_YELLOW
         "Enter a number to calculate the sum of its digits: " COLOR_RESET);
  scanf("%d", number);

  printf("---------------------------------------------------\n");
}

int sum_digits(int number, int accumulator) {
  if (number / 10 == 0) {
    return accumulator + number;
  }

  accumulator += number % 10;
  number /= 10;

  return sum_digits(number, accumulator);
}

void print_result(const int *number) {
  printf(COLOR_GREEN "Sum of the digits: " COLOR_RESET);
  printf("%d\n", sum_digits(*number, ZERO));
}

int main(void) {
  int number;
  get_value(&number);
  print_result(&number);

  return EXIT_SUCCESS;
}

