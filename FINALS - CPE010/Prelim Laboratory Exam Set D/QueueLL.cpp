#include <iostream>
#include "QueueLinkedList.h"


int main() {
    QNode<char>* front = nullptr;
    QNode<char>* back = nullptr;

    Enqueue('1', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;
    Enqueue('2', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;
    Enqueue('3', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;
    Enqueue('4', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;
    Enqueue('3', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;
    Enqueue('2', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;
    Enqueue('5', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;

    std::cout << "Is the Sequence Symmetric or Asymmetric?: \n";
    Checker(&front, &back);

    std::cout << "\nPrinting All Data in the Queue: ";
    DisplayAll(&front);


    return 0;
}