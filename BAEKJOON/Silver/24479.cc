#include <iostream>
#include <vector>
#include <set>
std::set<int> adj[100000];
int visited[100001];

bool dfs(int cur) {
    
    if(!adj[cur].empty())
        std::cout << cur << "\n";
    else {
        std::cout << 0 << "\n";
    }
    visited[cur] = 1;
    bool check = false;
    
    for(int ele : adj[cur]) {
        if(visited[ele]) continue;
        check = true;
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
    if(!adj[V].empty())
        dfs(V);
    else 
        std::cout << 0;
    return 0;    
}