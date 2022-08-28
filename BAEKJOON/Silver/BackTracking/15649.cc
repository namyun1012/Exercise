#include <iostream>
#include <vector>
#include <algorithm>

int cur = 1
void BackTracking(int N, int M) {
    if(M == 0) {
        std::cout << "\n";
        return ;
    }

    std::cout << cur << " ";

    BackTracking(N)
    
}

// 계산량 : N * (N-1));
int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> vec;
    
    for(int i = 1; i <= N; i++) {
        BackTracking(N, M);

    }
    

}

// set 정렬 다 해줌