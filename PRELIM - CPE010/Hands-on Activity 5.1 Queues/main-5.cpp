#include <iostream>
#include <queue>

void DisplayAll(std::queue<char> CopyQ) {
    // Create a copy of the quque
        // loop until its empty
        while(!CopyQ.empty()) {
            std::cout << CopyQ.front();
            //dequeue the front
            CopyQ.pop();
            //display the front
        }
        std::cout << std::endl;
    }

int main() {

    // Creating an object
    std::queue<char> myQ;

    // Using the Enqueue operation
    myQ.push('T');
    myQ.push('O');
    myQ.push('M');
        std::cout << "Current Front is: " << myQ.front() << "\n";
        std::cout << "Current Back is: " <<myQ.back() << std::endl;

    // Dequeue
    std::cout << "The current Queue Contains: " << std::endl;
    DisplayAll(myQ);
    myQ.pop();
    DisplayAll(myQ);
    myQ.pop();
    DisplayAll(myQ);
    myQ.pop();

    //check if the queue is empty.
    std::cout << "Is the Queue Empty?" << " " << myQ.empty() << std::endl;

    // Using the Dequeue operation

    return 0;
};
