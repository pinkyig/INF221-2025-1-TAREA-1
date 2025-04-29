#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <sstream>
#include "strassen.h"
using namespace std;


//Fuente:https://www.geeksforgeeks.org/strassens-matrix-multiplication/

vector<vector<int>> strassen(const vector<vector<int>>& matrizA, const vector<vector<int>>& matrizB) {
    int n = matrizA.size();

    //Dividir la matriz en 4 submatrices
    vector<vector<int>> A11(n/2, vector<int>(n/2));
    vector<vector<int>> A12(n/2, vector<int>(n/2));
    vector<vector<int>> A21(n/2, vector<int>(n/2));
    vector<vector<int>> A22(n/2, vector<int>(n/2));

    vector<vector<int>> B11(n/2, vector<int>(n/2));
    vector<vector<int>> B12(n/2, vector<int>(n/2));
    vector<vector<int>> B21(n/2, vector<int>(n/2));
    vector<vector<int>> B22(n/2, vector<int>(n/2));

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            A11[i][j] = matrizA[i][j];
            A12[i][j] = matrizA[i][j + n/2];
            A21[i][j] = matrizA[i + n/2][j];
            A22[i][j] = matrizA[i + n/2][j + n/2];

            B11[i][j] = matrizB[i][j];
            B12[i][j] = matrizB[i][j + n/2];
            B21[i][j] = matrizB[i + n/2][j];
            B22[i][j] = matrizB[i + n/2][j + n/2];
        }
    }

    // Calcular las 7 multiplicaciones de Strassen
    vector<vector<int>> M1(n/2, vector<int>(n/2));
    vector<vector<int>> M2(n/2, vector<int>(n/2));
    vector<vector<int>> M3(n/2, vector<int>(n/2));
    vector<vector<int>> M4(n/2, vector<int>(n/2));
    vector<vector<int>> M5(n/2, vector<int>(n/2));
    vector<vector<int>> M6(n/2, vector<int>(n/2));
    vector<vector<int>> M7(n/2, vector<int>(n/2));

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            int sum = 0;
            for (int k = 0; k < n/2; k++) {
                sum += (A11[i][k] + A22[i][k]) * (B11[k][j] + B22[k][j]);
            }
            M1[i][j] = sum;
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            int sum = 0;
            for (int k = 0; k < n/2; k++) {
                sum += (A21[i][k] + A22[i][k]) * B11[k][j];
            }
            M2[i][j] = sum;
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            int sum = 0;
            for (int k = 0; k < n/2; k++) {
                sum += A11[i][k] * (B12[k][j] - B22[k][j]);
            }
            M3[i][j] = sum;
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            int sum = 0;
            for (int k = 0; k < n/2; k++) {
                sum += A22[i][k] * (B21[k][j] - B11[k][j]);
            }
            M4[i][j] = sum;
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            int sum = 0;
            for (int k = 0; k < n/2; k++) {
                sum += (A11[i][k] + A12[i][k]) * B22[k][j];
            }
            M5[i][j] = sum;
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            int sum = 0;
            for (int k = 0; k < n/2; k++) {
                sum += (A21[i][k] - A11[i][k]) * (B11[k][j] + B12[k][j]);
            }
            M6[i][j] = sum;
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            int sum = 0;
            for (int k = 0; k < n/2; k++) {
                sum += (A12[i][k] - A22[i][k]) * (B21[k][j] + B22[k][j]);
            }
            M7[i][j] = sum;
        }
    }

    // Calcular las submatrices C
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            C[i][j + n/2] = M3[i][j] + M5[i][j];
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            C[i + n/2][j] = M2[i][j] + M4[i][j];
        }
    }

    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            C[i + n/2][j + n/2] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    return C;
}

