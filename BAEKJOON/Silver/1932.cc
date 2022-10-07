#include <iostream>
#include <algorithm>
int tri[502][502];
int dp[502][502]; // 각 칸마다의 최대치
int main() {
    int N;
    std::cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            std::cin >> tri[i][j];
        }
    }

    dp[1][1] = tri[1][1];
    for(int i = 2; i <= N; i++) { // 1, i번째는 다르게
        dp[i][1] = dp[i-1][1] + tri[i][1];
        for(int j = 2; j < i; j++) {
            dp[i][j] = std::max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
        }

        dp[i][i] = dp[i-1][i-1] + tri[i][i];
    }


    int result = dp[N][1];
    for(int i = 1; i <= N; i++) {
        result = std::max(result, dp[N][i]);
    }
    std::cout << result;
}