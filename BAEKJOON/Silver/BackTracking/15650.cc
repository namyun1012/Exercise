#include <iostream>
#include <vector>
#include <algorithm>

// 조합을 구하는 문제
bool check[9];

std::vector<int> per;

bool check_func(std::vector<int> vec) {
    bool checked = true;
    for(int i = 0; i < vec.size()-1; i++) {
        if(vec[i] > vec[i+1]) {
            checked = false;
            break;
        }
    }

    return checked;
}

void search(int N, int M) {
    if(per.size() == M && check_func(per)) {
        for(int ele : per)
            std::cout << ele <<" ";
        std::cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++) {
        if(check[i]) continue;

        check[i] = true; 
        per.push_back(i);   // 현재 값을 넣어줌
        search(N, M);
        check[i] = false;
        per.pop_back();
    }
}


int main() {
    int N, M;
    std::cin >> N >> M;
    search(N, M);

    return 0;

}