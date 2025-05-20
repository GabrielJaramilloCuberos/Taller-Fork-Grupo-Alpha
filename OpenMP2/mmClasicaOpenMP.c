/***************************************************************************************************************************************************************
-Pontificia Universidad Javeriana
-Nombre: Gabriel Jaramillo
-Clase: Sistemas Operativos
-Fecha: 2025-05-20
-Tema: Evaluación de uso de OpenMP
-Descripción: 
	Este programa realiza la multiplicación de matrices utilizando OpenMP para paralelizar el proceso.
	Se inicializan dos matrices con valores específicos y se multiplica en paralelo, midiendo el tiempo de ejecución.
	Al final, se imprimen las matrices y se libera la memoria asignada.
	En este programa, la directriz #pragma omp parallel se utiliza para crear un equipo de hilos que ejecutan la multiplicación de matrices.
	La directriz #pragma omp for distribuye el bucle de filas entre los hilos disponibles, permitiendo que cada hilo procese una fila diferente de la matriz A.
	La directriz #pragma omp private asegura que cada hilo tenga su propia copia de las variables locales Suma, pA y pB, evitando conflictos entre hilos.
	La función multiMatrix realiza la multiplicación de matrices de forma paralela utilizando OpenMP.

-Conclusiones:
	El uso de OpenMP permite una ejecución más rápida de la multiplicación de matrices al aprovechar múltiples núcleos de procesamiento.
	La paralelización mejora significativamente el rendimiento en comparación con la implementación secuencial.
	La gestión adecuada de variables locales y la distribución de trabajo entre hilos son clave para evitar conflictos y asegurar resultados correctos.
	La medición del tiempo de ejecución permite evaluar el rendimiento de la implementación paralela.
	OpenMP es una herramienta poderosa para optimizar el rendimiento de aplicaciones que requieren cálculos intensivos, como la multiplicación de matrices.
***************************************************************************************************************************************************************/

#include "mmInterfazOpenMP.h" // Incluye la interfaz de OpenMP para la multiplicación de matrices

/*
 * Función principal que:
 * 1. Valida argumentos de entrada (tamaño y número de hilos)
 * 2. Reserva memoria e inicializa matrices
 * 3. Realiza la multiplicación de matrices en paralelo 
 * 4. Mide el tiempo de ejecución
 * 5. Imprime las matrices si son pequeñas
 */
int main(int argc, char *argv[]){
	if(argc < 3){
		printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
		exit(0);
	}

	int N = atoi(argv[1]);  // Dimensión de la matriz
	int TH = atoi(argv[2]); // Número de hilos a utilizar

	// Reservar memoria para matrices A, B y C 
	size_t *matrixA  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixB  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixC  = (size_t *)calloc(N*N, sizeof(size_t));

	srand(time(NULL));      // Inicializa semilla para números aleatorios 

	omp_set_num_threads(TH); // Establece número de hilos a usar con OpenMP

	iniMatrix(matrixA, matrixB, N); // Inicializa las matrices A y B

	impMatrix(matrixA, N);  // Imprime matriz A si es pequeña
	impMatrix(matrixB, N);  // Imprime matriz B si es pequeña

	InicioMuestra();              // Inicia cronómetro
	multiMatrix(matrixA, matrixB, matrixC, N); // Multiplica matrices
	FinMuestra();                 // Finaliza cronómetro e imprime el tiempo

	impMatrix(matrixC, N);        // Imprime matriz resultado si es pequeña

	free(matrixA);                // Libera memoria asignada a matriz A
	free(matrixB);                // Libera memoria asignada a matriz B
	free(matrixC);                // Libera memoria asignada a matriz C
	
	return 0;
}