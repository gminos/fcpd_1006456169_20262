#include <stdio.h>
#include <stdlib.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"

void get_numerical_score(double *score) {
  printf(COLOR_YELLOW "Enter a numerical score (0 - 100): " COLOR_RESET);
  scanf("%lf", score);
  printf("---------------------------------------\n");
}

int is_valid_score(double score) { return (score >= 0.0 && score <= 100.0); }

char get_letter_grade(double score) {
  if (score >= 90.0 && score <= 100.0) {
    return 'A';
  } else if (score >= 80.0 && score < 90.0) {
    return 'B';
  } else if (score >= 70.0 && score < 80.0) {
    return 'C';
  } else if (score >= 60.0 && score < 70.0) {
    return 'D';
  } else {
    return 'F';
  }
}

void print_grade_result(double score) {
  if (!is_valid_score(score)) {
    printf(
        COLOR_RED
        "Invalid score, Please enter a value between 0 and 100\n" COLOR_RESET);
    return;
  }

  char letter_grade = get_letter_grade(score);
  printf(COLOR_GREEN "Numerical score: %.2f\n" COLOR_RESET, score);
  printf(COLOR_GREEN "Letter grade: %c\n" COLOR_RESET, letter_grade);
}

int main(void) {
  double score;

  get_numerical_score(&score);
  print_grade_result(score);

  return EXIT_SUCCESS;
}
