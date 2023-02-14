#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node * prev;
    Node * next;
};


template <typename T>
class DLL {
private:
    Node<T> * head;
    Node<T> * tail;
    int size;

public:
    DLL() {
        head = new Node<T>;
        tail = new Node<T>;

        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    // push_back
    void push_back(T data) {
        Node<T> * newNode = new Node<T>;
        newNode->value = data;
        newNode->next = tail;
        newNode->prev = tail->prev;

        tail->prev->next = newNode;
        tail->prev = newNode;
        size++;    
    
    }

    T pop_back() {
        Node<T>* deleteNode = tail->prev;
        tail->prev =deleteNode->prev;
        deleteNode->prev->next = tail;
        
        T deletedData = deleteNode->value;
        free(deleteNode);
        size--;
        return deletedData;
    }

    void printList() {
        Node<T> * curNode = head->next;
        while(curNode != tail) {
            cout << curNode->value << " ";
            curNode = curNode->next;
        }

        cout << "\n";
    }
    
    

    int getSize() {
        return size;
    }

};

int main() {
    DLL<int> list;

    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.printList();

    list.pop_back();
    list.pop_back();
    list.printList();

    return 0;
}