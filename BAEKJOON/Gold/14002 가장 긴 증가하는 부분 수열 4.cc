#include <iostream>
#include <algorithm>
#include <vector>
#include <stack> 
/*
    결과가 맨 끝이 아닐 경우를 놓침

*/
int arr[1002];
int dp[1002]; // 자기 포함하는 가장 긴 수열의 크기
int prev[1002];

int main() {
    int n;
    int result_index = 1;
    
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> arr[i];
    }

    dp[1] = 1;
    prev[1] = 0;

    for(int i = 2; i <= n; i++) {
        prev[i] = 0;
        dp[i] = 1;

        for(int j = i -1 ; j >= 1; j--) {
            if(arr[i] > arr[j]) {
                if(dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            } 
        }

        if(dp[result_index] < dp[i])
            result_index = i;
    }
    
    std::cout << dp[result_index] << "\n";
    
    std::stack<int> result;
    int temp = result_index;
    while(temp != 0) {
        result.push(temp);
        temp = prev[temp];
    }
    
    while(!result.empty()) {
        std::cout << arr[result.top()] << " ";
        result.pop();
    }
    
    return 0;
}