#include <iostream>
#include "binaryTree.h"

main() {

    BinaryTree<char>* root = new BinaryTree<char>('A');


    root->insertLeftChild('B');
    root->insertRightChild('C');
    
    //insert a Child to node B
    root->getLeftChild()->insertLeftChild('D');
    root->getLeftChild()->insertRightChild('F');

    //insert a child to node C
    root->getRightChild()->insertLeftChild('E');
    
    // Get the root Node
    std::cout << "Current Root Node: " << root->getRootVal() << std::endl;

    std::cout<< "\nRoot Node for A: " << std::endl;
    std::cout << "Left Root Node: " << root->getLeftChild()->getRootVal() << std::endl;
    std::cout << "Right Root Node: " << root->getRightChild()->getRootVal() << std::endl;

    std::cout<< "\nRoot Node for B: " << std::endl;
    std::cout << "Left Root Node: " << root->getLeftChild()->getLeftChild()->getRootVal() << std::endl;
    std::cout << "Right Root Node: " << root->getLeftChild()->getRightChild()->getRootVal() << std::endl;

    std::cout<< "\nRoot Node for C: " << std::endl;
    std::cout << "Left Root Node: " << root->getRightChild()->getLeftChild()->getRootVal() << std::endl;

    root->getLeftChild()->getRightChild()->setRootVal('E');
    
    std::cout << "\nIs root A a leaf? " << (root->isLeaf() ? "Yes" : "No") << std::endl;
    return 0;
}
