#include <iostream>
#include "Single_ll.h"
#include "doubly.ll.h"

int main() {

    DoubleList<char>* head = CreatenewNode('C');
    DoubleList<char>* second = CreatenewNode('P');
    DoubleList<char>* third = CreatenewNode('E');

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    ListTraversal(head);

    std::cout << std::endl;

    dllinsertheader('X', &head);
    ListTraversal(head);

    std::cout << std::endl;

    dllGeneralInsert('H', head->next);
    ListTraversal(head);
    
    std::cout << std::endl;

    dllinsertEnd('Z', head);
    ListTraversal(head);

    std::cout << std::endl;

    dllDeleteNode('P', &head);
    ListTraversal(head);


    std::cout << std::endl;
    
    std::cout<< "Deleting All Nodes. \n";
    dllDeleteAllNodes(&head);
    ListTraversal(head);

    return 0;
}