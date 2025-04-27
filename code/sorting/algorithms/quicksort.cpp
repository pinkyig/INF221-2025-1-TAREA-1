#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

// Umbral para usar insertion sort en subarreglos pequeños
static const int INSERTION_SORT_THRESHOLD = 16;

// Ordenación por inserción para subarreglos de tamaño reducido
template<typename T>
void insertionSort(T arr[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Quicksort robusto con pivote mediano-de-tres, eliminación de recursión de cola
template<typename T>
void quicksort(T arr[], int left, int right) {
    while (right - left > INSERTION_SORT_THRESHOLD) {
        // Mediana de tres para elegir pivote
        int mid = left + ((right - left) >> 1);
        if (arr[mid] < arr[left])  swap(arr[left], arr[mid]);
        if (arr[right] < arr[left]) swap(arr[left], arr[right]);
        if (arr[mid] < arr[right]) swap(arr[mid], arr[right]);
        T pivot = arr[right];

        // Partición estándar Lomuto
        int i = left, j = right - 1;
        while (true) {
            while (i <= j && arr[i] < pivot) ++i;
            while (j >= i && arr[j] > pivot) --j;
            if (i >= j) break;
            swap(arr[i++], arr[j--]);
        }
        swap(arr[i], arr[right]);

        // Recur sobre la partición más pequeña primero
        if (i - left < right - i) {
            quicksort(arr, left, i - 1);
            left = i + 1;
        } else {
            quicksort(arr, i + 1, right);
            right = i - 1;
        }
    }
    // Inserción para restos pequeños
    insertionSort(arr, left, right);
}

// Función para generar un vector con datos aleatorios
vector<int> generarVectorAleatorio(int n, int minVal, int maxVal) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(minVal, maxVal);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = distrib(gen);
    }
    return arr;
}

// Función para generar un vector ordenado ascendentemente
vector<int> generarVectorAscendente(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    return arr;
}

// Función para generar un vector ordenado descendentemente
vector<int> generarVectorDescendente(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = n - 1 - i;
    }
    return arr;
}

// int main() {
//     // Define los tamaños de las entradas que quieres probar
//     vector<int> tamanos = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
//     vector<int> longitudesDigitos = {1, 7};

//     for (int tamano : tamanos) {
//         cout << "-----------------------------------------" << endl;
//         cout << "Tamaño de la entrada: " << tamano << endl;

//         for (int longitud : longitudesDigitos) {
//             int minVal = 0;
//             int maxVal = pow(10, longitud) - 1;

//             // Prueba con datos aleatorios
//             vector<int> datosAleatorios = generarVectorAleatorio(tamano, minVal, maxVal);
//             auto start = high_resolution_clock::now();
//             quicksort(datosAleatorios.data(), 0, datosAleatorios.size() - 1);
//             auto stop = high_resolution_clock::now();
//             auto duration = duration_cast<microseconds>(stop - start);
//             cout << "  Aleatorios (" << longitud << " dígitos): " << duration.count() << " microsegundos" << endl;

//             // Prueba con datos ordenados ascendentemente
//             vector<int> datosAscendentes = generarVectorAscendente(tamano);
//             start = high_resolution_clock::now();
//             quicksort(datosAscendentes.data(), 0, datosAscendentes.size() - 1);
//             stop = high_resolution_clock::now();
//             duration = duration_cast<microseconds>(stop - start);
//             cout << "  Ascendentes: (" << longitud << " dígitos): " << duration.count() << " microsegundos" << endl;

//             // Prueba con datos ordenados descendentemente
//             vector<int> datosDescendentes = generarVectorDescendente(tamano);
//             start = high_resolution_clock::now();
//             quicksort(datosDescendentes.data(), 0, datosDescendentes.size() - 1);
//             stop = high_resolution_clock::now();
//             duration = duration_cast<microseconds>(stop - start);
//             cout << "  Descendentes: (" << longitud << " dígitos): " << duration.count() << " microsegundos" << endl;
//         }
//     }

//     return 0;
// }