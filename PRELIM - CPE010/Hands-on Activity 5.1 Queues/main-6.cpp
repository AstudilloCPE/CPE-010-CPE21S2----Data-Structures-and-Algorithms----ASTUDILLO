#include <iostream>
#include "queueLL.h"

int main() {
    QNode<char>* front = nullptr;
    QNode<char>* back = nullptr;

    Enqueue('T', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;
    Enqueue('O', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;
    Enqueue('M', &front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;
    std::cout << "Testing the Dequeue operatior: \n";
    dequeue(&front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;
    dequeue(&front, &back);
    std::cout << "front: " << front->data << " " << "back: " << back->data << std::endl;
    dequeue(&front, &back);
    dequeue(&front, &back);

    DisplayAll(&front);

    isEmpty(front, back);

    return 0;
}