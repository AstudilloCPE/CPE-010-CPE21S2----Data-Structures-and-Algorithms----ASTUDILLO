#include <iostream>
#include "LinearSearchAlgo_Supplementary.h"
#include "BinarySearchAlgo_Supplementary.h"
#include "node.h"

// Initialize Max Size
const int max_size = 10;

int main() {

    // Linear Search using Arrays and Linked List
    int dataset[max_size] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    Node<int> *head = new_node(15);
    Node<int> *n2 = new_node(18);
    Node<int> *n3 = new_node(2);
    Node<int> *n4 = new_node(19);
    Node<int> *n5 = new_node(18);
    Node<int> *n6 = new_node(0);
    Node<int> *n7 = new_node(8);
    Node<int> *n8 = new_node(14);
    Node<int> *n9 = new_node(19);
    Node<int> *n10 = new_node(14);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    n10->next = nullptr;

    // Linear Search Using Array
    std::cout << "Linear Search using Array (Target Value is: 18)" << std::endl;
    LinearSearchARR_Compare(max_size, 18, dataset);
    // Linear Search Using Linked List
    LinearSearchLL_Compare(head, 18);


    // Sequential Search with repeating instances using Arrays and Linked List
    int k = 18;

    int arrCount = countOccuranceARR(max_size, k, dataset);
    std:: cout << "Array Count for the Element: " << k << "\n";
    std:: cout << "Was found in: " << arrCount << std::endl;

    int linkedlistCount = countOccuranceLL(head, k);
    std:: cout << "Linked List Count for the Element: " << k << "\n";
    std:: cout << "Was found in: " << linkedlistCount << std::endl;


    // Binary Search using Arrays

    int dataset[max_size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int targetvalue = 8;

    std::cout << "Binary Search Using Arrays" << std::endl;

    binarySearchArr_Compare(dataset, max_size, targetvalue);

    std::cout << "\nBinary Searching using Recursive" << std::endl;

    binarySearchArr_Recursive(dataset, 0, max_size - 1, targetvalue);

    return 0;
}

