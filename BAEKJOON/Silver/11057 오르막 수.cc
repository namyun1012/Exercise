#include <iostream>

long long dp[1002][10];

int main() {
    int n;
    std::cin >> n;
    // 왠만한 것은 다 나머지
    //  00001 도 되는 듯 , 
    for(int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9 ; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] += (dp[i-1][k] % 10007);
            }
        }
    }

    long long result = 0;
    for(int i = 0; i <= 9; i++) {
        result += (dp[n][i] % 10007);
    }

    std::cout << result % 10007;
    return 0;
}