#include <iostream>
#include <algorithm>
#include <vector>

int coord[1000005];
std::vector<int> uniq;

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    int N;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        std::cin >> coord[i];
        uniq.push_back(coord[i]);
    }

    std::sort(uniq.begin(), uniq.end());
    uniq.erase(std::unique(uniq.begin(), uniq.end()), uniq.end()); // 중복된 원소들을 제거함

    for(int i = 0; i < N; i++) {
        std::cout << std::lower_bound(uniq.begin(), uniq.end(), coord[i]) - uniq.begin() << " ";

    }
    // uniq.begin >> 최소 iterator
    //lower_bound >> 최초로 나올 때 it
    return 0;

    
}