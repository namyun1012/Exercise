#include <iostream>
#include <algorithm>
int arr[100002];
int dp[100002]; // i 일 때 최고의 합
int main() {
    int N;
    int result = -1e9;
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
        
    }

    for(int i = 0; i < N; i++) {
        dp[i] = arr[i];
        dp[i] = std::max(dp[i], dp[i-1] + arr[i]);

        result = std::max(result, dp[i]);
    }

    std::cout << result;
    return 0;

}