// Astudillo, Thomas Joseph T.
// CPE21S2
#include <iostream>
#include <string>

int sumOfNumbers(int Num1, int Num2) {
    return Num1 + Num2;
}

std::string ComparingVariables(int Num1, int Num2) {
    if (Num1 > Num2) {
        return "Variable A is Greater than Variable B";
    }
    else if (Num2 > Num1) {
        return "Variable B is Greater than Variable A";
    }
    else {
        return "Variable A is Equal to Variable B";
    }
}

bool ComparingBools(bool Num1, bool Num2) {
    std::cout << std::boolalpha;
    std::cout << "AND: " << (Num1 && Num2) << std::endl;
    std::cout << "OR: " << (Num1 || Num2) << std::endl;
    std::cout << "NOT A: " << (!Num1) << std::endl;
    std::cout << "NOT B: " << (!Num2) << std::endl;
    return true;
}

int main() {
    int Num1, Num2;

    std::cout << "Please enter the First Number: ";
    std::cin >> Num1;

    std::cout << "Please enter the Second Number: ";
    std::cin >> Num2;

    std::cout << "The sum of the Two Numbers is: "
              << sumOfNumbers(Num1, Num2) << std::endl;

    std::cout << "Therefore "
              << ComparingVariables(Num1, Num2) << std::endl;

    std::cout << "Boolean Checking: " << std::endl;
    bool success = ComparingBools(Num1, Num2);


    return 0;
}