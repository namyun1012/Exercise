#include <iostream>

#define Queue_LEN 10000
class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class Deque {
public:
    Deque() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void DPush_front(int data) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        
        if(this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            newNode->prev = NULL;
            
        }
        size++;
    }

    void DPush_back(int data) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        
        if(this->tail == NULL) {
            this->head = newNode;
            this->tail = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
        }
        else {
            newNode->prev = tail;
            this->tail->next = newNode;
            this->tail = newNode;
            newNode->next = NULL;
            
        }
        size++;
    }

    int DEmpty() {
        if(size == 0) return 1;
        else return 0;
    }
    
    int DPop_front() {
        if(DEmpty()) return -1;

        int rData;
        Node* rNode;

        rNode = this->head;
        rData = rNode ->data;
        if(head->next == NULL) {
            this->head = NULL;
            this->tail = NULL;
        }
        else {
            this->head = this->head->next;
            head->prev = NULL;
        }
        free(rNode);
        size-=1;
        return rData;
    }

    int DPop_back() {
        if(DEmpty()) return -1;

        int rData;
        Node* rNode;

        rNode = this->tail;
        rData = rNode->data;
        if(tail->prev == NULL) {
            tail = NULL;
            this->head = NULL;
        }
        else {
            this->tail = this->tail->prev;
            tail->next = NULL;
        }
        free(rNode);
        size-=1;
        return rData;
    }

    int DFront() {
        if(DEmpty()) return -1;

        return this->head->data;
    }

    int DBack() {
        if(DEmpty()) return -1;
        
    

        return this->tail->data;
    }

    int DSize() {
        return this->size;
    }
private:
    Node* head;
    Node* tail;
    int size;

};




int main() {
    std::ios::sync_with_stdio(false); // 시간
    std::cin.tie(NULL);

    Deque s;   
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        std::string order;
        std::cin >> order;
        if(order == "push_back") {
            int ele;
            std::cin >> ele;
            s.DPush_back(ele);
        }

        else if(order == "push_front") {
            int ele;
            std::cin >> ele;
            s.DPush_front(ele);
        }

        else if(order == "pop_back") {
            int ele = s.DPop_back();
            std::cout << ele << "\n";
        }

        else if(order == "pop_front") {
            int ele = s.DPop_front();
            std::cout << ele << "\n";
        }

        else if(order == "size") {
            int ele = s.DSize();
            std::cout << ele << "\n";
        }

        else if(order == "empty") {
            int ele = s.DEmpty();
            std::cout << ele << "\n";
        }

        else if(order == "front") {
            int ele = s.DFront();
            std::cout << ele << "\n";
        }
        else if(order == "back") {
            int ele = s.DBack();
            std::cout << ele << "\n";
        }
    }


    return 0;
}