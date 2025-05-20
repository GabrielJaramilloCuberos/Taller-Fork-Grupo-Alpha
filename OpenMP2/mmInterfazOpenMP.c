/*********************************************************************************************************************
-Pontificia Universidad Javeriana
-Nombre: Gabriel Jaramillo
-Clase: Sistemas Operativos
-Fecha: 2025-05-20
-Tema: Evaluación de uso de OpenMP
-Descripción: 
	Esta interfaz define funciones para la multiplicación de matrices utilizando OpenMP.
	Se privatizan variables locales para evitar conflictos entre hilos.
	Se mide el tiempo de ejecución y se imprimen matrices solo si su tamaño es menor a 9.
*********************************************************************************************************************/

#include "mmInterfazOpenMP.h" // Incluye la interfaz de OpenMP para la multiplicación de matrices

// Variables globales para almacenar el tiempo de inicio y fin de ejecución
struct timeval inicio, fin;

void InicioMuestra(){
	gettimeofday(&inicio, (void *)0);
}

void FinMuestra(){
	gettimeofday(&fin, (void *)0);     // Almacena el tiempo actual en 'fin'
	fin.tv_usec -= inicio.tv_usec;     // Calcula diferencia en microsegundos
	fin.tv_sec  -= inicio.tv_sec;      // Calcula diferencia en segundos
	double tiempo = (double) (fin.tv_sec*1000000 + fin.tv_usec); 
	printf("%9.0f \n", tiempo);        // Imprime el tiempo transcurrido
}

void impMatrix(size_t *matrix, int D){
	printf("\n");
	if(D < 9){ 
		for(int i=0; i<D*D; i++){
			if(i%D==0) printf("\n");
			printf("%zu ", matrix[i]);    
		}
		printf("\n**-----------------------------**\n");
	}
}

void iniMatrix(size_t *m1, size_t *m2, int D){
	for(int i=0; i<D*D; i++, m1++, m2++){
		*m1 = i*2;    // Asigna valor a m1
		*m2 = i+2;    // Asigna valor a m2
	}
}

void multiMatrix(size_t *mA, size_t *mB, size_t *mC, int D) {
    size_t Suma, *pA, *pB;  // Variables locales para almacenar la suma parcial y los punteros a las matrices A y B

    #pragma omp parallel private(Suma, pA, pB)  // Se asegura de que cada hilo tenga sus propias variables
    {
        #pragma omp for  // Distribuye el bucle de filas entre los hilos disponibles
        for (int i = 0; i < D; i++) {  // Recorre las filas de la matriz A
            for (int j = 0; j < D; j++) {  // Recorre las columnas de la matriz B
                pA = mA + i * D;  // Apunta al inicio de la fila i de la matriz A
                pB = mB + j;      // Apunta a la columna j de la matriz B
                Suma = 0.0;  // Inicializa la suma acumulada para la multiplicación de la fila i y columna j

                // Recorre los elementos de la fila de A y la columna de B
                for (int k = 0; k < D; k++, pA++, pB += D) {
                    Suma += (*pA) * (*pB);  // Realiza la multiplicación y acumula en Suma
                }

                mC[i * D + j] = Suma;  // Asigna el resultado de la multiplicación en la posición correspondiente de C
            }
        }
    }
}