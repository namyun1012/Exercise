#include <iostream>

int dp[103][10];


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int N;
    std::cin >> N;

    int result = 0;
    dp[1][0] = 0; // 0으로 끝남
    for(int i = 1; i <= 9; i++)
        dp[1][i] = 1;  

    for(int i = 2; i <= N ;i++) {
        
        dp[i][0] = (dp[i-1][1] % 1000000000);
        
        for(int j = 1; j <= 8; j++) {
            dp[i][j] = ((dp[i-1][j-1] % 1000000000) + (dp[i-1][j+1] % 1000000000) % 1000000000);
        }
        dp[i][9] = (dp[i-1][8] % 1000000000);
    }

    for(int i = 0; i <= 9 ;i++) {
        result += (dp[N][i] % 1000000000);
        result = result % 1000000000;
    }
    std::cout << result % 1000000000;
}