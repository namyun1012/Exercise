#include <iostream>
#include <algorithm>

int arr[1002];
int dp[1002][2]; // 0 >> 자기 보다 작은 수들, 1 자기보다 큰 수들
int main() {
    int N;
    std::cin >> N;
    int result = 1;
    for(int i = 1; i <= N; i++) {
        std::cin >> arr[i];
    }

    dp[1][0] = 1;
    dp[N][1] = 1; // 위에 반대

    for(int i = 2; i <= N; i++) {
        dp[i][0] = 1; // 자기 포함    
        for(int j = 1; j < i; j++) { // i 보다 작은 수, 가장 긴 증가 수열은 구함
            if(arr[i] > arr[j]) {
                dp[i][0] = std::max(dp[i][0], dp[j][0] + 1);
            }
        }
    }
    //위와 반대로
    for(int i = N-1; i >= 1; i--) {
        dp[i][1] = 1;
        for(int j = N; j > i; j--) {
            if(arr[i] > arr[j]) {
                dp[i][1] = std::max(dp[i][1], dp[j][1] + 1);
            }
        }
    }


    for(int i = 1; i <= N; i++) {
        result = std::max(dp[i][0] + dp[i][1] - 1, result); // 자신이 중복되므로 1뺌
    }

    std::cout << result;
    return 0;
}