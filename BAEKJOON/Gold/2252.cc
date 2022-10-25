#include <iostream>
#include <vector>
#include <queue>
//위상 정렬 연습문제
std::vector<int> adj[32003];
int indegree[32003];
std::vector<int> result;

int main() {
    int n, m;
    std::cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int fromV, toV;
        std::cin >> fromV >> toV;
        adj[fromV].push_back(toV);
        indegree[toV]++; 
    }

    std::queue<int> q;
    for(int i = 1; i <= n ; i++) {
        if(indegree[i] == 0) // indegree 가 0이면 제일 먼저 처리
            q.push(i);
    }

    //indegree 가 낮은 순으로 처리
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur);       
        for(int nxt : adj[cur]) {
            indegree[nxt]--;
            if(indegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    for(int ele : result) {
        std::cout << ele << " ";
    }

    return 0;
}