# 🚀 Evaluación de Rendimiento en Multiplicación de Matrices Paralelas

**Pontificia Universidad Javeriana**  
**Curso:** Sistemas Operativos  
**Profesor:** John Jairo Corredor Franco  
**Fecha:** 6 de mayo de 2025

## 👥 Integrantes

- Gabriel Jaramillo  
- Roberth Méndez  
- Luz Salazar  
- Guden Silva  
- Viviana Gómez

---

## 🧠 Introducción

Este proyecto tiene como objetivo **evaluar el rendimiento** de distintos enfoques de **programación paralela en C** aplicados a la **multiplicación de matrices cuadradas**. Se comparan tres técnicas:

- `OpenMP`
- `fork()` (procesos)
- `POSIX threads (pthread)`

Los algoritmos se ejecutan en **múltiples entornos de cómputo** y se analizan en función del número de hilos, la arquitectura del sistema y el tamaño de las matrices. Esta evaluación permite comprender el impacto del paralelismo en el rendimiento y eficiencia de aplicaciones intensivas en cómputo.

---

## 🎯 Objetivos

- Comparar el rendimiento entre algoritmos secuenciales y paralelos.
- Medir los tiempos de ejecución en diferentes arquitecturas (WSL, Ubuntu VM, Replit).
- Analizar el comportamiento de cada técnica respecto a:
  - Tamaños de matriz: `600, 800, 1000, 1200`
  - Cantidad de hilos: `1, 2, 4, 8, 16, 20`
  - Sistemas con `4, 8 y 20 hilos`

---

## 🛠️ Implementación

Se desarrollaron tres programas en **lenguaje C**:

| Algoritmo        | Descripción                                                                 |
|------------------|-----------------------------------------------------------------------------|
| `mmClasicaFork`  | Usa `fork()` para crear procesos hijos, cada uno procesa una parte de la matriz y comunica resultados por `pipe`. |
| `mmClasicaPosix` | Usa `pthread_create()` para distribuir filas entre hilos POSIX.             |
| `mmClasicaOpenMP`| Usa directivas `#pragma` de OpenMP para paralelizar el trabajo.             |

Cada programa realiza:

1. Reserva dinámica de memoria
2. Inicialización de matrices
3. Multiplicación de matrices
4. Medición de tiempo con `gettimeofday()`
5. Liberación de memoria

---

## 🧪 Método de Prueba

Para automatizar las pruebas:

- Se desarrolló el script `lanza.pl` que:
  - Ejecuta las combinaciones posibles de algoritmos, tamaños de matrices y número de hilos.
  - Repite cada combinación **30 veces**.
  - Guarda los tiempos de ejecución en archivos `.dat`.

### 🖥️ Entornos de ejecución

| Sistema          | Núcleos / Hilos | RAM    |
|------------------|------------------|--------|
| WSL              | Variable         | 3.8 MiB|
| Ubuntu VM (4)    | 4 hilos          | 11 GB  |
| Ubuntu VM (8)    | 8 hilos          | 15 GB  |
| Ubuntu VM (20)   | 20 hilos         | 64 GB  |
| Replit           | 8 hilos          | 64 GB  |

---

## 📊 Resultados esperados

Para cada ejecución se obtiene:

- Un archivo con los **tiempos de ejecución** por combinación (algoritmo + tamaño de matriz + número de hilos + sistema).
- Datos listos para análisis comparativo.

---

## 🧳 Cómo Ejecutar

```bash
incluir "chmod +x mmClasicaPosix mmClasicaFork mmClasicaOpenMP" en caso de usar archivos pre-compilados

gcc mmClasicaPosix.c mmInterfazPosix.c -o mmClasicaPosix -pthread
gcc mmClasicaFork.c mmInterfazFork.c -o mmClasicaFork
gcc mmClasicaOpenMP.c mmInterfazOpenMP.c -o mmClasicaOpenMP -fopenmp
/usr/bin/perl ./lanza.pl
