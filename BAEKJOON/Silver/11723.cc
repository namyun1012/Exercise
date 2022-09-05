#include <iostream>
#include <set>
#include <string>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int N;
    std::cin >> N;
    std::set<int> s;
    std::set<int>::iterator it = s.begin();

    for(int i = 0; i < N; i++) {
        std::string order;
        std::cin >> order;
        int x; // x를 이쪽으로 옮기는 것이 빨라짐
        if(order == "add") {
            
            std::cin >> x;
            s.insert(x);
        }

        else if(order == "check") {
            
            std::cin >> x;
            it = s.find(x);
            if(it == s.end())
                std::cout << 0 << "\n";
            else
                std::cout << 1 << "\n";
            
        }

        else if(order == "remove") {
            
            std::cin >> x;
            s.erase(x);
        }

        else if(order == "toggle") {
            
            std::cin >> x;
            it = s.find(x);
            if(it == s.end())
                s.insert(x);
            else
                s.erase(x);
        }

        else if(order == "all") {
            s = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
            
        }

        else if(order == "empty") {
            s.clear();
        }
    }

    return 0;
}