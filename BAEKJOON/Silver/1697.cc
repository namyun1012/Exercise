#include <iostream>
//use dp
int dp[100060];

int main() {
    int N, K;
    std::cin >> N >> K;

    dp[N] = 0;
    dp[N+1] = 1;

    for(int i = 0; i <= N; i++)
        dp[i] = N-i;
    
    for(int i = N+2; i <= 100000; i++) {
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0) dp[i] = std::min(dp[i/2] + 1, dp[i]);
        
        dp[i-1] = std::min(dp[i]+1, dp[i-1]); // 이전 것또 비교 과정을 거침
        if((i-1) % 2 == 0) dp[i-1] = std::min(dp[(i-1)/2]+1, dp[i-1]);
    }

    

    std::cout << dp[K];
    return 0;
}