#include "iostream"
#include "string"
#include "vector"
#include "fstream"
#include <sys/time.h>
#include "chrono"
#include "selectionsort.h"





using namespace std;




// fuente : https://www.geeksforgeeks.org/selection-sort/ y https://www.programiz.com/dsa/selection-sort
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
