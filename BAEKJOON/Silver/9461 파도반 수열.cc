#include <iostream>

long long dp[102] = {0,1,1,1,2,2,3,4,5,7,9};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int N;
        std::cin >> N;

        for(int i = 1; i <= N; i++) {
            if(dp[i] != 0) continue;
            dp[i] = dp[i-2] + dp[i-3];
        }

        std::cout << dp[N] << "\n";
    }

    return 0;
}