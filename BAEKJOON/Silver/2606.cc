#include <iostream>
#include <vector>
#include <queue>
std::vector<int> adj[101];
int visited[101];

int main() {
    int N,M;
    std::queue<int> q;
    std::cin >> N >> M;
    int count = 0;
    int fromV, toV;
    
    while(M--) {
        std::cin >> fromV >> toV;
        adj[fromV].push_back(toV);
        adj[toV].push_back(fromV);
    }

    q.push(1);
    visited[1] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]) {
            if(visited[nxt]) continue;
            q.push(nxt);
            visited[nxt] = 1;
            count++;
        }

    }
    std::cout << count;
    return 0;
}