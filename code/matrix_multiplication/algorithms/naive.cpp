#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "naive.h"

using namespace std;


vector<vector<int>> naiveMatrixMultiplication(const vector<vector<int>>& matrizA, const vector<vector<int>>& matrizB) {
    int n = matrizA.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    return C;
}

// int main() {
//     int n;

//     srand(time(0)); // semilla para generar números aleatorios

//     vector<vector<int>> matrizA = loadMatrix("../data/matrix_input/1024_densa_D0_a_1.txt");
//     vector<vector<int>> matrizB = loadMatrix("../data/matrix_input/1024_densa_D0_a_2.txt");

//     n = matrizA.size();

//     auto startChrono = chrono::high_resolution_clock::now();
//     vector<vector<int>> C = naiveMatrixMultiplication(matrizA, matrizB);
//     auto endChrono = chrono::high_resolution_clock::now();

//     auto durationMicrosegundos = chrono::duration_cast<chrono::microseconds>(endChrono - startChrono).count();
//     auto tiempoMilisegundos = durationMicrosegundos / 1e3;

//     cout << "matriz multiplicada con exito!" << endl;

//     cout << "Tiempo de ejecucion: " << durationMicrosegundos << " microsegundos" << endl;
//     cout << "Tiempo de ejecucion: " << tiempoMilisegundos << " milisegundos" << endl;

//     return 0;
// }
