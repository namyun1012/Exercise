#include <iostream>
#include <vector>
#include <queue>

std::vector<int> adj[100002];
int parent[100002];
int visited[100002];
//root = 1
//using bfs
int main() {
    int N;
    std::cin >> N;
    int startV, toV;
    std::queue<int> que;

    for(int i = 0; i < N-1; i++) {
        std::cin >> startV >> toV;
        adj[startV].push_back(toV);
        adj[toV].push_back(startV);
    }

    parent[1] = 1;
    que.push(1);
    
    while(!que.empty()) {
        int cur = que.front();
        que.pop();

        for(int ele : adj[cur]) {
            if(visited[ele]) continue;
            que.push(ele);
            visited[ele] = 1;
            parent[ele] = cur;
        }
    }

    for(int i = 2; i <= N; i++) {
        std::cout << parent[i] << "\n";
    }

    return 0;
}

