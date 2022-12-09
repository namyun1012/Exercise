#include <iostream>
/*
    Fibonacci 의 변형
*/
long long dp[1002];


int main() {
    int n;
    std::cin >> n;

    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3; i <= n; i++) {
        dp[i] = (((dp[i-2] * 2) % 10007) + (dp[i-1] % 10007)) % 10007;
        
    }

    std::cout << dp[n];
    return 0;
}