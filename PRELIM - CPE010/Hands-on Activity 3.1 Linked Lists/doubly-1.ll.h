#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H


template <typename D>
class DoubleList { 
    public:
    D data;
    DoubleList<D>* prev = nullptr;
    DoubleList<D>* next = nullptr;

};

//Node Creation
template <typename D>
DoubleList<D>* CreatenewNode(D newData) {
    DoubleList<D> *CreatenewNode = new DoubleList<D>;

    CreatenewNode->data = newData;
    CreatenewNode->next = nullptr;
    CreatenewNode->prev = nullptr;

    return CreatenewNode;
}

template <typename D>
void ListTraversal(DoubleList<D>* currentNode) {

    DoubleList<D>* TempVar;

    if(currentNode == nullptr) {
        std::cout << "The List is empty. ";
        return;
    }
    
    std::cout<< "Forward: " << std::endl;
    while(currentNode != nullptr) {
        std::cout << currentNode-> data << " ";
        TempVar = currentNode;
        currentNode = currentNode->next;
    }

    std::cout<<std::endl;

    std::cout << "Backwards: " << std::endl;
    while(TempVar != nullptr) {
        std::cout << TempVar-> data << " ";
        TempVar = TempVar->prev;
    }

}

template <typename D>
    void dllinsertheader(D newData, DoubleList<D>** currentHead) {
        DoubleList<D>*  newNode = CreatenewNode(newData);

        newNode->next = *currentHead;

        (*currentHead)->prev = newNode;

        *currentHead = newNode;


    }


template <typename D>

void dllGeneralInsert(D newData, DoubleList<D>* preNode) {
    if (preNode == nullptr) {
        std::cout << "Previous Value Cannot be Null." << std::endl;
        return;
     }

    DoubleList<D>* newNode = new DoubleList<D>;

    newNode->data = newData;
    newNode->next = preNode->next;
    newNode->prev = preNode;

    if (preNode->next != nullptr){
        preNode->next->prev = newNode;
    }

    preNode->next = newNode;

}

template <typename D>
    void dllinsertEnd(D newData, DoubleList<D>* currentHead){
        
        DoubleList<D>* newNode = CreatenewNode(newData);

    while (currentHead->next != nullptr) {
        currentHead = currentHead->next;
    }

        currentHead->next = newNode;

        newNode->prev = currentHead;

    }

template <typename D>
    void dllDeleteNode(D findData, DoubleList<D>** currentHead) {

        if(*currentHead == nullptr) {
            std::cout << "The List is currently empty." << std::endl;
            return;
        }

        DoubleList<D>* newNode = *currentHead;

        while(newNode != nullptr && newNode->data != findData) {
        newNode = newNode->next;
        }

        if (newNode == nullptr) {
            std::cout<< "Data was not found." << std::endl;

            return;
        }

        if (newNode->prev != nullptr) {
            newNode->prev->next = newNode->next;
        }
        else {
            *currentHead = newNode->next;
        }

        if (newNode->next != nullptr) {
            newNode->next->prev = newNode->prev;
        }

        delete newNode;

    }

template <typename D>
    void dllDeleteAllNodes(DoubleList<D> **newNode) {
        DoubleList<D>* current = *newNode;

        while (current != nullptr) {
        DoubleList<D>* temp = current;

        current = current->next;

        delete temp;
    }
        *newNode = nullptr;
    }


#endif
    //DoubleList<char>* head = nullptr;
    //head -> data;
    //head -> next = nullptr;
    //head -> prev = nullptr;