#include <iostream>
#include <vector>
#include <queue>

std::vector<int> adj[100];
int indegrees[102];
std::vector<int> result;

int main() {
    int n,m;
    std::cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int fromV, toV;
        std::cin >> fromV >> toV;
        adj[fromV].push_back(toV);
        indegrees[toV]++;
    }
    
    std::queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(indegrees[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        result.push_back(cur);

        for(auto nxt : adj[cur]) {
           
            
            indegrees[nxt] -= 1;
            if(indegrees[nxt] == 0) {
                q.push(nxt);
            }

        }
    }

}