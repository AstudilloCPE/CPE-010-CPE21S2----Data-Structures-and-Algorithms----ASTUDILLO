#include <iostream>
#include "Printer_queue_arr.h"

int main() {
    PrinterQueue<Job> Print(5);
    // Enqueues the people who wish to use the printer along with their Queue ID and Page amount.
    Print.Enqueue(Job(1, "Gabriel", 5));
    Print.Enqueue(Job(2, "Matt", 7));
    Print.Enqueue(Job(3, "Scotty", 15));
    Print.Enqueue(Job(4, "Scooby", 8));
    Print.Enqueue(Job(5, "Shaggy", 19));



    while(!Print.Empty()) {
        std::cout << "\n";
        Job current = Print.Dequeue();
        std::cout << "Printing Request No. " << current.jobID << 
        " from " << current.user << " (Pages Requested: " 
        << current.pages << " Pages)" << std::endl;


        std::cout << "Requeuest No. " << current.jobID << ": " 
        << current.user << " Has Finished Printing! \n" 
        << "They've printed a total of: " << current.pages << " Pages" << std::endl;
        }

    return 0;
}