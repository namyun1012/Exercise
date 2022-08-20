#include <iostream>
#include "DBLinkedList.h"

void ListInit(List *plist){
    plist->cur = NULL;
    plist ->head = NULL;
    plist ->numOfData = 0;

}
void LInsert(List *plist, Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->data = data;

    newNode -> next = plist->cur->next;
    plist->cur->next->prev = newNode;
    newNode -> prev = plist->cur;
    plist->cur = newNode;
    (plist->numOfData)++ ;

}

int LFirst (List *plist, Data* pdata) {
    if(plist->head == NULL)
        return FALSE;

    *pdata = plist->head->next->data;
    plist->cur = plist->head->next;
    return TRUE;
    
}
int LNext (List *plist, Data* pdata) {
    if(plist->cur->next == NULL)
        return FALSE;

    *pdata = plist->cur->next->data;
    plist->cur = plist->cur->next;
    return TRUE;
}

int LPrevious (List *plist, Data* pdata) {
    if(plist->cur->prev == NULL)
        return FALSE;

    *pdata = plist->cur->prev->data;
    plist->cur = plist->cur->prev;
    return TRUE;
}

int LCount(List *plist) {
    return plist->numOfData;

}