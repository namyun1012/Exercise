#include <iostream>

int arr[1002];
int dp[1002];

int main() {
    int N;
    std::cin >> N;
    int result = 1;
    int max_ele;
    
    for(int i = 1; i <= N; i++) {
        std::cin >> arr[i];
    }
    
    
    dp[1] = 1;

    for(int i = 2; i <= N; i++) {
        dp[i] = 1;
        for(int j = i-1; j >= 1; j--) {
            
            if(arr[i] > arr[j]) {
                dp[i] = std::max(dp[j] + 1, dp[i]);
            }

        }
        
        result = std::max(dp[i], result);
    }

    std::cout << result;
    return 0;
}