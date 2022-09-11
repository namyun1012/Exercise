#include <iostream>
#include <vector>


std::vector<std::pair<int, int>> vec(42);


int main() {
    int N;
    std::cin >> N;
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int x;

    vec[0] = {1,0};
    vec[1] = {0,1};

    for(int i = 1; i <= 40; i++) {
        vec[i] = {vec[i-1].second, (vec[i-1].first + vec[i-1].second)};
    }

    while (N--)
    {
        
        std::cin >> x;
        std::cout << vec[x].first << " " << vec[x].second << "\n";

    }
    
    return 0;
}