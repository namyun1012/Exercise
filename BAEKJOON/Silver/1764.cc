#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

std::string strs[500002];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int N,M;
    std::cin >> N >> M;
    std::set<std::string> result;
    int count = 0;
    std::map<std::string, int> map;
  


    std::string temp;
    for(int i = 0; i < N; i++) {
        std::cin >> temp;
        map.insert({temp, 1});
    }

    for(int i = 0; i < M; i++) {
        std::cin >> temp;
        strs[i] = temp;
    }


    for(int i = 0; i < M; i++) {
        if(map[strs[i]]) {
            result.insert(strs[i]);
            count++;
        }
    }

    std::cout << count << "\n";
    for(auto ele : result) 
        std::cout << ele << "\n";
    return 0;
}