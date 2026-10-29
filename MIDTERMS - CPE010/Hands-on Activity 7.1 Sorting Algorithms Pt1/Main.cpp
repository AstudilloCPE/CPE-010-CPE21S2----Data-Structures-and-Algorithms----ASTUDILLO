#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main() {
    int unsortedArr[maxSize];
    srand(time(0));
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 100;
    }

    std::cout << "unsortedArr: \n";
    displayArr(unsortedArr);

    //std::cout << "SortedArr (Bubble Sort): \n";
    //bubbleSort(unsortedArr, maxSize);
    //displayArr(unsortedArr);

    //std::cout << "Sorted Arr (Selection Sort): \n";
    //selectionSort(unsortedArr, maxSize);
    //displayArr(unsortedArr);

    std::cout << "Sorted Arr (Insertion Sort): \n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
