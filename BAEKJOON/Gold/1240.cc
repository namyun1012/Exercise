#include <iostream>
#include <vector>
#include <stack>
#include <queue>

std::vector<std::pair<int, int>> adj[1002];
int visited[1002];

int main() {
    int N, M;
    std::cin >> N >> M;

    int fromV, toV, weight;
    for(int i = 0 ; i < N-1; i++) {
        std::cin >> fromV >> toV >> weight;
        adj[fromV].push_back({toV, weight});
        adj[toV].push_back({fromV, weight});
    }

    while(M--) {
        std::fill(visited, visited+1001, 0);
        
        int a,b;
        std::cin >> a >> b;
        
        std::queue<std::pair<int, int>> q;
        
        visited[a] = 1;
        q.push({a, 0});
        int cost = 0;

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            if(cur.first == b) {
                std::cout << cur.second << "\n"; // Enter 안눌러서 고생함
                break;
            }

            
            for(std::pair<int,int> nxt : adj[cur.first]) {
                if(visited[nxt.first]) continue;
                visited[nxt.first] = 1;
                q.push({nxt.first, cur.second + nxt.second});
                
            }
        }

    

    }

    return 0;
}