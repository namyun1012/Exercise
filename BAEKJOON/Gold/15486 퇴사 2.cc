#include <iostream>
#include <algorithm>

int T[2000000];
int P[2000000];

int DP[2000000];
/*
    돈 기준은 N+1 일때

*/

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int n;
    std::cin >> n;

    for(int i = 1; i <= n; i++) {
        std::cin >> T[i] >> P[i];
    }

    for(int i = 1; i <= n+1; i++) {
        int t = T[i];
        int p = P[i];

        // 현재 최대치는 이전 꺼나 아님 지금 쌓여 있는 것
        DP[i] = std::max(DP[i-1], DP[i]);
        // 미래에 저장 혹시 이미 있을 경우 있으니 최대치 인 것으로 지정
        DP[i + t] = std::max(DP[i + t], DP[i] + p);
    }

    std::cout << DP[n+1];

    return 0;
}