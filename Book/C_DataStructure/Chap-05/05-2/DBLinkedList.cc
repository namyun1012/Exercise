#include <iostream>
#include "DBLinkedList.h"

void ListInit(List *plist){
    plist -> cur = NULL;
    plist ->head = (Node*)malloc(sizeof(Node));
    plist ->tail= (Node*)malloc(sizeof(Node));
    plist->head->prev = NULL;
    plist->head->next = plist->tail;
    plist->tail->next = NULL;
    plist->tail->prev = plist->head;
   
    plist ->numOfData = 0;

}
void LInsert(List *plist, Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->data = data;

    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;
    
    newNode->next = plist->tail;
    plist->tail->prev = newNode;
    
    plist->numOfData +=1;

}

int LFirst (List *plist, Data* pdata) {
    if(plist->head->next == plist->tail)
        return FALSE;

    
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
    
}
int LNext (List *plist, Data* pdata) {
    if(plist->cur->next == plist->tail)
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LPrevious (List *plist, Data* pdata) {
    if(plist->cur->prev == plist->head)
        return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return TRUE;
}

int LCount(List *plist) {
    return plist->numOfData;

}

Data LRemove(List *plist) {
    Data rData = plist->cur->data;
    Node *rNode = plist->cur;

    rNode->prev->next = rNode->next;
    rNode->next->prev = rNode->prev;

    plist->cur = rNode ->next;
    free(rNode);
    plist->numOfData -= 1;
    return rData;

}