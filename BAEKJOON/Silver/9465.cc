#include <iostream>
#include <vector>
#include <algorithm>

int stickers[100002][2];
int dp[100002][2]; // j, i 번째를 포함한 최고


int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int N;
        int result = 0;
        std::cin >> N;

        for(int i = 0; i <= 1; i++) {
            for(int j = 1; j <= N; j++) {
                std::cin >> stickers[j][i];
            }
        }
        dp[0][0] = 0;
        dp[0][1] = 0;

        dp[1][0] = stickers[1][0];
        dp[1][1] = stickers[1][1];

        for(int i = 2; i <= N; i++) {
            dp[i][0] = std::max(dp[i-2][0], dp[i-2][1]) + stickers[i][0];
            dp[i][0] = std::max(dp[i-1][1] + stickers[i][0], dp[i][0]);
            dp[i][1] = std::max(dp[i-2][0], dp[i-2][1]) + stickers[i][1];
            dp[i][1] = std::max(dp[i-1][0]+ stickers[i][1], dp[i][1]);
        }

        int n1 = std::max(dp[N][0], dp[N][1]);
        int n2 = std::max(dp[N-1][0], dp[N-1][1]);
        std::cout << std::max(n1, n2) << "\n";
    }

    return 0;
}