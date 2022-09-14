#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::set<std::string> str_set;
    int count = 0;
    while(N--) {
        std::string temp;
        std::cin >> temp;
        str_set.insert(temp);
    }

    while(M--) {
        std::string temp;
        std::cin >> temp;
        auto it = str_set.begin();

        it = str_set.find(temp);
        if(it != str_set.end())
            count++;
    }
    std::cout << count;
    return 0;
}