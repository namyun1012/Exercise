//visited 감당이 안됨, adj 말고 다른 형식으로 해결해 보자

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<std::pair<int, int>> adj[102];
int visited[102];

int main() {
    int result = 102;
    int n, m;
    std::cin >> n >> m;
    
    int fromV, toV;
    for(int i = 0; i < n; i++) {
        std::cin >> fromV >> toV;
        adj[fromV].push_back({toV, 0}); // 주사위 안 굴림
    }   

    for(int j = 0; j < m; j++) {
        std::cin >> fromV >> toV;
        adj[fromV].push_back({toV, 0}); // 주사위 안 굴림
    }

    // i번째 + 6을 주사위로
    for(int i = 1; i < 100; i++) {
        if(!adj[i].empty()) continue; // 뱀, 사다리 일 경우 무조건 가야하므로 주사위 못굴림
        
        for(int j = i+1; j <= i+6 && j <= 100; j++) {
            adj[i].push_back({j,1}); // 주사위 굴림
        }
    }

    std::queue<std::pair<int, int>> q;
    q.push({1, 1});
    visited[1] = 1;

    while(!q.empty()) {
        auto cur = q.front(); 
        q.pop();

        if(cur.first == 100) {
            result = std::min(result, cur.second); 
        }

        for(auto nxt : adj[cur.first]) {
            if(nxt.second == 0) {
                q.push({nxt.first, nxt.second + cur.second});
                continue;
            }

            if(visited[nxt.first] && nxt.first != 100) continue;
            visited[nxt.first] = 1;
            q.push({nxt.first, nxt.second + cur.second});

        }
    }

    std::cout << result - 1; // 1 보정용으로 
    
    return 0;
}