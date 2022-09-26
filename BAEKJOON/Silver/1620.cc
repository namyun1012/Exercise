#include <iostream>
#include <string>
#include <vector>

int main() {
    int N,M;
    std::cin >> N >> M;
    std::vector<std::string> vec;
    std::string poketmon;
    
    for(int i = 0; i < N; i++) {
        std::cin >> poketmon;
        vec.push_back(poketmon);
    }
    std::string order;
    while(M--) {
        std::cin >> order;
        
    }
}