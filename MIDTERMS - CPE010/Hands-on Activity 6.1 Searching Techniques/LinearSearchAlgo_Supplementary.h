#include "node.h"

#ifndef LINEARSEARCHALGO_SUPPLEMENTARY_H
#define LINEARSEARCHALGO_SUPPLEMENTARY_H

/*
Problem 1: Sequential Search Using both Linked List and Arrays
*/

// Linear Search Array
template <typename T>
void LinearSearchARR_Compare(int arrsize, T DataToFind, T array[]) {
    int compare = 0;

    for (int i = 0; i < arrsize; i++) {
        compare++;

        if (array[i] == DataToFind) {
            std::cout << "Data was found! Comparisons Made: " << compare << std::endl;
            return;
        }
    }
    std::cout << "Data was not found. Comparisons Made: " << compare << std::endl;
}

// Linear Search Linked List
template <typename T>
void LinearSearchLL_Compare(Node<T> *nodes, T DataToFind) {
    int comparison = 0;

    while(nodes != nullptr) {
        comparison++;
        if(nodes->data == DataToFind) {
            std::cout << "Data was found!: " << nodes->data << std::endl;
            std::cout << "The Number of Comparisons made are: " << comparison << std::endl;
            return;
        }
        nodes = nodes->next;
    }
    std::cout << "Searching was Unsuccessful. \n";
    std::cout << "Comparisons Made: " << comparison << std::endl;
}

/*
Problem 2: Sequential Search Algorithm that counts repeating instances
*/

template <typename T>
int countOccuranceARR(int size, T DataToFind, T array[]) {
    int count = 0;

    for(int k = 0; k < size; k++) {
        if (array[k] == DataToFind) {
            count++;
        }
    }
    return count;
}

template <typename T>
int countOccuranceLL(Node<T> *nodes, T DataToFind) {
    int count = 0l;
    Node<T> *currentnode = nodes;

    while (currentnode != nullptr) {
        if(currentnode->data == DataToFind) {
            count++;
        }

        currentnode = currentnode->next;
    }

    return count;
}

#endif