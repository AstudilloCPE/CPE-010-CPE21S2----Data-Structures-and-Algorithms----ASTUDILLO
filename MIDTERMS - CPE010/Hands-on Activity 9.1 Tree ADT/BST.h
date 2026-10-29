#ifndef BST_H
#define BST_H

template <typename T>
class BinarySearchTree {
    private:
    // Create a key
    T key;
    // Pointers for left and right
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;

    public:
    // Constructor
    BinarySearchTree(T value);

    //insert left and right
    void insert(T value);

    //traversing
    void preOrder();
    void inOrder();
    void postOrder();

    //searching


};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    key = value;
    left = nullptr;
    right = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T value) {
    // left or right
    
    // go left if the value is < key insert to left
    if(value < key) {
        if (left == nullptr) {
            left = new BinarySearchTree<T>(value);
        }
        else {
            left->insert(value);
        }
    }
    // go right if the value is > key
    else if(value > key) {
        if (right == nullptr) {
            right = new BinarySearchTree<T>(value);
        }
        else {
            right->insert(value);
        }
    }
}

template <typename T>
void BinarySearchTree<T>::preOrder() {

    std::cout << key << " ";

    if (left != nullptr) {
        left->preOrder();
    }
    if (right != nullptr) {
        right->preOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::inOrder() {

    if (left != nullptr) {
        left->inOrder();
    }

    std::cout << key << " ";

    if (right != nullptr) {
        right->inOrder();
    }
}

template <typename T>
void BinarySearchTree<T>::postOrder() {
    
    if (left != nullptr) {
        left->postOrder();
    }

    if (right != nullptr) {
        right->postOrder();
    }

    std::cout << key << " ";

}


#endif