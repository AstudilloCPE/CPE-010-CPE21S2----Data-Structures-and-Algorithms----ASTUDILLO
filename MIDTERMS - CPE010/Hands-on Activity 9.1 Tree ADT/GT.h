#ifndef GT_H
#define GT_H

template <typename T>
class GeneralTree {
    private:

    T key;
    GeneralTree<T>* firstChild;
    GeneralTree<T>* nextChild;

    public:

    GeneralTree(T value);

    void addChild(T value);

    GeneralTree<T>* searcher(T value);

    void preOrder_GT();
    void postOrder_GT();
    void inOrder_GT();

    void findData(int CHOICE, T KEY);

    void addLeaf(T parentValue, T leafValue);
};

template <typename T>
GeneralTree<T>::GeneralTree(T value) {
    key = value;
    firstChild = nullptr;
    nextChild = nullptr;
}

template <typename T>
void GeneralTree<T>::addChild(T value) {
    if (firstChild == nullptr) {
        firstChild = new GeneralTree<T>(value);
    }
    else {
        GeneralTree<T>* current = firstChild;
        while (current->nextChild != nullptr) {
            current = current->nextChild;
        }
        current->nextChild = new GeneralTree<T>(value);
    }
}

template <typename T>
GeneralTree<T>* GeneralTree<T>::searcher(T value) {
    if (key == value) {
        return this;
    }

    if (firstChild != nullptr) {
        GeneralTree<T>* found = firstChild->searcher(value);
        if (found != nullptr) return found;
    }

    if (nextChild != nullptr) {
        GeneralTree<T>* found = nextChild->searcher(value);
        if (found != nullptr) return found;
    }

    return nullptr;
}

template <typename T>
void GeneralTree<T>::preOrder_GT() {

    std::cout << key << " ";

    if (firstChild != nullptr) {
        firstChild->preOrder_GT();
    }
    if (nextChild != nullptr) {
        nextChild->preOrder_GT();
    }
}

template <typename T>
void GeneralTree<T>::inOrder_GT() {


    if (firstChild != nullptr) {
        firstChild->preOrder_GT();
    }
    std::cout << key << " ";
    if (nextChild != nullptr) {
        nextChild->preOrder_GT();
    }
}

template <typename T>
void GeneralTree<T>::postOrder_GT() {

    if (firstChild != nullptr) {
        firstChild->postOrder_GT();
    }
    if (nextChild != nullptr) {
        nextChild->postOrder_GT();
    }

    std::cout << key << " ";
    
}

template <typename T>
void GeneralTree<T>::findData(int CHOICE, T KEY) {
    if (CHOICE == 1) {
        if (key == KEY) {
            std::cout << KEY << " was found! ";
            return;
        }
        if (firstChild != nullptr) {
            firstChild->findData(CHOICE, KEY);
        }
        if (nextChild != nullptr) {
            nextChild->findData(CHOICE, KEY);
        }
    }
    else if (CHOICE == 2) {
        if (firstChild != nullptr) {
            firstChild->findData(CHOICE, KEY);
        }
        if (key == KEY) {
            std::cout << KEY << " was found! ";
            return;
        }
        if (nextChild != nullptr) {
            nextChild->findData(CHOICE, KEY);
        }
    }
    else if (CHOICE == 3) {
        if (firstChild != nullptr) {
            firstChild->findData(CHOICE, KEY);
        }
        if (nextChild != nullptr) {
            nextChild->findData(CHOICE, KEY);
        }
        if (key == KEY) {
            std::cout << KEY << " was found! ";
            return;
        }
    }

}

template <typename T>
void GeneralTree<T>::addLeaf(T parentValue, T leafValue) {
    GeneralTree<T>* parentNode = searcher(parentValue);
    if (parentNode != nullptr) {
        parentNode->addChild(leafValue);
    }
}

#endif