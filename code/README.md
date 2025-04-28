# Proyecto: Algoritmos de Ordenamiento y Multiplicación de Matrices

Este proyecto contiene implementaciones en C/C++ (o tu lenguaje elegido) de diferentes algoritmos de ordenamiento de arreglos unidimensionales y la multiplicación de matrices. El objetivo es comparar su desempeño, entender su complejidad y proporcionar herramientas de pruebas y generación de datos.

---

## 📁 Estructura del repositorio

```bash
├── README.md                 
├── multiplicacion_matrices      
│   └── algorithms               # Implementaciones de algoritmos de multiplicación
│       ├── naive.cpp            
│       ├── strassen.cpp         
│       └── matrix_multiplication.cpp
│   └── data                     # Carpeta para datos generados y resultados
│       ├── matrix_input         # Archivos de entrada para matrices
│       ├── matrix_output        # Archivos de salida para matrices multiplicadas
│       ├── measurements         # Archivos con mediciones de tiempos de ejecución
│       └── plots                # Gráficos generados a partir de los datos
│   └── scripts                  # Scripts auxiliares
│       ├── matrix_generator.py  # Generador de matrices aleatorias
│       └── plot_generator.sh    # Generador de graficos a partir de datos generados 
│   ├── Makefile                 
│   ├── matrix_multiplication.cpp # Programa principal de multiplicación
├── sorting
│   └── algorithms                # Implementaciones de algoritmos de sorting
│       ├── mergesort.cpp         
│       ├── quicksort.cpp          
│       ├── selectionsort.cpp          
│       └── sort.cpp     
│   └── data                      # Carpeta para datos generados y resultados
│       ├── array_input           # Archivos de entrada para arreglos
│       ├── array_output          # Archivos de salida para arreglos ordenados
│       ├── measurements          # Archivos con mediciones de tiempos de ejecución
│       └── plots                 # Gráficos generados a partir de los datos
│   └── scripts                   # Scripts auxiliares
│       ├── array_generator.py    # Generador de arreglos
│       └── plot_generator.py     # Gráficos generados a partir de los datos
│   ├── makefile                  # Programa principal de ordenamiento
│   ├── sorting.cpp               # Archivo de compilación
```

# Documentacion

Estas carpetas contienen las  implementaciones en C/C++ de los  diferentes algoritmos de ordenamiento de arreglos unidimensionales (SelectionSort Qu)y la multiplicación de matrices (Naive y Strassen). El objetivo es comparar su desempeño, entender su complejidad y proporcionar herramientas de pruebas y generación de datos.


---

## 🔢 Multiplicación de matrices

En esta sección se implementa la multiplicación de dos matrices de tamaño `M × M`.

### Programa principal

- **Archivo:** `matrix_multiplication/matrix_multiplication.cpp`
- **Descripción:** Lee dos matrices desde archivos de entrada, las multiplica y almacena el resultado y tiempos en un terceros archivos.

- **Uso:**
Desde ca carpeta code se deje ejecutrar:

  ```bash
  cd matrix_multiplication
  make
  ```
Esto generara los archivos de salida tales como resultado de la mutiplicacion de matrices en ```bash code/matrix_multiplication/data/matrix_output ```

### Scripts

En la carpeta `matrix_multiplication/scripts` se incluyen herramientas para facilitar pruebas:

- **`matrix_generator.py`**
  - Genera dos matrices aleatorias de dimensiones dadas.
  - Uso:
    ```bash
    python3 matrix_generator.py
    ```
- **`plot_generator.py`**
    - Genera gráficos a partir de los datos de tiempos de ejecución registrados.
    - Configurable para diferentes algoritmos y tamaños de entrada.
    - Uso:
        Este archivo se ejecutara junto con el archivo principal a la hora de realizar el comando make
---

## Ordenamiento de arreglo unidimensional

Implementaciones de diferentes algoritmos de ordenamiento para vectores de tamaño `N`.

### Programa principal

- **Archivo:** `sorting/sorting.cpp`
- **Descripción:** Carga un arreglo de tamaño `N` (desde archivo , aplica cada algoritmo de ordenamiento (Selection Sort, Quick Sort, Merge Sort) y muestra o escribe el arreglo ordenado.
- **Uso:**
  ```bash
  cd sorting
  make
  ```

### Scripts

En la carpeta `sorting/scripts` se incluyen:

- **`array_generator.py`**
  - Crea archivos de arreglos aleatorios con diferentes distribuciones (ordenados, inverso, aleatorio).
  - Uso:
    ```bash
    python3 array_generator.py
    ```
- **`plot_generator.py`**
    - Genera gráficos comparativos de tiempos de ejecución para diferentes algoritmos y tamaños de entrada.
    - Uso:
        Este archivo se ejecutara atuomaticamente depsues de ejeructar el comando make para el archivo principal
        ```bash
        cd sorting
        python3 plot_generator.py
        ```


