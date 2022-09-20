#include <iostream>

// 색이 연속되면 안됨

int cost[1002][3];
int dp[1002][3]; // 색깔 R ,G, B;
int main() {
    int N;
    std::cin >> N;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= 2; j++) {
            std::cin >> cost[i][j];
        }
    }

    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];

    // dp[i][0] 은 red로 칠함, 즉 이전꺼 그린, 블루 둘 중 작은 거를 가져옴
    for(int i = 2; i <= N; i++) {
        dp[i][0] = std::min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = std::min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = std::min(dp[i-1][1], dp[i-1][0]) + cost[i][2];
        
    }

    std::cout << std::min(dp[N][0], std::min(dp[N][1], dp[N][2]));
    return 0;
}