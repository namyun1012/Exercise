/*
    비트마스킹 학습용
    비트마스킹을 사용해 기록함
    모든 도시를 방문했다는 것은 bit 상태가 (1 << N) - 1의 상태임
    
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int board[16][16];
int n;
int dp[16][1 << 16];

// 현재 방문 지점, 비트
int dfs(int cur_node, int cur_bit) {
    if(dp[cur_node][cur_bit] != -1)
        return dp[cur_node][cur_bit];
    
    // 모든 노드를 방문하였을 때
    if(cur_bit == (1 << n) - 1) {
        
        // 0 으로 가는 길이 있을 때
        if(board[cur_node][0] != 0)
            // 현재노드에서 0으로 가는 것을 반환함
            return board[cur_node][0];
        else
            return INF;
    }
    
    // 최소값을 찾기 위해 우선 INF 로 지정
    dp[cur_node][cur_bit] = INF;

    for(int i = 0; i < n; i++) {
        // 이 노드를 이미 방문했거나 갈 수가 없을 경우 continue
        if(cur_bit & (1 << i) || board[cur_node][i] == 0) continue;

        // 자기자신과 i번째 노드를 방문했을 때 중 더 작은 것
        dp[cur_node][cur_bit] = min(dp[cur_node][cur_bit], dfs(i, cur_bit|(1<<i)) + board[cur_node][i]);

    } 

    return dp[cur_node][cur_bit];
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    // fill은 마지막 것을 안 채움
    fill(&dp[0][0], &dp[15][(1<<16)-1] + 1, -1);

    cout << dfs(0 ,1);

    return 0;
}