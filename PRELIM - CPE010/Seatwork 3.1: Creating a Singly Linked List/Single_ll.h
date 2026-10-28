#ifndef SINGLE_LL_H
#define SINGLE_LL_H

template <typename T>

class SingleList {
    public:
    T data; // This contains the head of the data to be store in the node.
    SingleList<T>* next = nullptr;

};

// List Traversal
template <typename T>
void ListTraversal(SingleList<T>* head) {
    if(head == nullptr) {
        std::cout << "The List has no contents.";
    }

    while(head != nullptr) {
        std::cout << head-> data;
    
        if(head->next != nullptr) {
            std::cout << "->";
        }
        head = head->next;
    }


    std::cout << std::endl;
}

// Insert at the Head
template <typename T>
    void sllinsertheader(T newData, SingleList<T>** head) {
        SingleList<T>* newNode = new SingleList<T>;

        newNode->data = newData;

        newNode->next = *head;

        *head = newNode;

    }

// General Inserter
template <typename T>
void stllGeneralInserter(T newData, SingleList<T>* preNode){
    if (preNode ==nullptr) {
        std::cout << "Previous Value cannot be null." << std::endl;
        return;
    }

    SingleList<T>* newNode = new SingleList<T>;
    
    newNode->data = newData;

    newNode->next = preNode->next;

    preNode->next = newNode;
}


// Inserts at the End
template <typename T>
void stllInsertEnd(T newData, SingleList<T>** head) {
    SingleList<T>* newNode = new SingleList<T>;
    SingleList<T>* currentNode = *head;
    newNode->data = newData;
    newNode->next = nullptr;

    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;

}

// Deletes a specific node
template <typename T>
void stllDeleteNode(T findData, SingleList<T>** head) {
    if(*head == nullptr) return;

    SingleList<T>* currentNode = *head;
    SingleList<T>* prevNode = nullptr;

    while(currentNode != nullptr && currentNode->data != findData) {
        prevNode = currentNode;
        currentNode = currentNode->next;

    }
    if (currentNode == nullptr) {
        std::cout<< "Data was not found. Try again." << std::endl;
        return;
    }

    if (prevNode == nullptr) {
        *head = currentNode->next;

    } else {
        prevNode->next = currentNode->next;

    }
    delete currentNode;

}

// Delete All Nodes
template <typename T>
void stllDeleteAllNodes(SingleList<T> **head) {
    SingleList<T>* current = *head;

    while (current != nullptr) {
        SingleList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}
#endif