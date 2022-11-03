#include <iostream>
#include <algorithm>

int coins[102];
int dp[10002]; // i 금액에서의 개수
/*
    그 동안 풀었던 dp와 형식이 좀 다름
    중복 되는 것을 방지 하기 위해서
    1번 동전만 사용 그 후 2번 + 1번,  3번 + 2번 + 1번 이렇게 되도록 함
*/

int main() {
    int n,k;
    std::cin >> n >> k;

    for(int i = 0; i < n; i++) {
        std::cin >> coins[i];
    }

    dp[0] = 1; // 보정용 
    
    for(int i = 0; i < n ; i++) {
        int coin = coins[i];
        for(int j = coin ; j <= k ; j++) {
            dp[j] += dp[j - coin]; // 
        }
    }

    std::cout << dp[k];

    return 0;
}