#include <iostream>

#define Queue_LEN 10000
class Node {
public:
    int data;
    Node* next;
};

class Queue {
public:
    Queue() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void QPush(int data) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        
        if(this->head == NULL) {
            this->head = newNode;
            this->tail = newNode;
            newNode->next = NULL;
        }
        else {
            this->tail->next = newNode;
            this->tail = newNode;
            newNode->next = NULL;
            
        }
        size++;
    }

    int QEmpty() {
        if(size == 0) return 1;
        else return 0;
    }
    
    int QPop() {
        if(QEmpty()) return -1;

        int rData;
        Node* rNode;

        rNode = this->head;
        rData = rNode ->data;

        this->head = this->head->next;

        free(rNode);
        size-=1;
        return rData;
    }

    int QFront() {
        if(QEmpty()) return -1;

        return this->head->data;
    }

    int QBack() {
        if(QEmpty()) return -1;
        
    

        return this->tail->data;
    }

    int QSize() {
        return this->size;
    }
private:
    Node* head;
    Node* tail;
    int size;

};




int main() {
    Queue s;   
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        std::string order;
        std::cin >> order;
        if(order == "push") {
            int ele;
            std::cin >> ele;
            s.QPush(ele);
        }

        else if(order == "pop") {
            int ele = s.QPop();
            std::cout << ele << "\n";
        }

        else if(order == "size") {
            int ele = s.QSize();
            std::cout << ele << "\n";
        }

        else if(order == "empty") {
            int ele = s.QEmpty();
            std::cout << ele << "\n";
        }

        else if(order == "front") {
            int ele = s.QFront();
            std::cout << ele << "\n";
        }
        else if(order == "back") {
            int ele = s.QBack();
            std::cout << ele << "\n";
        }
    }


    return 0;
}