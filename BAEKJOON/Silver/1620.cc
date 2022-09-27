#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int N,M;
    std::cin >> N >> M;
    std::map<int , std::string> m;
    std::map<std::string, int> m2;
    
    std::string temp;


    for(int i = 0; i < N; i++) {
        std::cin >> temp;
        m.insert({i+1, temp});
        m2.insert({temp, i+1});
    }
    std::string order;
   
    for(int i = 0; i < M; i++) {
        std::cin >> order;
        if(order[0] >= '0' && order[0] <= '9') {
            int tm = std::stoi(order);

            std::cout << m[tm] << "\n";
        }

        else {
            std::cout << m2[order] << "\n";
        }
    }

    return 0;

}