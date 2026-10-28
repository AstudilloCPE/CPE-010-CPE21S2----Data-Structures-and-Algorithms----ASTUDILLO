#include <iostream>


#define maxCap 10

int stackArr[maxCap];
int top = -1;
int newData;


void Push();
void Pop();
void Top();
bool isEmpty();
bool isFull();
void DisplayStack();

int main() {
    int choice;
    while(true) {
        std::cout << " =======================================================" << std::endl;
        std::cout << "Stack Operation Menu: " << std::endl;
        std::cout << " 1. PUSH \n 2. POP \n 3. TOP \n 4. isEmpty \n 5. isFull \n 6. DisplayStack \n" << std::endl;
        std::cout << " =======================================================" << std::endl;

        std::cin>>choice;

        switch(choice) {
            case 1: Push();
            break;
            case 2: Pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout << "Is the Stack empty?: " << isEmpty() << std::endl;
            break;
            case 5: std::cout << "Is the Stack full?: " << isFull() << std::endl;
            break;
            case 6: DisplayStack();
            break;
            default: std::cout << "Invalid Choice." << std::endl;
            break;
        }
    }

    return 0;
}



bool isEmpty() {
    if(top == -1) return true;
    return false;
}

bool isFull() {
    if(top == maxCap -1) return true;
    
    return false;
}

void Push() {
    if(isFull()) {
        std::cout << "Stack is currently full." << std::endl;
        return;
    }

    std::cout << "Please enter a new value: " << std::endl;
    std::cin >> newData;

    stackArr[++top] = newData;
}

void Pop() {
    if(isEmpty()) {
        std::cout << "Stack is underflow" << std::endl;
    }

    std::cout <<"Popping: " << stackArr[top] << std::endl;
    top--;

}

void Top() {
    if(isEmpty()) {
        std::cout << "Stack is currently empty." << std::endl;
        return;
    }
    std::cout<< "Top Elements: " << stackArr[top] << std::endl;
}

void DisplayStack() {       

    if(isEmpty()) {
        std::cout << "Stack is currently Empty." << std::endl;
        return;
    }

    std::cout << "The Stack Contains: " << std::endl;
    for (int i = top; i >= 0; i--) {
        std::cout << stackArr[i] << std::endl;
    }


}
