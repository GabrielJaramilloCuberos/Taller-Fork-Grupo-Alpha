/**************************************************************************************
-Nombre: Gabriel Jaramillo Cuberos
-Fecha: 13 de mayo, 2025
-Materia: Sistemas Operativos
-Tema: Programacion paralela, introduccion a OpenMP
-Resumen: Programa que crea hilos de ejecucion para cada core imprime cadena de caracteres por cada llamada
**************************************************************************************/

#include <stdio.h> // Libreria para entrada y salida de datos
#include <omp.h> // Libreria para programacion paralela
#include <stdlib.h> // Libreria para funciones de utilidad

int main(int argc, char *argv[]){
  printf("OpenMP ejecutando con %d hilos\n", omp_get_max_threads()); // Imprime el numero de hilos que se ejecutaran en paralelo
  #pragma omp parallel // Directiva para crear hilos de ejecucion en paralelo
  {
    printf("Hello World desde el thread %d\n", omp_get_thread_num()); // Imprime el numero de hilo que esta ejecutando la instruccion
  }
  return 0;
}
