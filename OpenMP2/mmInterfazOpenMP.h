/*********************************************************************************************************************
-Pontificia Universidad Javeriana
-Nombre: Gabriel Jaramillo
-Clase: Sistemas Operativos
-Fecha: 2025-05-20
-Tema: Evaluación de uso de OpenMP
-Descripción: 
	Este header define funciones para la multiplicación de matrices utilizando OpenMP.
*********************************************************************************************************************/

#include <stdio.h>      // Entrada y salida estándar
#include <stdlib.h>     // Funciones generales: malloc, free, atoi, etc.
#include <string.h>     // Funciones para manipulación de cadenas
#include <time.h>       // Manejo de tiempo para semilla aleatoria
#include <sys/time.h>   // Estructuras y funciones para medir tiempo con microsegundos
#include <omp.h>        // Biblioteca para programación paralela con OpenMP

/*
 * Función que registra el tiempo de inicio de la ejecución
 */
void InicioMuestra();

/*
 * Función que registra el tiempo de fin y calcula el tiempo total en microsegundos
 */
void FinMuestra();

/*
 * Función que imprime una matriz si su tamaño es menor a 9
 * Parámetros:
 *   - matrix: puntero a la matriz a imprimir
 *   - D: dimensión de la matriz
 */
void impMatrix(size_t *matrix, int D);

/*
 * Función que inicializa dos matrices con multiplos de 2
 * Parámetros:
 *   - m1: puntero a la primera matriz (matriz A)
 *   - m2: puntero a la segunda matriz (matriz B)
 *   - D: dimensión de las matrices
 */
void iniMatrix(size_t *m1, size_t *m2, int D);

/*
 * Función que realiza la multiplicación de matrices de forma paralela usando OpenMP
 * Parámetros:
 *   - mA: puntero a la matriz A
 *   - mB: puntero a la matriz B
 *   - mC: puntero a la matriz resultado C
 *   - D: dimensión de las matrices
 */
void multiMatrix(size_t *mA, size_t *mB, size_t *mC, int D);