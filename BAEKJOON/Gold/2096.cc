#include <iostream>
#include <algorithm>

short board[100002][3];
int dp[100002][3];


int main() {
    int N;
    std::cin >> N;
    for(int i = 1; i <= N ; i++) {
        std::cin >> board[i][0] >> board[i][1] >> board[i][2];
    }

    dp[1][0] = board[1][0];
    dp[1][1] = board[1][1];
    dp[1][2] = board[1][2];

    for(int i = 2; i <= N ; i++) {
        dp[i][0] =std::max(dp[i-1][0], dp[i-1][1]) + board[i][0];
        dp[i][1] =std::max(dp[i-1][0], std::max(dp[i-1][1], dp[i-1][2])) + board[i][1];
        dp[i][2] =std::max(dp[i-1][1], dp[i-1][2]) + board[i][2];
    }

    std::cout << std::max(dp[N][0], std::max(dp[N][1], dp[N][2]));

    std::fill(&dp[1][0], &dp[N][2] , 0);

    dp[1][0] = board[1][0];
    dp[1][1] = board[1][1];
    dp[1][2] = board[1][2];

    for(int i = 2; i <= N ; i++) {
        dp[i][0] =std::min(dp[i-1][0], dp[i-1][1]) + board[i][0];
        dp[i][1] =std::min(dp[i-1][0], std::min(dp[i-1][1], dp[i-1][2])) + board[i][1];
        dp[i][2] =std::min(dp[i-1][1], dp[i-1][2]) + board[i][2];
    }


    std::cout <<" " <<  std::min(dp[N][0], std::min(dp[N][1], dp[N][2]));
    return 0;
}