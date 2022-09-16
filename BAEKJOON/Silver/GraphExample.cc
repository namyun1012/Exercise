#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

std::set<int> graph[1004];
int visited[1004];


void dfs(int cur) {
    visited[cur] = 1;
    std::cout << cur << " ";
    for(auto ver : graph[cur]) {
        if(visited[ver]) continue;
        dfs(ver);
    }
}

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    int N, M, V;
    std::cin >> N >> M >> V;
    int fromV, toV;
    std::vector<int> result_vec;

    for(int i = 0;i < M; i++) {
        std::cin >> fromV >> toV;
        graph[fromV].insert(toV);
        graph[toV].insert(fromV);
    }
    
    //DFS use Stacl
    dfs(V);
    std::cout << "\n";   
    
    result_vec.clear(); 
    
    for(int i = 0; i <= N; i++) {
        visited[i] = 0;
    }

    //BFS use Queue
    std::queue<int> que;
    que.push(V);
    visited[V] = 1;
    result_vec.push_back(V);
    
    while(!que.empty()) {
        int cur  = que.front();
        que.pop();
        
        for(int ver : graph[cur]) {
            if(visited[ver]) continue;
            que.push(ver);
            visited[ver] = 1;
            result_vec.push_back(ver);
            
        }
    }

    for(auto ele : result_vec)
        std::cout << ele << " ";

    return 0;
}