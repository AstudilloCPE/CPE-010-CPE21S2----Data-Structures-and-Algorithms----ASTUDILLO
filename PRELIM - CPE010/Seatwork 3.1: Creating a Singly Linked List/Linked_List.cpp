#include <iostream>
#include "Single_ll.h"

int main() {
    // Creationg of node/s for "THOMAS"
    SingleList<char>* header = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;
    SingleList<char>* fourth = nullptr;
    SingleList<char>* fifth = nullptr;
    SingleList<char>* sixth = nullptr;

    header = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    fourth = new SingleList<char>;
    fifth = new SingleList<char>;
    sixth = new SingleList<char>;

    header->data = 'T';
    second->data = 'H';
    third->data = 'O';
    fourth->data = 'M';
    fifth->data = 'A';
    sixth->data = 'S';


    //Link the node
    header->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = nullptr;

    std::cout << header << std::endl;
    std::cout << second << std::endl;
    std::cout << third << std::endl;
    std::cout << fourth << std::endl;
    std::cout << fifth << std::endl;
    std::cout << sixth << std::endl;
    
    std::cout << "Testing of traversal:\n";
    ListTraversal(header);

    std::cout << "Testing of stllinsertHeader: \n";
    sllinsertheader('S', &header);
    ListTraversal(header);

    std::cout << "Testing the generalinsert: \n";
    stllGeneralInserter('G', header->next->next);
    ListTraversal(header);

    std::cout << "Testing the InsertEnd: \n";
    stllInsertEnd('G', &header);
    ListTraversal(header);

    std::cout << "Testing of DeleteNode: \n";
    stllDeleteNode('O', &header);
    ListTraversal(header);

    std::cout<< "Deleting All Nodes. \n";
    stllDeleteAllNodes(&header);
    ListTraversal(header);


    return 0;
}