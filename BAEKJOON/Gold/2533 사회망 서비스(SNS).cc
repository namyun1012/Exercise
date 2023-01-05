#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/*
    시간 엄청 먹긴 하는 듯
    Tree DP에 대해서 더 학습해 보기
    자신의 모든 친구가 얼리아답터 일 때만 받아들임
*/
using namespace std;

vector<int> adj[1000002];
int visited[1000002];
int dp[1000002][2]; // 0 일반, 1이 어댑터


void dfs(int cur) {
    visited[cur] = 1;
    // cur가 어댑터일 시 일단은 자기 하나
    dp[cur][1] = 1;
    
    for(int nxt : adj[cur]) {
        if(visited[nxt]) continue;
        dfs(nxt);

        // 자기가 어댑터 X일시 다음 것이 어댑터인 것을 더함
        dp[cur][0] += dp[nxt][1];   

        // 자기가 어댑터일 경우 다음 것 중에서 작은 것을 더함
        dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
    }
 
}



int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int fromV, toV;
        cin >> fromV >> toV;
        adj[fromV].push_back(toV);
        adj[toV].push_back(fromV);
    }


    
    dfs(1);
    cout << min(dp[1][1], dp[1][0]);

   return 0;
}

