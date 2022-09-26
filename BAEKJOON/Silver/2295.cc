#include <iostream>
#include <vector>
#include <algorithm>


int U[1003];

int main() {
    int N;
    std::cin >> N;

    std::vector<int> vec;

    for(int i = 0; i < N; i++) {
        std::cin >> U[i];
        vec.push_back(U[i]);
    }

    std::sort(vec.begin(), vec.end());
    
    
}