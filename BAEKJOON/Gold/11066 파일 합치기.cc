#include <iostream>
#include <algorithm>
#define MAX 1e9
int arr[502];
int dp[502][502]; // dp[i][j] i ~ j 까지 합침에서 사용된 용량
int sum[502];
/*
    dp 형식 까지는 잘 생각했는데
    그 이후가 혼돈

*/
int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int k;
        std::cin >> k;
        std::fill(&dp[0][0], &dp[501][501], 0);

        for(int i = 1; i <= k; i++) {
            std::cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }
        


        for(int i = 1; i <= k; i++) {
            for(int j = 1; j <= k-i; j++) {
                dp[j][i+j] = MAX;
                for(int l = j; l < i+j; l++) {
                    int temp = dp[j][l] + dp[l+1][i+j] + sum[i+j] - sum[j-1];
                    
                    dp[j][i+j] = std::min(dp[j][i+j], temp);
                    
                }
            
            }
        }
        /* 배열 확인 용 코드
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j <= k ; j++) {
                std::cout << dp[i][j] << " ";
            }
            std::cout << "\n";
        }
        */
        std::cout << dp[1][k] << "\n";
    }

    return 0;
}