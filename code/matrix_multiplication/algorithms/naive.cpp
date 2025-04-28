#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "naive.h"

using namespace std;

//Fuente: https://www.geeksforgeeks.org/matrix-multiplication/ y https://www.programiz.com/cpp-programming/examples/matrix-multiplication
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

