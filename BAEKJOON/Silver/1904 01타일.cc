#include <iostream>

// 00 과 1로 구성됨
long long dp[1000002];

int main() {
    int n;
    std::cin >> n;
    
    dp[1] = 1; // 1
    dp[2] = 2; // 00 , 11
    // dp[3] = 3 // 001 111 110
    // dp[4] = 5 // 0011 1111 1001 1100 0000
    for(int i = 3; i <= n ; i++) {
        dp[i] = ( dp[i-1] + dp[i-2]) % 15746; // i-2 번째에서 00 을 더하기 i-1 번째에서 1을 더하기
    }

    std::cout << dp[n];
    return 0;
}