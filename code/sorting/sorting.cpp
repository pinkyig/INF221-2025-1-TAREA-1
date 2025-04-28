#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <filesystem>
#include <string>
#include <algorithm>

#include "algorithms/selectionsort.h"
#include "algorithms/mergesort.h"
#include "algorithms/quicksort.h"
#include "algorithms/sort.h"

using namespace std;

vector<int> pobladorVector(const string& rutaArchivo) {
    vector<int> elementos;
    ifstream MyFile(rutaArchivo);
    int n;
    while (MyFile >> n) {
        elementos.push_back(n);
    }
    MyFile.close();
    return elementos;
}

void imprimirVector(const vector<int>& elementos) {
    for (const int& elemento : elementos) {
        cout << elemento << " ";
    }
    cout << endl;
}

// int main(){
//     vector <int> arreglo;

//     vector<int> elementos;
//     elementos = pobladorVector(elementos);

//     cout << "Vector Original: ";
//     imprimirVector(elementos);


//     //Probando MergeSort
//     arreglo = elementos;
//     auto inicio = chrono::high_resolution_clock::now();
//     mergeSort(arreglo, 0, arreglo.size()-1);
//     auto fin = chrono::high_resolution_clock::now();
//     auto duracionMerge = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();
//     cout << "MergeSort tomó: " << duracionMerge << " microsegundos" << endl;


//     //Probando QuickSort
//     arreglo = elementos;
//     inicio = chrono::high_resolution_clock::now();
//     quickSort(arreglo, 0, arreglo.size()-1);
//     fin = chrono::high_resolution_clock::now();
//     auto duracionQuick = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();
//     cout << "QuickSort tomó: " << duracionQuick << " microsegundos" << endl;

//     //Probando SelectionSort
//     arreglo = elementos;
//     inicio = chrono::high_resolution_clock::now();
//     SelectionSort(arreglo);
//     fin = chrono::high_resolution_clock::now();
//     auto duracionSelect = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();
//     cout << "SelectionSort tomó: " << duracionSelect << " microsegundos" << endl;

//     //Probando sort

//     arreglo = elementos;
//     inicio = chrono::high_resolution_clock::now();
//     sortArray(arreglo);
//     fin = chrono::high_resolution_clock::now();
//     auto duracionLib = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();
//     cout << "LibrarySort tomó: " << duracionLib << " microsegundos" << endl;
    
//     return 0 ;
// }


// Ejemplo de lectura de archivos en un directorio en C++
// -----------------------------------------------------
// Este ejemplo utiliza la librería estándar <filesystem> introducida en C++17.
// Asegúrate de compilar con soporte para C++17 o superior (e.g., -std=c++17).

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;

std::vector<std::string> obtenerRutasOrdenadas(const std::string& ruta) {
    std::vector<std::string> rutasOrdenadas;

    try {
        // Verificar que la ruta es un directorio
        if (!fs::is_directory(ruta)) {
            std::cerr << ruta << " no es un directorio válido.\n";
            return rutasOrdenadas;
        }

        // Recoger los elementos del directorio en un vector para luego ordenar
        std::vector<fs::directory_entry> entradas;
        for (const auto& entry : fs::directory_iterator(ruta)) {
            entradas.push_back(entry);
        }

        // Ordenar con "natural sort" considerando el número inicial antes del guión bajo
        auto extract_number = [](const std::string& name) {
            size_t pos = name.find('_');
            if (pos != std::string::npos) {
                try {
                    return std::stoi(name.substr(0, pos));
                } catch (...) {
                    return 0;
                }
            }
            return 0;
        };

        std::sort(entradas.begin(), entradas.end(), [&](const fs::directory_entry& a, const fs::directory_entry& b) {
            const std::string a_name = a.path().filename().string();
            const std::string b_name = b.path().filename().string();
            int a_num = extract_number(a_name);
            int b_num = extract_number(b_name);
            if (a_num != b_num) {
                return a_num < b_num;
            }
            // Si el número es igual, ordenar alfabéticamente completo
            return a_name < b_name;
        });

        // Agregar las rutas ordenadas al vector
        for (const auto& entry : entradas) {
            rutasOrdenadas.push_back(entry.path().string());
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error al acceder al directorio: " << e.what() << "\n";
    }

    return rutasOrdenadas;
}


int main() {
    std::string ruta = "data/array_input";
    std::vector<std::string> rutasOrdenadas = obtenerRutasOrdenadas(ruta);

    for (const auto& ruta : rutasOrdenadas) {
        std::vector<int> elementos = pobladorVector(ruta);
        cout << "Procesando archivo: " << ruta << endl;
        // Extraer partes del nombre del archivo
        fs::path filePath(ruta);
        std::string fileName = filePath.stem().string(); // Obtener el nombre del archivo sin extensión
        std::vector<std::string> partes;
        size_t start = 0, end = 0;

        // Dividir el nombre del archivo por los guiones bajos '_'
        while ((end = fileName.find('_', start)) != std::string::npos) {
            partes.push_back(fileName.substr(start, end - start));
            start = end + 1;
        }
        partes.push_back(fileName.substr(start)); // Agregar la última parte

        // Asignar las partes a variables con nombres específicos
        string size = partes.size() > 0 ? partes[0] : "";
        string type = partes.size() > 1 ? partes[1] : "";
        string large = partes.size() > 2 ? partes[2] : "";
        string id = partes.size() > 3 ? partes[3] : "";

        // Imprimir las partes extraídas
        cout << "ID: " << id << ", Size: " << size << ", Type: " << type << endl;

        // Probando MergeSort
        vector<int> arreglo = elementos;
        auto inicio = chrono::high_resolution_clock::now();
        mergeSort(arreglo, 0, arreglo.size() - 1);
        auto fin = chrono::high_resolution_clock::now();
        auto duracionMerge = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();
        cout << "MergeSort tomó: " << duracionMerge << " microsegundos" << endl;

        // Probando QuickSort
        arreglo = elementos;
        inicio = chrono::high_resolution_clock::now();
        quicksort(arreglo.data(), 0, arreglo.size() - 1);
        fin = chrono::high_resolution_clock::now();
        auto duracionQuick = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();
        cout << "QuickSort tomó: " << duracionQuick << " microsegundos" << endl;

        // Probando SelectionSort
        auto duracionSelect = -1; // Inicializar con un valor por defecto
        if (elementos.size() < 10000000) {
            arreglo = elementos;
            auto inicio = chrono::high_resolution_clock::now();
            SelectionSort(arreglo);
            auto fin = chrono::high_resolution_clock::now();
            duracionSelect = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();
            cout << "SelectionSort tomó: " << duracionSelect << " microsegundos" << endl;
        } else {
            cout << "SelectionSort no se ejecuta para 10,000,000 datos." << endl;
        }

        // Probando sort (LibrarySort)
        arreglo = elementos;
        inicio = chrono::high_resolution_clock::now();
        sortArray(arreglo);
        fin = chrono::high_resolution_clock::now();
        auto duracionLib = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();
        cout << "LibrarySort tomó: " << duracionLib << " microsegundos" << endl;

        cout << "----------------------------------------" << endl;


        // Escribir la matriz resultante en un archivo
        const string outputDirectorySorted = "data/array_output/";
        fs::create_directories(outputDirectorySorted); // Crear directorio si no existe
        string sortedFilePath = outputDirectorySorted + size + "_" + type + "_" + large + "_" + id + "_out.txt";

        ofstream sortedFile(sortedFilePath);
        if (sortedFile.is_open()) {
            for (const int& elemento : arreglo) {
                sortedFile << elemento << " ";
            }
            sortedFile.close();
            cout << "Matriz ordenada escrita en: " << sortedFilePath << endl;
        } else {
            cerr << "No se pudo abrir el archivo para escribir la matriz ordenada en " << sortedFilePath << ".\n";
        }

        // Escribir los tiempos en un archivo
        const string outputDirectory = "data/measurements/";
        string outputFilePath = outputDirectory + "time.txt";

        ofstream outFile(outputFilePath, ios::app);
        if (outFile.is_open()) {
            // Si el archivo está vacío, agregamos un encabezado
            outFile.seekp(0, ios::end);
            if (outFile.tellp() == 0) {
                outFile << "size,type,Large,id,MergeSort_microseg,QuickSort_microseg,SelectionSort_microseg,LibrarySort_microseg\n";
            }

            // Escribimos los datos en formato CSV
            outFile << size << "," 
                    << type << "," 
                    << large << "," 
                    << id << "," 
                    << duracionMerge << "," 
                    << duracionQuick << "," 
                    << duracionSelect << "," 
                    << duracionLib << "\n";
        } else {
            cerr << "No se pudo abrir el archivo de salida en " << outputFilePath << ".\n";
        }
        outFile.close();


    }

    return 0;
}

/*
Explicación:
- Extrayendo la parte numérica al inicio del nombre (antes del primer '_'), se puede ordenar por valor entero.
- Si los prefijos numéricos son iguales, se usa la comparación lexicográfica del nombre completo.
*/
