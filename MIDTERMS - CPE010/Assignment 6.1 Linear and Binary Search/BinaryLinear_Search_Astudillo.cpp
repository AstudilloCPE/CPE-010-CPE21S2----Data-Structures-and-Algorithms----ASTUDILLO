#include <iostream>

// Linear Search
int LinearSearch(int list[], int listsize, int search) {
    // Searches every element in the array list
    // If the targeted value is found, print the if statement and return the targeted.
    for (int i = 0; i < listsize; i++) {
        if (list[i] == search) {
            std::cout << "\nNumber Found in the List!";
            return i;
        } 
    // If the targeted value wasn't found, or if it reaches the end of the list, print out the else statement.
        else 
            if (i == listsize - 1) {
                std::cout << "\nNumber not found in the list.";
        }
    }
    // Return -1; signals the terminal that the element wasn't found in the list.
    return -1;
}

// Binary Search
int BinarySearch(int list[], int listsize, int Num) {
    // Initializes the upper and lower part of the array list
    int low = 0;
    int up = listsize - 1;
    int f = 0, i;

    // This part continues to search the array list if the lower bound is less than equal to the upper bound by dividing each interval.
    while (low <= up) {
    // Find the middle of the list using a new variable
        int mid = (low + up) / 2;
    // If the targeted element is found print the if statement and return the indexed number.
        if (list[mid] == Num) {
            std::cout << "\nNumber Found in the List!";
            return mid;
        }
    // If the middle element is greater than the targeted value, search the left half
        else if (list[mid] > Num) {
            up = mid - 1;
        }
    // On the other hand, if the middle element is smaller than the target value, search the right half
        else {
            low = mid + 1;
        }
    }
    // If the BinarySearch doesn't find the targeted value or reaches the end of the list, print out a failure message.
    std::cout << "\nNumber not found in the list.";
    // Return -1; signals the terminal that the element wasn't found in the list.
    return -1; 
}

// main
int main() {
    // Initializes the size of the dataset and the targeted number
    int datasize;
    int targetnumber;
    // Asks the user the size of the dataset.
    std::cout << "Please Enter The Dataset Size: ";
    std::cin >> datasize;
    // This part of the code then creates a pointer named 'list' where list creates a new array dataset using new int[datasize];
    // 'new int[datasize]' dynamically allocates an array of integers on the heap
    // The user determines the size of the dataset using datasize as the basis of the array
    int* list = new int[datasize];

    // Asks the number data that the user wishes to allocate into the newly created array
    // The amount of data that can be stored is dependent on what the user inputted in datasize
    std::cout << "Enter " << datasize << " numbers: \n";
    for (int i = 0; i < datasize; i++) {
        std::cin >> list[i];
    }
    // It then asks the user what number they are using for specifically in the dataset.
    // targetnumber is number the LinearSearch and Binary Search should be looking for in the dataset
    std::cout << "Please Enter a Number to Search in the list: ";
    std::cin >> targetnumber;
    // This part calls the BinarySearch function, which passes the list, datasize, and the targeted number.
    // If linear search doesnt return -1 to the function, then the element was successfully found in the list.
    int linearResult = LinearSearch(list, datasize, targetnumber);
    if (linearResult != -1)
        std::cout << "\nLinear Search has determined its in element number: " << linearResult << std::endl;

    // This part calls the BinarySearch function, which passes the list, datasize, and the targeted number.
    // If binary search doesnt return -1 to the function, then the element was successfully found in the list.
    int binaryResult = BinarySearch(list, datasize, targetnumber);
    if (binaryResult != -1)
        std::cout << "\nBinary Search has determined its in element number: " << binaryResult << std::endl;


    return 0;
}