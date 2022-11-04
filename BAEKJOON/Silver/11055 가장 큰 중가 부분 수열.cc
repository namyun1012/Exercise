#include <iostream>
#include <algorithm>

int arr[1002];
int dp[1002]; // i 번째 일 때 i번째 포함 중 가장 큰 것
/*
    2트클
    음수 고려

*/
int main() {
    int n;
    std::cin >> n;
    int result = -1e9;
    for(int i = 1; i <= n ; i++) {
        std::cin >> arr[i];
    }


    for(int i = 1; i <= n ; i++) {
        dp[i] = arr[i];

        for(int j = 1; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = std::max(dp[i], dp[j] + arr[i]);
            }
        }

        result = std::max(result, dp[i]);
    }

    std::cout << result;
    return 0;
}