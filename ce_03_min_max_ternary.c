#include <stdio.h>
#include <stdlib.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

void get_values(int *first_number, int *second_number, int *third_number) {
  printf(COLOR_YELLOW "Enter the first value: " COLOR_RESET);
  scanf("%d", first_number);

  printf(COLOR_YELLOW "Enter the second value: " COLOR_RESET);
  scanf("%d", second_number);

  printf(COLOR_YELLOW "Enter the third value: " COLOR_RESET);
  scanf("%d", third_number);

  printf("---------------------------------------------------\n");
}

void print_max_value(int *first_number, int *second_number, int *third_number) {
  int max_value =
      (*first_number > *second_number)
          ? ((*first_number > *third_number) ? *first_number : *third_number)
          : ((*second_number > *third_number) ? *second_number : *third_number);

  printf(COLOR_GREEN "Maximum value: " COLOR_RESET);
  printf("%d\n", max_value);
}

void print_min_value(int *first_number, int *second_number, int *third_number) {
  int min_value =
      (*first_number < *second_number)
          ? ((*first_number < *third_number) ? *first_number : *third_number)
          : ((*second_number < *third_number) ? *second_number : *third_number);

  printf(COLOR_GREEN "Minimum value: " COLOR_RESET);
  printf("%d\n", min_value);
}

int main(void) {
  int first_number;
  int second_number;
  int third_number;

  get_values(&first_number, &second_number, &third_number);
  print_max_value(&first_number, &second_number, &third_number);
  print_min_value(&first_number, &second_number, &third_number);

  return EXIT_SUCCESS;
}
