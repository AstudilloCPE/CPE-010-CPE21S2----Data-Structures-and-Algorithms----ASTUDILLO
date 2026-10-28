#ifndef QUEUE_ARR_H
#define QUEUE_ARR_H
#include <iostream>

template <typename T>
class queueArr{
    private:
    // Pointer to dynamically allocate a memory in an array
    T* q_array;
    // Maximum Capacity
    size_t q_capacity;
    // Delcare current number of Elements in queue
    size_t q_size;
    // Index of the Front and Back elements
    int q_front;
    int q_back;

    public:
    // Constructor
    queueArr(size_t capacity = 10);

    // Destructor
    ~queueArr();

    // Copy Constructor
    queueArr(const queueArr& other);

    // Copy assignment operator
    queueArr& operator = (const queueArr& other);

    

    // Queue Operators
    bool Empty();
    bool Full();

    size_t Size();
    void Clear();

    T front();
    T back();

    void Enqueue(T value);
    T Dequeue();

    #endif
};

// Constructor
template <typename T>
queueArr<T>::queueArr(size_t capacity) {
    // Capacity, q_array, q_size, q_front, q_back
    q_capacity = capacity;

    q_size = 0;
    q_front = 0;
    q_back = -1;

    q_array = new T[capacity];
}

// Destructor
template <typename T>
queueArr<T>::~queueArr() {
    delete[] q_array;
}

// Copy Constructor
template <typename T>
queueArr<T>::queueArr(const queueArr& other) {
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    q_array = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }
}

// Copy Assingment Operator
template <typename T>
queueArr<T>& queueArr<T>::operator = (const queueArr& other) {
    if (this == &other) {
        return *this;
    }

    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    q_array = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }

    return *this;

}

// Empty()
template <typename T>
bool queueArr<T>::Empty() {
    return q_size == 0;
}

// Full()
template <typename T>
bool queueArr<T>::Full() {
    return q_size == q_capacity;
}

// Size_T
template <typename T>
size_t queueArr<T>::Size() {
    return q_size;
}

// Front
template <typename T>
T queueArr<T>::front() {
    if (Empty()) { 
        std::cout << "Queue is currently Empty.";
        return T();
    }
    return q_array[q_front];
}
// Back
template <typename T>
T queueArr<T>::back() {
if (Empty()) { 
        std::cout << "Queue is currently Empty.";
        return T();
    }
    return q_array[q_back];
}

// Clear
template <typename T>
void queueArr<T>::Clear() {
    q_size = 0;
    q_front = 0;
    q_back = -1;
}
// Enqueue
template <typename T>
void queueArr<T>::Enqueue(T value) {
    // Check if the queue is Full
    if (Full()) {
        std::cout << "Queue is currently Full.";
        return;
    }

    // Move Q_back Circularly
    q_back = (q_back + 1) % q_capacity;

    // Store the value to the back
    q_array[q_back] = value;

    // increment the q_size
    q_size++;
}
// Dequeue
template <typename T>
T queueArr<T>::Dequeue() {
    // Check if Empty
     if (Empty()) {
        std::cout << "Queue is currently Empty.";
        return T();
    }

    // Create a temporary variable to store the current front
    T tempVar = q_array[q_front];

    //move q_front circularly
    q_front = (q_front + 1) % q_capacity;

    // Decrement the q_size
    q_size--;

    //reset the indexes if the queues become empty
    if (Empty()) {
        Clear();
        return T();
    }

    // Return the temporary variable
    return tempVar;

    
}