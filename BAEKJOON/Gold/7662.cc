#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
class doublequeue {
public: 

    doublequeue() {}

    std::multiset<int> s;
    size_t size = 0;
    int max_ele;
    int min_ele;
    
    

    void insert(int ele) {
        s.insert(ele);
        size+=1;
    }

    void pop(int order) {
        std::multiset<int>::iterator it;
        if(size == 0) {
            return;
        }
        
        
        if(order == 1) { // max
            it = s.end();
            it--;
            s.erase(it);
        }

        else if(order == -1) {
           s.erase(s.begin());
        }
        size -= 1;
    }
    bool isempty() {
        if(size == 0) return true;
        else return false;
    }


    int getsize() {
        return size;
    }

    int get_min() {
        return *s.begin();
    }

    int get_max() {
        return *s.rbegin();
    }

};

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int T;
    std::cin >> T;

    while(T--) {
        doublequeue que;
        int k;
        std::cin >> k;
        
        char order;
        int order_number;
        
        while(k--) {
            std::cin >> order;
            if(order == 'I') {
                std::cin >> order_number;
                que.insert(order_number);
            }

            else if(order == 'D') {
                std::cin >> order_number;
                que.pop(order_number);
            }
        }

        if(que.isempty()) {
            std::cout << "EMPTY" << "\n";
        }

        else {
            std::cout << que.get_max() << " " << que.get_min() << "\n";
        }
    }

    return 0;
}