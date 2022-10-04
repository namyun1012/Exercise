#include <iostream>

int dp[10002][3]; //dp[i][2] i가 안들감 dp[i][1] i가 2번째로 들어감 , [i][0] 가 1번째로 들어감
int arr[10002];

int main() {
    int N;
    std::cin >> N;

    for(int i = 1 ; i <= N; i++)
        std::cin >> arr[i];

    dp[1][0] = arr[1];
    dp[1][1] = arr[1];
    dp[1][2] = 0;

    dp[2][0] = arr[2];
    dp[2][1] = arr[1] + arr[2];
    dp[2][2] = arr[1];

    for(int i = 3; i <= N; i++) {
        dp[i][0] = std::max(dp[i-2][0], std::max(dp[i-2][1], dp[i-2][2])) + arr[i]; // i-1의 수가 안 붙음
        dp[i][1] = dp[i-1][0] + arr[i]; // i-1 번째가 들어감
        dp[i][2] = std::max(dp[i-1][0], std::max(dp[i-1][1], dp[i-1][2])); // i번째 수가 들어가지 않음
    }
    
    std::cout << std::max(dp[N][0], std::max(dp[N][1], dp[N][2]));
    return 0;
}