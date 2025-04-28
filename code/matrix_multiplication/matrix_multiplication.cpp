// Ejemplo de lectura de archivos en un directorio en C++
// -----------------------------------------------------
// Este ejemplo utiliza la librería estándar <filesystem> introducida en C++17.
// Asegúrate de compilar con soporte para C++17 o superior (e.g., -std=c++17).

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "algorithms/naive.h"
#include "algorithms/strassen.h"


using namespace std;

//Funcion pobladora de matrices cuadradas
vector<vector<int>> loadMatrix(const string& filepath) {
    ifstream in(filepath);
    if (!in) {
        cout << "No se puede abrir: " << filepath << endl;
        return {};
    }
    vector<vector<int>> mat;
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        istringstream iss(line);
        vector<int> row;
        int x;
        while (iss >> x) row.push_back(x);
        mat.push_back(row);
    }
    return mat;
}


namespace fs = std::filesystem;

vector<pair<string, string>> getSortedPathPairs(const string& ruta) {
    vector<pair<string, string>> pathPairs;

    try {
        // Verificar que la ruta es un directorio
        if (!fs::is_directory(ruta)) {
            cerr << ruta << " no es un directorio válido.\n";
            return pathPairs;
        }

        // Recoger los elementos del directorio en un vector para luego ordenar
        vector<fs::directory_entry> entradas;
        for (const auto& entry : fs::directory_iterator(ruta)) {
            entradas.push_back(entry);
        }

        // Ordenar con "natural sort" considerando el número inicial antes del guión bajo
        auto extract_number = [](const string& name) {
            size_t pos = name.find('_');
            if (pos != string::npos) {
                try {
                    return stoi(name.substr(0, pos));
                } catch (...) {
                    return 0;
                }
            }
            return 0;
        };

        sort(entradas.begin(), entradas.end(), [&](const fs::directory_entry& a, const fs::directory_entry& b) {
            const string a_name = a.path().filename().string();
            const string b_name = b.path().filename().string();
            int a_num = extract_number(a_name);
            int b_num = extract_number(b_name);
            if (a_num != b_num) {
                return a_num < b_num;
            }
            // Si el número es igual, ordenar alfabéticamente completo
            return a_name < b_name;
        });

        // Crear pares de rutas ordenadas
        for (size_t i = 0; i + 1 < entradas.size(); i += 2) {
            pathPairs.emplace_back(entradas[i].path().string(), entradas[i + 1].path().string());
        }

        // Si hay un archivo impar, agregarlo como un par con una cadena vacía
        if (entradas.size() % 2 != 0) {
            pathPairs.emplace_back(entradas.back().path().string(), "");
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Error al acceder al directorio: " << e.what() << "\n";
    }

    return pathPairs;
}

int main() {
    // Ruta fija dada (ajusta este valor según tu directorio)
    const string ruta = "data/matrix_input";

    // Obtener los pares de rutas ordenadas
    vector<pair<string, string>> sortedPathPairs = getSortedPathPairs(ruta);

    // Mostrar los pares de rutas ordenadas
    cout << "Pares de rutas ordenadas del directorio: " << ruta << "\n";
    for (const auto& pair : sortedPathPairs) {

        // Extraer los nombres de los archivos de los pares
        string fileNameA = pair.first.substr(pair.first.find_last_of("/\\") + 1);
        string fileNameB = pair.second.substr(pair.second.find_last_of("/\\") + 1);

        // Dividir el nombre del archivo por los guiones bajos '_'
        vector<string> partesA, partesB;
        size_t start = 0, end;
        while ((end = fileNameA.find('_', start)) != std::string::npos) {
            partesA.push_back(fileNameA.substr(start, end - start));
            start = end + 1;
        }
        partesA.push_back(fileNameA.substr(start)); // Agregar la última parte

        start = 0;
        while ((end = fileNameB.find('_', start)) != std::string::npos) {
            partesB.push_back(fileNameB.substr(start, end - start));
            start = end + 1;
        }
        partesB.push_back(fileNameB.substr(start)); // Agregar la última parte

        // Asignar las partes a variables con nombres específicos
        string sizeA = partesA.size() > 0 ? partesA[0] : "";
        string typeA = partesA.size() > 1 ? partesA[1] : "";
        string largeA = partesA.size() > 2 ? partesA[2] : "";
        string idA = partesA.size() > 3 ? partesA[3] : "";

        string sizeB = partesB.size() > 0 ? partesB[0] : "";
        string typeB = partesB.size() > 1 ? partesB[1] : "";
        string largeB = partesB.size() > 2 ? partesB[2] : "";
        string idB = partesB.size() > 3 ? partesB[3] : "";

        // Mostrar los datos extraídos
        cout << "Archivo A: size=" << sizeA << ", type=" << typeA << ", large=" << largeA << ", id=" << idA << "\n";
        cout << "Archivo B: size=" << sizeB << ", type=" << typeB << ", large=" << largeB << ", id=" << idB << "\n";

        vector<vector<int>> matrixA = loadMatrix(pair.first);
        cout << "Matriz cargada desde " << pair.first << ":\n";

        vector<vector<int>> matrixB = loadMatrix(pair.second);
        cout << "Matriz cargada desde " << pair.second << ":\n";
        cout << "Multiplicando matrices...\n";

        // Para naiveMatrixMultiplication
        cout << "Multiplicando matrices con el algoritmo Naive...\n";
        auto startChrono = chrono::high_resolution_clock::now();
        vector<vector<int>> C = naiveMatrixMultiplication(matrixA, matrixB);
        auto endChrono = chrono::high_resolution_clock::now();
        auto durationMicrosegundosNaive = chrono::duration_cast<chrono::microseconds>(endChrono - startChrono).count();
        auto tiempoMilisegundosNaive = durationMicrosegundosNaive / 1e3;
        cout << "Tiempo de ejecución (Naive): " << durationMicrosegundosNaive << " microsegundos\n";
        cout << "Tiempo de ejecución (Naive): " << tiempoMilisegundosNaive << " milisegundos\n";
        cout << "Matriz multiplicada con éxito (Naive)!\n";
        cout << "----------------------------------------\n";
        
        //Escribir la matriz resultante en un archivo con el nombre de los archivos de entrada
        // string resultFilePath = "data/matrix_output/" + pair.first.substr(pair.first.find_last_of("/\\") + 1);
        string resultFilePath = "data/matrix_output/" + sizeA + "_" + typeA + "_" + largeA + "_" + idA + "_out.txt";

        ofstream resultFile(resultFilePath);
        if (resultFile.is_open()) {
            for (const auto& row : C) {
            for (const auto& elem : row) {
                resultFile << elem << " ";
            }
            resultFile << "\n";
            }
            cout << "Matriz resultante guardada en: " << resultFilePath << "\n";
        } else {
            cerr << "No se pudo abrir el archivo de salida en " << resultFilePath << ".\n";
        }
        resultFile.close();

        // Para strassen
        cout << "Multiplicando matrices con el algoritmo Strassen...\n";
        startChrono = chrono::high_resolution_clock::now();
        vector<vector<int>> C_strassen = strassen(matrixA, matrixB);
        endChrono = chrono::high_resolution_clock::now();
        auto durationMicrosegundosStrassen = chrono::duration_cast<chrono::microseconds>(endChrono - startChrono).count();
        auto tiempoMilisegundosStrassen = durationMicrosegundosStrassen / 1e3;
        cout << "Tiempo de ejecución (Strassen): " << durationMicrosegundosStrassen << " microsegundos\n";
        cout << "Tiempo de ejecución (Strassen): " << tiempoMilisegundosStrassen << " milisegundos\n";
        cout << "Matriz multiplicada con éxito (Strassen)!\n";
        cout << "----------------------------------------\n";

        //Escribir los tiempos en un archivo solo archivo
        const string outputDirectory = "data/measurements/";
        string outputFilePath = outputDirectory + "time.txt";

        ofstream outFile(outputFilePath, ios::app);
        if (outFile.is_open()) {
            // Si el archivo está vacío, agregamos un encabezado
            outFile.seekp(0, ios::end);
            if (outFile.tellp() == 0) {
            outFile << "sizeA,typeA,largeA,idA,sizeB,typeB,largeB,idB,tiempo_naive_microseg,tiempo_strassen_microseg\n";
            }

            // Escribimos los datos en formato CSV usando las nuevas variables
            outFile << sizeA << "," 
                << typeA << "," 
                << largeA << "," 
                << idA << "," 
                << sizeB << "," 
                << typeB << "," 
                << largeB << "," 
                << idB << "," 
                << tiempoMilisegundosNaive << "," 
                << tiempoMilisegundosStrassen << "\n";
        } else {
            cerr << "No se pudo abrir el archivo de salida en " << outputFilePath << ".\n";
        }
        outFile.close();


        
    }

    return 0;
}

