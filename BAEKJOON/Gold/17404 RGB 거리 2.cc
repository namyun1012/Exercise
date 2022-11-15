#include <iostream>
#include <algorithm>
/*
    dp 배열을 각각 경우의 수에 따라 3개로 분류함
*/

int arr[1002][3];
long long dp_red[1002][3]; // 1번집을 빨강으로 칠함
long long dp_green[1002][3];
long long dp_blue[1002][3];
int main() {
    long long result = 1e9;
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++)
            std::cin >> arr[i][j];
    }

    // 1. dp_red 진행
    dp_red[1][0] = arr[1][0];
    dp_red[1][1] = 1e8; // 사용불가
    dp_red[1][2] = 1e8; // 사용불가

    for(int i = 2; i <= n; i++) {
        dp_red[i][0] = std::min(dp_red[i-1][1], dp_red[i-1][2]) + arr[i][0];
        dp_red[i][1] = std::min(dp_red[i-1][0], dp_red[i-1][2]) + arr[i][1];
        dp_red[i][2] = std::min(dp_red[i-1][0], dp_red[i-1][1]) + arr[i][2];
    }
    
    // 2. dp_green 진행
    dp_green[1][0] = 1e8;
    dp_green[1][1] = arr[1][1]; // 사용불가
    dp_green[1][2] = 1e8; // 사용불가

    for(int i = 2; i <= n; i++) {
        dp_green[i][0] = std::min(dp_green[i-1][1], dp_green[i-1][2]) + arr[i][0];
        dp_green[i][1] = std::min(dp_green[i-1][0], dp_green[i-1][2]) + arr[i][1];
        dp_green[i][2] = std::min(dp_green[i-1][0], dp_green[i-1][1]) + arr[i][2];
    }

    // 3. dp_blue 진행
    dp_blue[1][0] = 1e8;
    dp_blue[1][1] = 1e8; // 사용불가
    dp_blue[1][2] = arr[1][2]; // 사용불가

    for(int i = 2; i <= n; i++) {
        dp_blue[i][0] = std::min(dp_blue[i-1][1], dp_blue[i-1][2]) + arr[i][0];
        dp_blue[i][1] = std::min(dp_blue[i-1][0], dp_blue[i-1][2]) + arr[i][1];
        dp_blue[i][2] = std::min(dp_blue[i-1][0], dp_blue[i-1][1]) + arr[i][2];
    }
    
    result = std::min(result, dp_red[n][1]);
    result = std::min(result, dp_red[n][2]);
    result = std::min(result, dp_green[n][0]);
    result = std::min(result, dp_green[n][2]);
    result = std::min(result, dp_blue[n][0]);
    result = std::min(result, dp_blue[n][1]);
    // n - 1 일 때 0일 때와 같은 색이면 안됨 [0][0] 번째를 저장해 놓자
    std::cout << result;
    return 0;
}