#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>
#include <ctime>

const int maxSize = 25;

void DisplayArr(int arr[]);

// Merge Function
template <typename T>
void merge(T arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge Sort using Multithreading
template <typename T>
void mergeSort_Multithread(T arr[], int left, int right) {
    int N = right - left + 1;
    // If N = 1, The array is already sorted.
    if (N <= 1) {
        return;
    }

    // If N > 1, run the "get middle" part of the code.
    int mid = (left + right) / 2;

    /* Implementation of Multithreading */
    // Creates a seperate thread for the left half of the unsorted array.
    std::thread t1(mergeSort_Multithread<T>, arr, left, mid);
    // Sort the right half on the current thread
    mergeSort_Multithread(arr, mid + 1, right);
    // Waits for the thread to finish execution before merging
    t1.join();
    // Calls merge to combine the sorted halves
    merge(arr, left, mid, right);
}


int main() {
    int unsortedArr[maxSize];
    srand(time(0));
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 100;
    }

    std::cout << "Unsorted Array: \n";
    DisplayArr(unsortedArr);

    std::cout << "\nSorted Array (Multithread Merge Sort): \n";
    mergeSort_Multithread(unsortedArr, 0, maxSize - 1);
    DisplayArr(unsortedArr);

    return 0;
}

void DisplayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}