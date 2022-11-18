#include <string>
#include <vector>
#include <algorithm>

int dp[503][503];

using namespace std;

int solution(vector<vector<int>> triangle) {
    int result = 0;
    int n = triangle.size();
    dp[0][0] = triangle[0][0];
    
    for(int i = 1 ; i < n ; i++) {
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for(int j = 1; j <= i-1; j++) {
            dp[i][j] = std::max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
    }

    for(int i = 0; i < n; i++) {
        result = std::max(dp[n-1][i], result);
    }
    return result;
}