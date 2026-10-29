#include <cstddef>
#include <vector>
#ifndef SORTINGALGO_PT2_H
#define SORTINGALGO_PT2_H

// Shell Sort
template <typename T>
// shellSort(array, size)
void shellSort(T arr[], size_t arrSize) {
    // for interval i <- size/2n down to 1
    for (size_t gap = arrSize / 2; gap > 0; gap /= 2) {

        // for each interval "i" in array
        for (size_t i = gap; i < arrSize; i++) {
            T temp = arr[i];
            size_t j = i;

        // sort all the elements at interval "i"
        while (j >= gap && arr[j - gap] > temp) {
            arr[j] = arr[j - gap];
            j -= gap;
            }

            arr[j] = temp;
        }
    }

}

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

// Merge Sort
template <typename T>
void mergeSort(T arr[], int left, int right) {
    int N = right - left + 1;

    // If N = 1, array is already sorted
    if (N == 1) {
        return; // Return simply means that the array is already sorted
    }

    // If N>1,
    else if (N > 1) {
        // Find middle = (left + right)/2
        int mid = (left + right) / 2;

        // Call merge_sort(Arr,left,middle) => sort first half recursively
        mergeSort(arr, left, mid);
        // Call merge_sort(Arr,middle+1,right) => sort second half recursively
        mergeSort(arr, mid + 1, right);
        //Call merge(Arr, left, middle, right) to merge sorted arrays in above steps
        merge(arr, left, mid, right);

    }
}

// Quick Sort Partition
template <typename T>
int Partition(T arr[], int low, int high) {
    // Declare array A[N] to be sorted
    T pivot = arr[high];
    // low = 1st element; high = last element; pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        // pivot = partition(A, low, high)
        int pivot = Partition(arr, low, high);

        // quicksort(A, low, pivot-1)
        quickSort(arr, low, pivot - 1);

        // quicksort(A, pivot+1, high)
        quickSort(arr, pivot + 1, high);
    }
}


template <typename T>
void hybridQuickSort(T arr[], int low, int high){
    if(low < high) {
        int pivotIndex = Partition(arr, low, high);

        int leftSize = pivotIndex - low;
        int rightSize = high - pivotIndex;

        if(leftSize > 1){
            shellSort(&arr[low], leftSize);
        }
        if(rightSize > 1){
            shellSort(&arr[pivotIndex + 1], rightSize);
        }
    }
}


#endif