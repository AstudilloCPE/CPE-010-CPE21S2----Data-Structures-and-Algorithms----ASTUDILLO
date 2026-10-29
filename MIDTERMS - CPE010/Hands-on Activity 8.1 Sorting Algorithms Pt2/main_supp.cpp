#include <iostream>
#include <cstdlib>
#include <ctime>
#include "searchingAlgo_pt2.h"

void displayArr(int arr[], int size);

int main()
{
    // Problem 1: Partitions & Quick Sort using ShellSort

    int prob1Array[] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int prob1Size = 15;

    std::cout << "Before Hybrid Quick Sort: ";
    displayArr(prob1Array, prob1Size);
    
    hybridQuickSort(prob1Array, 0, prob1Size - 1);

    std::cout << "After Hybrid Quick Sort: ";
    displayArr(prob1Array, prob1Size);

    return 0;
}

void displayArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}
