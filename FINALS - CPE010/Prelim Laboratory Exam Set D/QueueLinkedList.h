#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

//Create a class node

//Create a class node
template <typename T>
class QNode {
    public:
    T data;
    QNode* next;
};
// new Node Creator
template <typename T>
QNode <T>* new_Node(T newData) {
    //Allocates space for the new node
    QNode<T>* new_Node = new QNode<T>;

    //Stores the newdata to newNode
    new_Node->data = newData;

    //point the newNode to next
    new_Node->next = nullptr;

    return new_Node;
}

// enqueue
template <typename T>
void Enqueue(T newData, QNode<T>** front, QNode<T>** back)
{
    // Create the new node
    QNode<T>* newNode = new_Node(newData);

    // If the queue is empty
    if (*front == nullptr && *back == nullptr)
    {
        (*front) = newNode;
        (*back) = newNode;
        return;
    }

    // Otherwise, add the new node to the back
    (*back)->next = newNode;
    (*back) = newNode;
}

// Checker
template <typename T>
void Checker(QNode<T> **front, QNode<T> **back) {
    // If the front data is equal to the back data and vice versa.
    // Print the Sequence is symmetrical
    if ((*front)->data == (*back)->data && (*back)->data == (*front)->data) {
        std::cout << "The Sequence is Symmetrical.";
        return;
    }
    // If anything else, or if the front data is not equal to the back data and vice versa.
    // Print the Sequence is Not Symmetrical
    else {
        std::cout << "The Sequence is Not Symmetric.";
    }
}

// dequeue
template <typename T>
void dequeue(QNode<T>** front, QNode<T>** back) {
    //check if the queue is empty
    if ((*front) == nullptr && (*back) == nullptr) {
        std::cout << "The Queue is Empty." << std::endl;
        return;
    }
    //Create a temporary variable to store the current Node
    QNode<T>* deleteTemp = nullptr;

    // assign the current front to the deleteTemp
    deleteTemp = (*front);
    // check if the queue has only 1 item
    if ((*front)->next == nullptr && (*back)->next == nullptr) {
        (*front) = nullptr;
        (*back) = nullptr;
        delete deleteTemp;
        return;
    }

    (*front) = (*front)->next;
    deleteTemp->next = nullptr;
    // Delete Node
    delete deleteTemp;

}


// display all
template <typename T>
void DisplayAll(QNode<T>** front) {
    if ((*front) == nullptr) {
        std::cout << "The List has no contents. \n";
    }

    while ((*front) != nullptr) {
        std::cout << (*front)->data;
        (*front) = (*front)->next;
        
    }
    std::cout << std::endl;
}
//isEmpty
template <typename T>
void isEmpty(QNode<T>* front, QNode<T>* back) {
    if ((front) == nullptr && (back) == nullptr) {
        std::cout << "The Queue is currently Empty.";
    }
    else {
        std::cout << "The Queue is not Empty.";
    }
}

#endif