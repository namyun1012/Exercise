#include <iostream>

long long result[1002];

int main() {
    int n;
    std::cin >> n;
    long long val;
    result[1] = 1;
    result[2] = 2;
    

    for(int i = 3; i <= n; i++) {
        result[i] = (result[i-1] + result[i-2]) % 10007; // 저장 할 때부터 10007으로 나눈 값을 넣음
    
    }

    std::cout << result[n];
    return 0;
}

