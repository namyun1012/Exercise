#include <iostream>
//prefix sum
int arr[100002];
int dp[100002];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    
    int N,M;
    int max_result = 0;
    std::cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        std::cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];

    for(int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + arr[i];
    }
    int x,y;
    
    while(M--) {
        std::cin >> x >> y;
        std::cout << dp[y] - dp[x-1] << "\n";
    }
    
    return 0;
}