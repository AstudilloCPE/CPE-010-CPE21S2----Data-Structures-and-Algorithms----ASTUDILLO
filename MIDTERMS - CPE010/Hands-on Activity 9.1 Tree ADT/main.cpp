#include <iostream>
#include "BST.h"
#include "GT.h"


int main () {
    /* General Tree Setup */
    GeneralTree<char> root('A');

    root.addChild('B');
    root.addChild('C');
    root.addChild('D');
    root.addChild('E');
    root.addChild('F');
    root.addChild('G');

    GeneralTree<char>* nodeD = root.searcher('D');
    if (nodeD != nullptr) {
        nodeD->addChild('H');
    }

    GeneralTree<char>* nodeE = root.searcher('E');
    if (nodeE != nullptr) {
        nodeE->addChild('I');
        nodeE->addChild('J');
    }

    GeneralTree<char>* nodeJ = root.searcher('J');
    if (nodeJ != nullptr) {
        nodeJ->addChild('P');
        nodeJ->addChild('Q');
    }

    GeneralTree<char>* nodeF = root.searcher('F');
    if (nodeF != nullptr) {
        nodeF->addChild('K');
        nodeF->addChild('L');
        nodeF->addChild('M');
    }

    GeneralTree<char>* nodeG = root.searcher('G');
    if (nodeG != nullptr) {
        nodeG->addChild('N');
        nodeG->addChild('O');
    }


    std::cout << "Pre-order Traversal: ";
    root.preOrder_GT();
    std::cout << std::endl;

    std::cout << "In-order Traversal: ";
    root.inOrder_GT();
    std::cout << std::endl;

    std::cout << "Post-order Traversal: ";
    root.postOrder_GT();
    std::cout << std::endl;

    std::cout << "\n=== Finder Tests ===\n";
    
    std::cout << "Choice 1 (Pre-order search for 'J'): ";
    root.findData(1, 'J');
    std::cout << std::endl;

    std::cout << "Choice 2 (In-order search for 'J'): ";
    root.findData(2, 'J');
    std::cout << std::endl;

    std::cout << "Choice 3 (Post-order search for 'J'): ";
    root.findData(3, 'J');
    std::cout << std::endl;

    std::cout << "Choice 1 (Pre-order search for 'O'): ";
    root.findData(1, 'O');
    std::cout << std::endl;

    /* Binary Seach Tree
    
    // Create a root node:
    BinarySearchTree<int> tree(2);
    // 2, 3, 9, 18, 0, 1, 4, 5.
    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    std::cout << "preOrder: \n";
    tree.preOrder();

    std::cout << std::endl;

    std::cout << "inOrder: \n";
    tree.inOrder();

    std::cout << std::endl;

    std::cout << "Post Order: \n";
    tree.postOrder();
*/
    

return 0;

}