#include <iostream>
#include <algorithm>
// HCPC 문제
int n, m;
int S[2002]; // 받게 되는 돈

int main() {
    std::cin >> n >> m;

    //출제자
    for(int i = 1; i <= n; i++) {
        std::cin >> S[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n + m; j++) {
            int temp;
            std::cin >> temp;
            S[i] -= temp;
            S[j] += temp;
        }
    }


    for(int i = 1; i <= n + m; i++) {
        std::cout << S[i] << " ";
    }

    return 0;

}