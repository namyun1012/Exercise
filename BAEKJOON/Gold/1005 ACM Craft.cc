#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<int> adj[1002];
std::vector<int> parent[1002];
int indegree[1002];
int visited[1002];
int times[1002];
int dp[1002];
/*
    위상 정렬에서 DP를 초기화 할 때 
    parent의 것들을 찾아가면서 최대치 인 것을 받음
*/
int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while(t--) {
        std::fill(times, times + 1002, 0);
        std::fill(dp, dp + 1002, 0);
        std::fill(indegree, indegree + 1002, 0);
        std::fill(visited, visited + 1002, 0);
        for(int i = 1; i <= 1001; i++)
            adj[i].clear();

        for(int i = 1; i <= 1001; i++)
            parent[i].clear();

        int n, k;
        std::cin >> n >> k;

        for(int i = 1; i <= n; i++) {
            std::cin >> times[i];
        }

        for(int i = 1; i <= k; i++) {
            int fromV, toV;
            std::cin >> fromV >> toV;
            adj[fromV].push_back(toV);
            parent[toV].push_back(fromV);
            indegree[toV]++;
        }

        int w;
        std::cin >> w;

        std::queue<int> q;

        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                visited[i] = 1;
                dp[i] = times[i];
            }
        }


        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int nxt : adj[cur]) {
                if(visited[nxt]) continue;
                indegree[nxt]--;
                if(indegree[nxt] <= 0) {
                    visited[nxt] = 1;
                    for(int pt : parent[nxt]) {
                        dp[nxt] = std::max(dp[pt] + times[nxt], dp[nxt]);
                    }
                    q.push(nxt);
                }
            }
        }



        std::cout << dp[w] << "\n";
    }

    return 0;
}