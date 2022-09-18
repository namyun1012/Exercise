#include <iostream>
#include <vector>
#include <queue>

std::vector<int> adj[1002];
int visited[1002];

int main() {
    int N,M;
    int fromV, toV;
    int startV;
    int count = 0;
    std::cin >> N >> M;
    while(M--) {
        std::cin >> fromV >> toV;
        adj[fromV].push_back(toV);
        adj[toV].push_back(fromV);
    }

    std::queue<int> q;

    int N_count = N;

    while(N_count > 0) {
        for(int i = 1; i <= N; i++) {
            if(!visited[i]) {
                startV = i;
                break;
            }
        }

        q.push(startV);
        visited[startV] = 1;
        N_count--;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for(int nxt : adj[cur]) {
                if(visited[nxt]) continue;
                visited[nxt] = 1;
                q.push(nxt);
                N_count--;
            }
        }
        
        count++;
    }

    std::cout << count;
    return 0;
}