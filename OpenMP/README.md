# 🧵 Introducción a OpenMP

## 👤 Autor
**Gabriel Jaramillo Cuberos**

## 📅 Fecha
**13 de mayo, 2025**

## 📚 Materia
**Sistemas Operativos**

## 🧠 Tema
**Programación paralela - Introducción a OpenMP**

---

## 📝 Descripción

Este proyecto es un ejemplo básico de uso de OpenMP (Open Multi-Processing), una API que permite a los programas C/C++ y Fortran aprovechar múltiples núcleos del procesador mediante programación paralela con hilos (`threads`).

El programa crea una región paralela y ejecuta un simple mensaje de saludo desde cada hilo activo, utilizando la cantidad de núcleos disponibles en la máquina.

---



---

> La cantidad de hilos puede variar dependiendo del procesador y la configuración de OpenMP.

---

## ⚒️ Funciones principales

| Función | Descripción |
|--------|-------------|
| `omp_get_max_threads()` | Retorna el número máximo de hilos que OpenMP usará si no se especifica otro número. |
| `omp_get_thread_num()` | Retorna el ID del hilo actual dentro de la región paralela. |
| `#pragma omp parallel` | Indica el inicio de una región de código que debe ejecutarse en paralelo por múltiples hilos. |

---

