#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

// --- Shell Sort Implementation ---
void shellSort(std::vector<int>& arr) {
int n = arr.size();
// Start with a large gap, then reduce the gap
for (int gap = n / 2; gap > 0; gap /= 2) {
// Do a gapped insertion sort for this gap size.
for (int i = gap; i < n; i += 1) {
int temp = arr[i];
int j;
for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
arr[j] = arr[j - gap];
}
arr[j] = temp;
}
}
}

int main() {
std::vector<int> testSizes = {100, 1000, 10000};

std::cout << "========================================\n";
std::cout << " SHELL SORT BENCHMARK (ALG 2) \n";
std::cout << "========================================\n\n";

for (int n : testSizes) {
std::cout << "--- Input Size (n) = " << n << " ---\n";

// 1. Best Case (Already Sorted)
std::vector<int> bestCaseArr(n);
for (int i = 0; i < n; i++) {
bestCaseArr[i] = i;
}

auto start = std::chrono::high_resolution_clock::now();
shellSort(bestCaseArr);
auto stop = std::chrono::high_resolution_clock::now();
long long shellBest = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

// 2. Worst Case (Reverse Sorted)
std::vector<int> worstCaseArr(n);
for (int i = 0; i < n; i++) {
worstCaseArr[i] = n - i;
}

start = std::chrono::high_resolution_clock::now();
shellSort(worstCaseArr);
stop = std::chrono::high_resolution_clock::now();
long long shellWorst = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

std::cout << " Best Case : " << shellBest << " microseconds\n";
std::cout << " Worst Case : " << shellWorst << " microseconds\n\n";
}

return 0;
}