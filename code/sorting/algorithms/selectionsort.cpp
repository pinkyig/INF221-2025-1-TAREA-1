#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include <sys/time.h>
#include "chrono"
#include "selectionsort.h"





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




void SelectionSort(vector<int>& elementos){

    int n = elementos.size();
    
    for (int i = 0 ; i< n-1 ; i++){
        int min_index = i;
        for (int j = i + 1 ; j < n ;j++){
            if (elementos[j] < elementos[min_index])
                min_index = j;
        }

        if (min_index != i) {
            swap(elementos[i], elementos[min_index]);
        }
    }
}

// int main(){

//     vector<int> elementos = {3,2,1,5,4};

//     cout << "Vector original:" << endl;
//     for (int num : elementos) {
//         cout << num << " ";
//     }
//     cout << endl;

//     SelectionSort(elementos);

//     cout << "Vector ordenado:" << endl;
//     for (int num : elementos) {
//         cout << num << " ";
//     }
//     cout << endl;


//     return 0;
// }