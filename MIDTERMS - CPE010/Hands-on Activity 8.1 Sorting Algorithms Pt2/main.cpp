#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchingAlgo_pt2.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main() {
    int unsortedArr[maxSize];
    srand(time(0));
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 1000;
    }

    std::cout << "Unsorted Array: \n";
    displayArr(unsortedArr);

    /*
    std::cout << "\nSorted Array (Shell Sort): \n";
    shellSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
    */

    /*
    std::cout << "\nSorted Array (Merge Sort): \n";
    mergeSort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);
    */

    std::cout << "\nSorted Array (Quick Sort): \n";
    quickSort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);


    return 0;
}


void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}