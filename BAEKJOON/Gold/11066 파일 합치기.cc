#include <iostream>
#include <algorithm>
#define MAX 1e9
int arr[502];
int dp[502][502]; // dp[i][j] i ~ j 까지 합침에서 사용된 용량
int sum[502];
/*
    dp 형식 까지는 잘 생각했는데
    그 이후가 혼돈 
    i, j 순차적으로 하면 안됨

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
        /*
            i : 구해야 하는 범위의 크기
            j : 합치는 범위의 시작 부분
            l : 구해야 하는 범위를 나눈 기준점
            
            i + j - 1 : 합치는 범위의 끝
            k = 5 라고 했을 때
         0   1   2   3   4
             0   1   2   3
                 0   1   2
                     0   1
                        0
            이런 식으로 계산이 필요함
        */


        for(int i = 1; i <= k; i++) {
            for(int j = 1; j <= k-i; j++) {
                dp[j][i+j] = MAX; // x,y 값
                for(int l = j; l < i+j; l++) {
                    int temp = dp[j][l] + dp[l+1][i+j] + sum[i+j] - sum[j-1];
                    
                    dp[j][i+j] = std::min(dp[j][i+j], temp);
                    
                }
            
            }
        }
        // 배열 확인 용 코드
        /*
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