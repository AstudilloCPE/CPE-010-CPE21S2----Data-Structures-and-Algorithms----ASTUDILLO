#include <iostream>
#include <thread>


int global_var = 0;


void add(int value) {
    global_var += value;
}


int main() {
    std::cout << "Initial global_var: " << global_var << std::endl;


    std::thread t1(add, 5);
    std::cout << "After spawning T1 (before join): " << global_var << std::endl;
    t1.join();
    std::cout << "After T1.join(): " << global_var << std::endl;


    std::thread t2(add, 10);
    std::cout << "After spawning T2 (before join): " << global_var << std::endl;
    t2.join();
    std::cout << "After T2.join(): " << global_var << std::endl;


    std::thread t3(add, 15);
    std::cout << "After spawning T3 (before join): " << global_var << std::endl;
    t3.join();
    std::cout << "After T3.join(): " << global_var << std::endl;


    std::cout << "Final global_var: " << global_var << std::endl;
    return 0;
}