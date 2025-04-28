#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include <sys/time.h>
#include "chrono"
using namespace std;




//funcion de ordenamiento mergeSort, fuente: https://www.geeksforgeeks.org/merge-sort/ y https://www.programiz.com/dsa/merge-sort

void merge(vector<int>& elementos, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++){
        L[i] = elementos[l + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = elementos[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            elementos[k] = L[i];
            i++;
        }else{
            elementos[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        elementos[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        elementos[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& elementos, int l, int r){
    if (l >= r){
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(elementos, l, m);
    mergeSort(elementos, m + 1, r);
    merge(elementos, l, m, r);
}
