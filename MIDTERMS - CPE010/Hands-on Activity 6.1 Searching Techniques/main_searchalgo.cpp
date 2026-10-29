#include <iostream>
#include <cstdlib>
#include <time.h>
#include "searchingAlgo.h"
#include "node.h"


// Dataset Size Declaration
const int max_size = 50;

int main() {

    // Generate a random set of data
    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++) {
        dataset[i] = rand();
        std::cout<< dataset[i] << " ";
    }
    std::cout << std::endl;
    // Asks the user what number they want to find in the dataset.
    std::cout << "What Number to Find: ";
    int choice;
    std::cin >> choice;

    // Linear Search Array
    linearSearchAR(max_size, 10, dataset);



    Node<char> *char1 = new_node('J');
    Node<char> *char2 = new_node('I');
    Node<char> *char3 = new_node('M');

    char1->next = char2;
    char2->next = char3;
    char3->next = nullptr;

    
    // Linear Search Linked List
    linearSearchLL(char1, 'J');

    /*
    // Binary Search Array
    int newArr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < max_size; i++) {
        newArr[i] = i;
    }

    binarySearchArr(newArr, max_size, 5);


    Node<char> *char1 = new_node('J');
    Node<char> *char2 = new_node('I');
    Node<char> *char3 = new_node('M');

    char1->next = char2;
    char2->next = char3;
    char3->next = nullptr;

    // Binary Search Linked List
    binarySearchLL(char1, 'M');
    */
   
    return 0;

}