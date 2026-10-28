// Astudillo, Thomas Joseph T.
// CPE21S2
#include <iostream>

int main() {
    int ValueA, ValueB;
    int Swapped;
    
    std::cout << "Please Enter Your First Variable: ";
    std::cin >> ValueA;
    
    std::cout << "Please Enter Your Second Variable: ";
    std::cin >> ValueB;
    
    std::cout << "Your Original Variables are: " << std::endl;
    std::cout << "First Variable:  " << ValueA << std::endl;
    std::cout << "Second Variable: " << ValueB << std::endl;
    
    Swapped = ValueA;
    ValueA = ValueB;
    ValueB = Swapped;
    
    
    std::cout << "Your Swapped Variables are now: " << std::endl;
    std::cout << "First Variable: " << ValueA << std::endl;
    std::cout << "Second Variable: " << ValueB << std::endl;
    return 0;
}