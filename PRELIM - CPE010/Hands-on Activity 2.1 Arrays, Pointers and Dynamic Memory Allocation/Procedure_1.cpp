#include <iostream>
#include <string.h>

class Student {
    private:
    std::string StudentName;
    int StudentAge;

    // Constructor
    public:
    Student(std::string NewName = "Gabriel Arididon", int NewAge = 19) {
        StudentName = std::move(NewName);
        StudentAge = int(NewAge);

        //std::string* ptr = &StudentName;
        //int* ptr = &StudentAge;
        std::cout << "Constructor Successfully Called." << std::endl;
    }

    // Deconstructor
    ~Student() {
        std::cout << "Destructor Successfully Called." << std::endl;
    }

    //Copy Constructor
    Student(const Student &copyStudent) {
        std::cout << "Copy Constructor Successfully Called" << std::endl;
        StudentName = copyStudent.StudentName;
        StudentAge = copyStudent.StudentAge;
    }

    //Display Attributes

    void PrintDetails() {
        std::cout << this->StudentName << " " << this->StudentAge << std::endl;
    }
}; 

int main() {
    const size_t j = 5;
    Student studentList[j] = {};

    std::string namesList[j] = {"Bryan", "Zach", "Sammy", "Shaggy", "Scooby"};

    int ageList[j] = {15, 16, 18, 19, 16};

    //loop A
    for(int i = 0; i < j; i++) {
        Student *ptr = new Student (namesList[i], ageList[i]);
        studentList[i] = *ptr;
    }
    
    //loop B
    for(int i = 0; i < j; i++) {
        studentList[i].PrintDetails();
    }

    return 0;
}
