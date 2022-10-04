#include <iostream>

int arr[100002];
int dp[100002];
int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int N,K;
    std::cin >> N >> K;

    int result;
    
    for(int i = 0; i < N; i++)
        std::cin >> arr[i];
    int sum = 0;

    for(int i = 0; i < K; i++)
        sum += arr[i];
    
    result = sum;
    for(int i = 0; i < N - K; i++) {
        sum = sum + arr[i+K] - arr[i];
        result = std::max(sum, result);
    }

    std::cout << result;
}