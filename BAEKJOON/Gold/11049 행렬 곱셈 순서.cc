#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
/*
    대각선으로 계산을 수행해야 함
    파일 합치기와 유사 
    행렬 순서는 비교 안됨

*/
std::pair<int, int> matrix[502];
int dp[502][502];

int main() {
    int t;
    std::cin >> t;
    
    int r, c;
    for(int i = 1; i <= t; i++) {
        std::cin >> r >> c;
        matrix[i] = {r, c};
    }
    /*
        i = 차이
        j = 시작점
        (1,2) , (2,3), 
    */

    for(int i = 1; i <= (t-1); i++) {
        for(int j = 1; (i + j) <= t ; j++) {
            dp[j][i+j] = INF;
            for(int k = j; k <= (i+j); k++) {
                /*
                    k 구간을 나눠줌
                    dp[j][k] = X 좌표 같은 합칠 것
                    dp[k+1][i+j] = Y 좌표 같은 합칠 것
                
                */
                dp[j][i+j] = std::min(dp[j][i+j],  dp[j][k] + dp[k + 1][i + j] + matrix[j].first * matrix[k].second * matrix[i+j].second);
            }

        }

    }

    std::cout << dp[1][t];

    return 0;

}