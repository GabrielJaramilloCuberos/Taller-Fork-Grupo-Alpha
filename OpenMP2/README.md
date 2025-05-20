
# OpenMP para la multiplicación de matrices

## 📘 Pontificia Universidad Javeriana  
**Clase:** Sistemas Operativos  
**Estudiante:** Gabriel Jaramillo  
**Fecha:** 20 de mayo de 2025  
**Tema:** Evaluación de uso de OpenMP  

---

## 📄 Descripción del Proyecto

Este proyecto implementa la **multiplicación de matrices en C** utilizando la biblioteca **OpenMP** para aprovechar el paralelismo en sistemas multiprocesador.

El objetivo es comparar el rendimiento de una implementación paralela respecto a una secuencial y explorar el uso eficiente de hilos en la programación con OpenMP.

---

## ⚙️ Estructura del Proyecto

El proyecto se compone de tres archivos principales:

- `mmClasicaOpenMP.c`: Contiene la función principal del programa, donde se inicializan matrices, se ejecuta la multiplicación paralela y se mide el tiempo de ejecución.
- `mmInterfazOpenMP.c`: Define las funciones auxiliares como inicialización, impresión, medición de tiempo y multiplicación paralela.
- `mmInterfazOpenMP.h`: Header, declara las funciones usadas en los archivos fuente.

---

## 🧪 Funcionalidades

- Inicialización de matrices A y B con valores definidos.
- Multiplicación de matrices en paralelo utilizando directivas OpenMP:
  - `#pragma omp parallel`
  - `#pragma omp for`
  - `#pragma omp private`
- Medición del tiempo de ejecución con `gettimeofday`.
- Impresión de matrices si el tamaño es menor a 9.
- Liberación de memoria dinámica.

---

## 🚀 Instrucciones de Compilación y Ejecución

### 💻 Compilación

```bash
gcc -o openMP mmClasicaOpenMP.c mmInterfazOpenMP.c -fopenmp
```

### 🏃‍♂️Ejecución

```bash
./openMP
```

## Conclusiones

- El uso de OpenMP permite una ejecución más rápida de la multiplicación de matrices al aprovechar múltiples núcleos de procesamiento.
- La paralelización mejora significativamente el rendimiento en comparación con la implementación secuencial.
- La gestión adecuada de variables locales y la distribución de trabajo entre hilos son clave para evitar conflictos y asegurar resultados correctos.
- La medición del tiempo de ejecución permite evaluar el rendimiento de la implementación paralela.
- OpenMP es una herramienta poderosa para optimizar el rendimiento de aplicaciones que requieren cálculos intensivos, como la multiplicación de matrices.
- El programa, efectivamente, realiza la multiplicación de matrices de manera eficiente y escalable, aprovechando la capacidad de procesamiento paralelo de los sistemas modernos.
