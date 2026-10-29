#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CandidateTally.h"

// Set the max Capacity
const int maxSize = 100;

void displayVotes(int arr[]);
// Main Body

// Initialize the array
int main() {
    int CandidateVotes[maxSize];
    srand(time(0));
    for (int i = 0; i < maxSize; i++) {
        CandidateVotes[i] = (rand() % 5) + 1; // Generates from values 1 - 5
    }

// Display the original Votes
    std::cout << "Unsorted Candidate Votes: \n";
    displayVotes(CandidateVotes);

// Display the Sorted Votes
    std::cout << "Sorted Candidate Votes: \n";
    bubbleSort_Votes(CandidateVotes, maxSize);
    displayVotes(CandidateVotes);

// Sum up the total votes for each candidate & display the total sum of votes
// Determine which candidate received the highest number of votes & display the winning candidate
    std::cout << "Total Votes for Each Candidate: \n";
    tallyVotes(CandidateVotes, maxSize);

    return 0;
}

// Display the Votes
void displayVotes(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}