#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> arr[102];
int dp[102][100002]; // dp[i][j] 


int main() {
    int N, K;
    std::cin >> N >> K;
    
    int W, V;
    
    for(int i = 1; i <= N; i++) {
        std::cin >> W >> V;
        arr[i] = {W, V};
    }

    
    int cur_weight;
    int cur_value;

    for(int i = 1; i <= N; i++) { // 중복 방지 위해 [i][j], 이럴 시 물건 1개당 1개만 사용가능함
        cur_weight = arr[i].first;
        cur_value = arr[i].second;
        
        for(int j = 1; j <= K; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= cur_weight)
                dp[i][j] = std::max(dp[i][j], dp[i-1][j-cur_weight] + cur_value);
                // 예전 꺼 까지 사용한 것 끼리 비교
                //dp[i][j-cur_weight] 시 그 떄 i 것이 계속 들어감
            // i는 i개 
            else {
                
            }
        }
    }

    std::cout << dp[N][K];
    return 0;   

}

// 중복을 방지 하기 위해서 i개의 물건 까지 씀 [i][j]의 이차원 배열로
/*1 9 2 3
0 0 0 0 0 0 0 0 0
0 3 3 3 3 3 3 3 3
0 3 
*/ 