#include <iostream>
#include <string>

#define MaxCap 50

char ArrStack[MaxCap];
int Index = -1;

// Push
void Push(char StackData) {
    if (Index == MaxCap -1) {
        std::cout << "Stack is Currently Overflowing" << std::endl;
        return;
    }

    ArrStack[++Index] = StackData;
}

// Pop
char Pop() {
    if (Index == -1) {
        std::cout << "Stack is Currently Underflow." << std::endl;
        return '\0';
    }

    return ArrStack[Index--];
}

// isEmpty
bool isEmpty() {
    if (Index == -1) 
        return true;
    
    return false;
}


bool Matching(char Num1, char Num2) {
    if (Num1 == Pop() && Num2 == Pop())
    return true;

    return false;
}

bool Balanced(const std::string expression) { 
    for(char op: expression) {
        if (op == '1' || op == '2' || op == '3') {
            Push(op);
        }
        else if (op == '1' || op == '2' || op == '3') {
        if (isEmpty())
        return false;

        char StackTop = Pop();

        if (!Matching(StackTop, op))
        return false;
        }
    }
    return isEmpty();
}

int main() {
    std::string Input;
    std::cout << "Please Enter an Sequence: \n ";
    std::getline(std::cin, Input);

    if (Balanced(Input)) {
        std::cout << "The Expression is Symmetrical." <<std::endl;
    }
    else {
        std::cout << "The Expression isn't Symmetrical." << std::endl;
    }

    return 0;
}

