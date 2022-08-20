#include <iostream>
#include "DBLinkedList.h"

int main() {
    List list;
    int data;

    ListInit(&list);

    LInsert(&list, 1); LInsert(&list, 2);
    LInsert(&list, 3); LInsert(&list, 4);
    LInsert(&list, 5); LInsert(&list, 6);
    LInsert(&list, 7); LInsert(&list, 8);

    if(LFirst(&list, &data)) {
        std::cout << data <<" ";

        while(LNext(&list, &data)) {
            std::cout << data << " ";
            
        }

        while(LPrevious(&list, &data)) {
            std::cout << data << " ";
            
        }
    }

    else
        std::cout << "List is empty" << "\n";

    std::cout << "\n";
    return 0;
}