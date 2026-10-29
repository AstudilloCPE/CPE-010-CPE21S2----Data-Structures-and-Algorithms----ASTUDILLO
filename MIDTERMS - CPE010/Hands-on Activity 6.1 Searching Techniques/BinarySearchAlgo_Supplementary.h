#include "node.h"

#ifndef BINARYSEARCHALGO_SUPPLEMENTARY_H
#define BINARYSEARCHALGO_SUPPLEMENTARY_H

/*
Problem 3: Binary Search Algorithm using Arrays
*/
template <typename T>
void binarySearchArr_Compare(T data[], int arrSize, T DataToFind) {
    int low = 0;
    int high = arrSize -1;
    int middle;

    int iteration = 1;

    while (low <= high) {
            middle = (int)((low + high/2));

        std::cout << "Index Modification  " << iteration << ": " << " low = "
        << low << ", high = " << high << ", middle = " << middle
        << " (val = " << data[middle] << ")\n";

        if (DataToFind == data[middle]) {
            std::cout << "Data " << DataToFind << " Was Successfully Found at the index "<< middle;

            return;
        }

        else if (DataToFind < data[middle]) {
            high = middle - 1;
        }

        else {
            low = middle + 1;
        }
        iteration++;
    }
    std::cout << "The Data was not Found." << std::endl;
}

template <typename T>
void binarySearchArr_Recursive(T data[], int low, int high, T DataToFind, int iteration = 1) {
    if (low > high) {
        std::cout << "Data was Not Found in the Index." << std::endl;
    }

    int middle = (int)((low + high/2));

    std::cout << "Recursion Modification " << iteration << ": " << " low = "
        << low << ", high = " << high << ", middle = " << middle
        << " (val = " << data[middle] << ")\n";

    if (DataToFind == data[middle]) {
        std::cout << "Data " << DataToFind << " Was Successfully Found at the index "<< middle;

        return;
        } 
    
    if (DataToFind < data[middle]) {
        binarySearchArr_Recursive(data, low, middle - 1, DataToFind, iteration + 1);
        return;
    }

    else {
        binarySearchArr_Recursive(data, middle + 1, high, DataToFind, iteration + 1);
    }
}

#endif