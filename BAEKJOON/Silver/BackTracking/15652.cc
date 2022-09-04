#include <iostream>
#include <vector>
#include <algorithm>

// 중복 조합을 구하는 문제
bool check[9];

std::vector<int> per;

void search(int N, int M, int num) {
    if(per.size() == M) {
        for(int ele : per)
            std::cout << ele <<" ";
        std::cout << "\n";
        return;
    }

    for(int i = num; i <= N; i++) {
        if(check[i]) continue;

        
        per.push_back(i);   // 현재 값을 넣어줌
        search(N, M, i); // i+ 1 >> i 로 변경, 중복 가능하게 
        per.pop_back();
    }
}


int main() {
    int N, M;
    std::cin >> N >> M;
    search(N, M, 1);

    return 0;

}