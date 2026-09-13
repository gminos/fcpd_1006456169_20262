/**
 * @file ce_10_student_management_structs.c
 * @brief Student management system using structs, dynamic memory, and file I/O
 * @author Jose Hernandez Giraldo
 * @date 2026-09-13
 */

#include <stdio.h>
#include <stdlib.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

struct Student {
  int id;
  char name[10];
  double grades[3];
  double average;
  int is_passed;
};

void get_student_count(FILE *file, int *student_count) {
  fscanf(file, "%d", student_count);
}

void read_students(FILE *file, struct Student *students,
                   const int *student_count) {
  for (int i = 0; i < *student_count; i++) {
    fscanf(file,
           "%d"
           "%s"
           "%lf"
           "%lf"
           "%lf",
           &students[i].id, students[i].name,
           &students[i].grades[0], &students[i].grades[1],
           &students[i].grades[2]);
  }
}

void calculate_student_averages(struct Student *students,
                                const int *student_count) {
  double sum = 0;
  for (int j = 0; j < *student_count; j++) {
    for (int h = 0; h < 3; h++) {
      sum += students[j].grades[h];
    }
    students[j].average = sum / 3.0;
    sum = 0;
  }
}

int check_if_passed(const double *average) {
  return (*average >= 60.0) ? 0 : 1;
}

void set_students_pass_status(struct Student *students,
                              const int *student_count) {
  for (int p = 0; p < *student_count; p++) {
    students[p].is_passed =
        check_if_passed(&students[p].average);
  }
}

void count_passed_students(const struct Student *students,
                            const int *student_count,
                            int *passed_count) {
  for (int k = 0; k < *student_count; k++) {
    if (students[k].is_passed == 0) {
      (*passed_count)++;
    }
  }
}

void get_passed_students_names(const struct Student *students,
                                const int *student_count,
                                char **passed_students_names) {
  int idx = 0;
  for (int u = 0; u < *student_count; u++) {
    if (students[u].is_passed == 0) {
      passed_students_names[idx] = (char *)students[u].name;
      idx++;
    }
  }
}

void print_passed_students(char **passed_students_names,
                            const int *passed_count) {
  for (int a = 0; a < *passed_count; a++) {
    printf(COLOR_GREEN "Student %s passed\n" COLOR_RESET,
           passed_students_names[a]);
  }
  printf("-----------------------------------------------------------\n");
}

void print_students_with_averages(const struct Student *students,
                                  const int *student_count) {
  for (int f = 0; f < *student_count; f++) {
    printf(COLOR_YELLOW "Student %s, average: %.3f\n" COLOR_RESET,
           students[f].name, students[f].average);
  }
  printf(
      "-------------------------------------------------------------------\n");
}

int main(void) {
  int student_count = 0;
  int passed_count = 0;

  FILE *file = fopen("students.txt", "r");
  if (file == NULL) {
    printf("Error opening students.txt file.\n");
    return EXIT_FAILURE;
  }

  get_student_count(file, &student_count);

  struct Student *students =
      malloc(student_count * sizeof(struct Student));
  if (students == NULL) {
    fclose(file);
    return EXIT_FAILURE;
  }

  read_students(file, students, &student_count);
  calculate_student_averages(students, &student_count);
  set_students_pass_status(students, &student_count);
  count_passed_students(students, &student_count, &passed_count);

  char **passed_students_names =
      malloc(passed_count * sizeof(char *));
  if (passed_students_names == NULL) {
    free(students);
    fclose(file);
    return EXIT_FAILURE;
  }

  get_passed_students_names(students, &student_count,
                            passed_students_names);

  print_passed_students(passed_students_names, &passed_count);
  print_students_with_averages(students, &student_count);

  fclose(file);
  free(students);
  free(passed_students_names);

  return EXIT_SUCCESS;
}
