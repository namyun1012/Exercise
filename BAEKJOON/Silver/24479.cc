#include <iostream>
#include <vector>
#include <set>
std::set<int> adj[100001];
int visited[100001];
int result[100001];
int cnt = 0;

void dfs(int cur) {


    visited[cur] = 1;
    cnt++;
    result[cur] = cnt;

    for(int ele : adj[cur]) {
        if(visited[ele]) continue;
        dfs(ele);
    }
}
    
    


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int N, M, V;
    std::cin >> N >> M >> V;
    int fromV, toV;
    while(M--) {
        std::cin >> fromV >> toV;
        adj[fromV].insert(toV);
        adj[toV].insert(fromV);
    }
    
    
    dfs(V);
    

    for(int i = 1; i <= N; i++)
        std::cout << result[i] << "\n"; // 정점별로 방문하지 않으면 0이 나옴

    return 0;    
}