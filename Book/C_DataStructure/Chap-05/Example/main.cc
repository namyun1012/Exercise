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
        printf("%d ",data);

        while(LNext(&list, &data)) {
            std::cout << data << " ";
            
        }

        while(LPrevious(&list, &data)) {
            std::cout << data << " ";
            
        }
    }

    
    std::cout << "\n";
    std::cout << 1 << std::endl ;
    return 0;
}