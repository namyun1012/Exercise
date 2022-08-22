#include <iostream>
#include <string>
#define MAX 10000

class Stack {
public:
    Stack() {topIndex = -1;}

    void SPush(int x) {
        topIndex++;
        this->stack[topIndex] = x;
        
    }

    int SPop() {
        if(SEmpty()) return -1;

        int rData = stack[topIndex];
        topIndex -= 1;
        return rData;
    }

    int SSize() {

        return topIndex+1;
    }

    int SEmpty() {
        if(topIndex == -1) return 1;
        else return 0;

    }

    int STop() {
        if(SEmpty()) return -1;
        return stack[topIndex];
    }


private:
    int stack[MAX];
    int topIndex;
    
};


int main() {
    Stack s;   
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        std::string order;
        std::cin >> order;
        if(order == "push") {
            int ele;
            std::cin >> ele;
            s.SPush(ele);
        }

        else if(order == "pop") {
            int ele = s.SPop();
            std::cout << ele << "\n";
        }

        else if(order == "size") {
            int ele = s.SSize();
            std::cout << ele << "\n";
        }

        else if(order == "empty") {
            int ele = s.SEmpty();
            std::cout << ele << "\n";
        }

        else if(order == "top") {
            int ele = s.STop();
            std::cout << ele << "\n";
        }
    }


    return 0;
}