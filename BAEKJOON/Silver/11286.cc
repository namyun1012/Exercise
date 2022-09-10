#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

class comp {
public:
    bool operator()(const int a, const int b) {
        if(std::abs(a) == std::abs(b))
            return a > b;
        return std::abs(a) > std::abs(b);
    }
};

int main( ) {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    std::priority_queue<int,std::vector<int>, std::greater<int>> que;
    int N;
    std::cin >> N;
    
    while(N--) {
        int x;
        std::cin >> x;
        if(x == 0) {
            if(que.empty()) {
                std::cout << 0 << "\n";
                continue;
            }
            std::cout << que.top() << "\n";
            que.pop();
        }

        else {
            que.push(x);
        }


    }

    return 0;
}