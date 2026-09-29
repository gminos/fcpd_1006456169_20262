/**
 * @file ce_05_string_pointers.c
 * @brief Practice logic exercises in C focusing on pointers, double pointers,
 * and pointer arithmetic
 * @author Jose Belarmino Hernandez Giraldo
 * @date 2026-09-28
 *
 * FUNCTIONALITY:
 * This program initializes a string literal ("hola") and iterates through its
 * characters using a character pointer (char *ptr). In each iteration, it prints
 * the character (*ptr) and its memory address (ptr) until it reaches the null
 * terminator ('\0').
 *
 * EXPECTED OUTPUT:
 * h
 * 0x...
 * o
 * 0x...
 * l
 * 0x...
 * a
 * 0x...
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  const char *str = "hola";
  const char *ptr = str;

  while (*ptr != '\0') {
    printf("%c\n", *ptr);
    printf("%p\n", (void *)ptr);
    ptr++;
  }

  return EXIT_SUCCESS;
}
