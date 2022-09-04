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
        return ; // M까지 찾으면 함수는 중단 되어야 함
    }

    for(int i = 1; i <= N; i++) {
        if(check[i]) continue;

        // check[i] = true 를 제거해서 중복 체크 가능하게
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