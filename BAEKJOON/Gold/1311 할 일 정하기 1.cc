/*
    비트마스킹을 이용한 DP 외판원 순환 문제 변경
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e8
using namespace std;

int n;
int board[21][21];
int dp[21][1 << 21];

// 최대 20만 정도니 돌파할 일은 없어보임

// cur 가 할일을 선정함, status 는 상태
int bfs(int cur, int status) {
    if(dp[cur][status] != -1) return dp[cur][status];

    // 모든 노드를 방문했을 시 추가할 것 없으므로 return 0;
    if(status == (1<<n) - 1) return 0;

    // n번째는 사용되지 않음
    if(cur == n) return 0;

    // 우선 무한으로 설정해 놓음
    dp[cur][status] = INF;
    for(int i = 0; i < n; i++) {

        // 이미 누군가 맡았을 경우 넘어감
        if(status & (1 << i)) continue;

        // 더 작은 것으로 그리고 다음 사람의 것을 진행함
        dp[cur][status] = min(dp[cur][status], bfs(cur + 1, status |(1<<i)) + board[cur][i]);
    }

    return dp[cur][status];
}


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    cin >> n;

    // 기본 초기화 -1으로
    fill(&dp[0][0], &dp[20][(1<<20)]+1, -1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    // 기본값은 (0,0)으로
    int result = bfs(0, 0);
    cout << result;
}