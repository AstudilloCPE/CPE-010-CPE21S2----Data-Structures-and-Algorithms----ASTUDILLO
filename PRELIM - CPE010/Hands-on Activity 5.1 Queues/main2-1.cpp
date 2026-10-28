#include <iostream>
#include "queueArr.h"

int main() {
    queueArr<int> q(5);

    q.Enqueue(10);
    std::cout <<"Front: " << q.front() << std::endl;
    std::cout <<"Back: " << q.back() << std::endl;
    std::cout <<"Size: " << q.Size() << std::endl;

    q.Enqueue(20);
    std::cout <<"Front: " << q.front() << std::endl;
    std::cout <<"Back: " << q.back() << std::endl;
    std::cout <<"Size: " << q.Size() << std::endl;

    q.Enqueue(40);
    q.Enqueue(50);
    std::cout <<"Front: " << q.front() << std::endl;
    std::cout <<"Back: " << q.back() << std::endl;
    std::cout <<"Size: " << q.Size() << std::endl;

    
    std::cout << "Dequeued: " << q.Dequeue() << std::endl;

    // Testing Queue Clearing
    q.Clear();
    std::cout<<"Is the queue empty? " << (q.Empty()) << std::endl;

    return 0;
}