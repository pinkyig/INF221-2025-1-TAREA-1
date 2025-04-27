#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include <sys/time.h>
#include "chrono"
using namespace std;


//poblador de vector
// vector<int> pobladorVector(vector<int> elementos){
//     ifstream MyFile("../data/array_input/10_descendente_D7_c.txt");
//     int n;
//     while (MyFile >> n){
//         elementos.push_back(n);
//     }
//     MyFile.close();
//     return elementos;

// }


//funcion de ordenamiento mergeSort

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



// int main(){

//     long tiempoMicrosegundos;
//     double tiempoSegundos;
        

//     vector<int> elementos;
//     elementos = pobladorVector(elementos);

//     cout << "Vector original:" << endl;
//     for (int num : elementos) {
//         cout << num << " ";
//     }
//     cout << endl;
//     //obteniendo el tiempo de ejecucion
 
//     auto startChrono = chrono::high_resolution_clock::now();
//     mergeSort(elementos, 0, elementos.size() - 1);
//     auto endChrono = chrono::high_resolution_clock::now();


//     cout << "Elementos ordenados con exito!" << endl;

//     auto durationMicrosegundos = chrono::duration_cast<chrono::microseconds>(endChrono - startChrono).count();
    
//     auto tiempoMilisegundos = durationMicrosegundos / 1e3;

//     cout << "Tiempo de ejecucion: " << durationMicrosegundos << " microsegundos" << endl;
//     cout << "Tiempo de ejecucion: " << tiempoMilisegundos << " milisegundos" << endl;    

// }