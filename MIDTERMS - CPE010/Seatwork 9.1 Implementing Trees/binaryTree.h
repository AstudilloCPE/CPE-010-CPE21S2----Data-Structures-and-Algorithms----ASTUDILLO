#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
class BinaryTree {
    private:
    T key;
    // Pointers
    BinaryTree<T>* leftChild;
    BinaryTree<T>* rightChild;


    public:

    // Constructor
    BinaryTree(T rootObj);

    // Inserting Function
    void insertLeftChild(T newNode);
    void insertRightChild(T newNode);

    //pointer
    BinaryTree<T>* getLeftChild();
    BinaryTree<T>* getRightChild();

    // Get Values & Set Values
    T getRootVal();
    void setRootVal(T obj);

    // Boolean function to check if the node is a leaf
    bool isLeaf();

};

template <typename T>
BinaryTree<T>::BinaryTree(T rootObj) {
    key = rootObj;
    leftChild = nullptr;
    rightChild = nullptr;
}

template <typename T>
void BinaryTree<T>::insertLeftChild(T newNode) {

    if(leftChild == nullptr) {
        leftChild = new BinaryTree<T>(newNode);
    }
    else {
        // Create a new Node
        BinaryTree<T> *newChild = new BinaryTree<T>(newNode);

        // Move the existing leftChild below the new Node
        newChild->leftChild = leftChild;
        leftChild = newChild;
    }
}


template <typename T>
void BinaryTree<T>::insertRightChild(T newNode) {
    if(rightChild == nullptr) {
        rightChild = new BinaryTree<T>(newNode);
    }
    else {
        // Create a new Node
        BinaryTree<T> *newChild = new BinaryTree<T>(newNode);

        // Move the existing leftChild below the new Node
        newChild->rightChild = rightChild;
        rightChild = newChild;
    }
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild() {
   return leftChild;

}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild() {
   return rightChild;
}

template <typename T>
T BinaryTree<T>::getRootVal() {
    return key;
}

template <typename T>
void BinaryTree<T>::setRootVal(T obj) {
    key = obj;
}

template <typename T>
bool BinaryTree<T>::isLeaf() {

    return leftChild == nullptr && rightChild == nullptr;
}

#endif