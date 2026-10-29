#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

/*
Linear Search Algorithm
*/

template <typename T>
void linearSearchAR(int size, T datatofind, int array[]) {

    int i = 0;

    while (i < size) {
        if (datatofind = array[i]) {
            std::cout << "Searching is successful\n";
            return;
        }
        i++;
    }
    std::cout << "Searching is unsuccessful.\n";


}

/*
Linear Search Algorithm For Linked Lists
*/

template<typename T>
void linearSearchLL(Node<T> *nodes, T dataFind) {

while(nodes != nullptr){

    if(nodes->data == dataFind){
        std::cout << "The data: " << nodes->data << " was found successfully.\n";
        return;
        }
    nodes = nodes->next;

    }
    std::cout << "Searching is unsuccessful.\n";
}   


/*
Binary Search Algorithm For Arrays
*/
template <typename T>
void binarySearchArr(T data[], int arrSize, T datatofind) {
    int low = 0;
    int high = arrSize - 1;
    int middle;

    while(low <= high) {
        middle = (int)((low + high/2));
        if (datatofind = data[middle]) {
            std::cout << "The Data was Found.\n";
            return;
        }
        else if(datatofind < data[middle]) {
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }

    std::cout << "The Data was Not Found.\n";
}


/*
Get Middle Function
*/

template <typename T>
Node<T>* getMiddle(Node<T> *start, Node<T> *last) {

    Node<T> *slow = start;
    Node<T> *fast = start;


    while (fast != last && fast->next != last) {

        slow = slow->next;

        fast = fast->next;
        if (fast != last) fast = fast->next;
    }
    return slow;
}

/*
Binary Linked List
*/

template <typename T>
void binarySearchLL(Node<T>* start, T datatofind) {
    Node<T>* last = nullptr;

    while (start != last) {
        Node<T>* middle = getMiddle(start, last);

        if (middle->data == datatofind) {
            std::cout << "Searching is Successful.\n";
            return;
        }
        else if (middle->data > datatofind) {
            last = middle;
        }
        else {
            start = middle->next;
        }
    }

    std::cout << "Searching is Unsuccessful.\n";
}
#endif