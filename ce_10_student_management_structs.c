#include <stdio.h>
#include <stdlib.h>

#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

struct Estudiante {
  int id;
  char nombre[10];
  double notas[3];
  double promedio;
  int aprobado;
};

void cantidad_estudiantes(FILE *file, int *numero_estudiantes) {
  fscanf(file, "%d", numero_estudiantes);
}

void leer_estudiantes(FILE *file, struct Estudiante *arreglo_estudiantes,
                      int *numero_estudiantes) {

  for (int i = 0; i < *numero_estudiantes; i++) {
    fscanf(file,
           "%d"
           "%s"
           "%lf"
           "%lf"
           "%lf",
           &arreglo_estudiantes[i].id, arreglo_estudiantes[i].nombre,
           &arreglo_estudiantes[i].notas[0], &arreglo_estudiantes[i].notas[1],
           &arreglo_estudiantes[i].notas[2]);
  }
}

void determinar_promedio_cada_estudiante(struct Estudiante *arreglo_estudiantes,
                                         int *numero_estudiantes) {
  double promedio = 0;
  for (int j = 0; j < *numero_estudiantes; j++) {
    for (int h = 0; h < 3; h++) {
      promedio += arreglo_estudiantes[j].notas[h];
    }
    arreglo_estudiantes[j].promedio = promedio / 3;
    promedio = 0;
  }
}

int determinar_aprobado(double *promedio) {
  return (*promedio >= 60.0) ? 0 : 1;
}

void agregar_aprobacion_estudiante(struct Estudiante *arreglo_estudiantes,
                                   int *numero_estudiantes) {
  for (int p = 0; p < *numero_estudiantes; p++) {
    arreglo_estudiantes[p].aprobado =
        determinar_aprobado(&arreglo_estudiantes[p].promedio);
  }
}

void cantidad_estudiantes_aprobados(
    const struct Estudiante *arreglo_estudiantes, const int *numero_estudiantes,
    int *cantidad_aprobados) {
  for (int k = 0; k < *numero_estudiantes; k++) {
    if (arreglo_estudiantes[k].aprobado == 0) {
      (*cantidad_aprobados)++;
    }
  }
}

void estudiantes_aprobados(struct Estudiante *arreglo_estudiantes,
                           const int *numero_estudiantes,
                           char **arreglo_estudiantes_aprobados) {
  int q = 0;
  for (int u = 0; u < *numero_estudiantes; u++) {
    if (arreglo_estudiantes[u].aprobado == 0) {
      arreglo_estudiantes_aprobados[q] = arreglo_estudiantes[u].nombre;
      q++;
    }
  }
}

void imprimir_arreglo_estudiantes_aprobados(
    char **arreglo_estudiantes_aprobados,
    const int *cantidad_estudiantes_aprobados) {
  for (int a = 0; a < *cantidad_estudiantes_aprobados; a++) {
    printf(COLOR_GREEN "Estudiante " COLOR_RESET);
    printf(COLOR_GREEN "%s " COLOR_RESET, arreglo_estudiantes_aprobados[a]);
    printf(COLOR_GREEN "aprobado\n" COLOR_RESET);
  }
  printf("-----------------------------------------------------------\n");
}

void imprimiri_estudiante_junto_promedio(struct Estudiante *arreglo_estudiantes,
                                         int *numero_estudiantes) {
  for (int f = 0; f < *numero_estudiantes; f++) {
    printf(COLOR_YELLOW "Estudiante %s, promedio %.3f\n" COLOR_RESET,
           arreglo_estudiantes[f].nombre, arreglo_estudiantes[f].promedio);
  }
  printf(
      "-------------------------------------------------------------------\n");
}

int main(void) {
  int numero_estudiantes = 0;
  int cantidad_aprobados = 0;

  FILE *file = fopen("students.txt", "r");

  cantidad_estudiantes(file, &numero_estudiantes);

  struct Estudiante *arreglo_estudiantes =
      malloc(numero_estudiantes * sizeof(struct Estudiante));

  leer_estudiantes(file, arreglo_estudiantes, &numero_estudiantes);
  determinar_promedio_cada_estudiante(arreglo_estudiantes, &numero_estudiantes);
  agregar_aprobacion_estudiante(arreglo_estudiantes, &numero_estudiantes);
  cantidad_estudiantes_aprobados(arreglo_estudiantes, &numero_estudiantes,
                                 &cantidad_aprobados);
  char **arreglo_estudiantes_aprobados =
      malloc(cantidad_aprobados * sizeof(char *));

  estudiantes_aprobados(arreglo_estudiantes, &numero_estudiantes,
                        arreglo_estudiantes_aprobados);

  imprimir_arreglo_estudiantes_aprobados(arreglo_estudiantes_aprobados,
                                         &cantidad_aprobados);
  imprimiri_estudiante_junto_promedio(arreglo_estudiantes, &numero_estudiantes);

  fclose(file);
  free(arreglo_estudiantes);
  free(arreglo_estudiantes_aprobados);

  return EXIT_SUCCESS;
}
