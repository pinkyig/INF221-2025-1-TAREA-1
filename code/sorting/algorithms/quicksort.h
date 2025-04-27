#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>  // para std::swap

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
        int mid = left + ((right - left) >> 1);
        if (arr[mid] < arr[left])  std::swap(arr[left], arr[mid]);
        if (arr[right] < arr[left]) std::swap(arr[left], arr[right]);
        if (arr[mid] < arr[right]) std::swap(arr[mid], arr[right]);
        T pivot = arr[right];

        int i = left, j = right - 1;
        while (true) {
            while (i <= j && arr[i] < pivot) ++i;
            while (j >= i && arr[j] > pivot) --j;
            if (i >= j) break;
            std::swap(arr[i++], arr[j--]);
        }
        std::swap(arr[i], arr[right]);

        if (i - left < right - i) {
            quicksort(arr, left, i - 1);
            left = i + 1;
        } else {
            quicksort(arr, i + 1, right);
            right = i - 1;
        }
    }
    insertionSort(arr, left, right);
}

#endif // QUICKSORT_H

