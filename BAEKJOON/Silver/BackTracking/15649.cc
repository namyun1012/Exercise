#include <iostream>
#include <vector>
#include <algorithm>

bool check[9];

std::vector<int> per;

void search(int N, int M) {
    if(per.size() == M) {
        for(int ele : per)
            std::cout << ele <<" ";
        std::cout << "\n";
    }

    for(int i = 1; i <= N; i++) {
        if(check[i]) continue;

        check[i] = true; 
        per.push_back(i);   // 현재 값을 넣어줌
        search(N, M);
        check[i] = false;  // 현재 값을 빼줌
        per.pop_back();
    }
}


int main() {
    int N, M;
    std::cin >> N >> M;
    search(N, M);

    return 0;

}