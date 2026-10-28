#ifndef PRINTER_QUEUE_ARR_H
#define PRINTER_QUEUE_ARR_H
#include <iostream>
#include <string>

struct Job {
    int jobID;
    std::string user;
    int pages;

    Job(int id = 0, std::string u = "", int p = 0){
         jobID = id;
         user = u;
         pages = p;
    }

};

template <typename T>
class PrinterQueue {
    private:
    // Pointer to dynamically allocate a memory in the queue
    T* q_Printer;
    // Maximum Capacity
    size_t q_capacity;
    // Delcare current number of Elements in queue
    size_t q_size;
    // Index of the Front and Back of the Queue
    int q_front;
    int q_back;

    public:
    // Constructor
    PrinterQueue(size_t capacity = 10);

    // Destructor
    ~PrinterQueue();

    // Copy Constructor
    PrinterQueue(const PrinterQueue& other);

    // Copy assignment operator
    PrinterQueue& operator = (const PrinterQueue& other);


     // Queue Operators
    bool Empty();
    bool Full();

    size_t Size();
    void Clear();

    T front();
    T back();

    void Enqueue(T value);
    T Dequeue();

};

// Constructor
template <typename T>
PrinterQueue<T>::PrinterQueue(size_t capacity) {
    // Capacity, q_Printer, q_size, q_front, q_back
    q_capacity = capacity;

    q_size = 0;
    q_front = 0;
    q_back = -1;

    q_Printer = new T[capacity];
}

// Destructor
template <typename T>
PrinterQueue<T>::~PrinterQueue() {
    delete[] q_Printer;
}

// Copy Constructor
template <typename T>
PrinterQueue<T>::PrinterQueue(const PrinterQueue& other) {
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    q_Printer = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; i++) {
        q_Printer[i] = other.q_Printer[i];
    }
}


// Copy Assignment Operator
template <typename T>
PrinterQueue<T>& PrinterQueue<T>:: operator = (const PrinterQueue& other) {
    if (this == &other) return *this;

    delete[] q_Printer;
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_Printer = new T[q_capacity];

    for (size_t i = 0; i < q_capacity; i++) {
        q_Printer[i] = other.q_Printer[i];
    }
    return *this;

}

// Queue Operators
template <typename T>
bool PrinterQueue<T>::Empty() { 
    return q_size == 0;

}

template <typename T>
bool PrinterQueue<T>::Full() { 
    return q_size == q_capacity;

}

template <typename T>
size_t PrinterQueue<T>::Size() { 
    return q_size;

}

template <typename T>
void PrinterQueue<T>::Clear() {
    q_size = 0;
    q_front = 0;
    q_back = -1;

}

//Front
template <typename T>
T PrinterQueue<T>::front() {
    if (Empty()) {
        std::cout << "Queue is currently Empty.\n";
        return T();
    }

    return q_Printer[q_front];
}

//Back
template <typename T>
T PrinterQueue<T>::back() {
    if (Empty()) {
        std::cout << "Queue is currently Empty.\n";
        return T();
    }

    return q_Printer[q_back];
}

//Enqueue
template <typename T>
void PrinterQueue<T>::Enqueue(T value) {
    if (Full()) {
        std::cout << "Queue is currently Full.\n";
        return;
    }

    q_back = (q_back + 1) % q_capacity;

    q_Printer[q_back] = value;

    q_size++;
}

// Dequeue
template <typename T>
T PrinterQueue<T>::Dequeue() {
    if (Empty()) {
        std::cout << "Queue is currently Empty.\n";
        return T();
    }

    T tempVar = q_Printer[q_front];

    q_front = (q_front + 1) % q_capacity;

    q_size--;

    if (Empty()) Clear();

    return tempVar;
}

#endif