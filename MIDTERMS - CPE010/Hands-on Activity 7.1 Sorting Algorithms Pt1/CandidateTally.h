#ifndef CANDIDATETALLY_H
#define CANDIDATETALLY_H
#include <cstddef>

template <typename T>
void bubbleSort_Votes(T arr[], size_t arrSize) {
    // Outer loop: number of passes
    for (size_t i = 0; i < arrSize - 1; i++) {
        // Inner loop: compare adjacent elements
        for (size_t j = 0; j < arrSize - i - 1; j++) {
            // Swap if the current element is greater than the next
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Sum up all Votes
template <typename T>
void tallyVotes(T arr[], size_t arrSize) {
    int votes[5] = {0};

    for (size_t i = 0; i < arrSize; i++) {
        int vote = arr[i];
        if (vote >= 1 && vote <= 5) {
            votes[vote]++;
        }
    }
    for (int candidate = 1; candidate <= 5; candidate++) {
        std::cout << "Candidate " << candidate << ": " << votes[candidate] << " votes\n";
    }

// Determine the Winning Candidate
    int maxVotes = 0;
    int Winner = -1;

    for (int i = 1; i <= 5; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            Winner = i;
        }
    }

    std::cout << "The Winning Candidate is: Candidate " 
              << Winner << "\nWith: " << maxVotes << " Votes\n";

    return;
}


#endif