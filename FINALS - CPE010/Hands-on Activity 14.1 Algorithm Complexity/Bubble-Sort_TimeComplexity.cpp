#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cmath>
#include <string>

class BubbleSort_TimeComplexity {
private:
    std::vector<int> array;

public:

    BubbleSort_TimeComplexity(const std::vector<int>& arr) : array(arr) {}

    void sortArray();

    static void checkArray(int size, const std::string& caseType);
};

void BubbleSort_TimeComplexity::sortArray() {
    int n = array.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[i]) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

void BubbleSort_TimeComplexity::checkArray(int size, const std::string& caseType) {
    std::vector<int> Array(size);

    if (caseType == "best") {
        for (int i = 0; i < size; i++) {
            Array[i] = i;
        }
    } else if (caseType == "worst") {
        for (int i = 0; i < size; i++) {
            Array[i] = size - i;
        }
    } else {
        std::mt19937 rng(50);
        std::uniform_int_distribution<int> dist(1, 100000);
        for (int i = 0; i < size; i++) {
            Array[i] = dist(rng);
        }
    }

    BubbleSort_TimeComplexity sorter(Array);

    auto begin = std::chrono::steady_clock::now();
    
    sorter.sortArray();
    
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    std::cout << " Array Size: " << size 
              << " | Time: " << duration << " microseconds" << std::endl;
}

int main() {
    std::cout << "====================== BEST CASE ======================" << std::endl;
    BubbleSort_TimeComplexity::checkArray(100, "best");
    BubbleSort_TimeComplexity::checkArray(1000, "best");
    BubbleSort_TimeComplexity::checkArray(10000, "best");

    std::cout << "\n====================== WORST CASE ======================" << std::endl;
    BubbleSort_TimeComplexity::checkArray(100, "worst");
    BubbleSort_TimeComplexity::checkArray(1000, "worst");
    BubbleSort_TimeComplexity::checkArray(10000, "worst");

    return 0;
}