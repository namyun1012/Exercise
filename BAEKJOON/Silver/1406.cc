#include <iostream>
#include <list>
#include <string>

int main() {
    std::string str;
    int N;
    std::cin >> str >> N;

    std::list<char> list;
    std::list<char>::iterator it = list.begin();

    for(int i = 0; i < str.size(); i++)
        list.push_back(str[i]);
    
    
    for(int i = 0; i < N; i++) {
        char order;
        std::cin >> order;

        if(order == 'L') {
            if(it != list.begin())
                it.operator--();
        }

        else if(order == 'D') {
            if(it != list.end())
                it.operator++();
        }

        else if(order == 'B') {
            if(it != list.begin()) {
                
                std::list<char>::iterator dit = it;
                
                dit--;
                list.erase(dit);
        
            }
        }

        else if(order == 'P') {
            char c;
            std::cin >> c;
            list.insert(it,  c);
        }

    }

    it = list.begin();
    while (it != list.end()) {
        std::cout << *it++;
    }

    return 0;
}