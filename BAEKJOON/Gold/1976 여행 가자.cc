#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
/*
    우선은 BFS 부터 클리어
*/

std::vector<int> adj[202];
int visited[202];
std::queue<int> que;

int main() {
    int n, m;
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int temp;
            std::cin >> temp;
            if(temp == 1)
                adj[i].push_back(j);
        }
    }

    for(int i = 0; i < m; i++) {
        int temp;
        std::cin >> temp;
        que.push(temp);
    }

    bool check = true;
    // 시작, 끝 지점 끼리 BFS 계속
    for(int i = 0; i < m - 1; i++) {
        
        int st = que.front(); que.pop();
        int en = que.front();

        std::fill(visited, visited + n + 1, 0);
        std::queue<int> q;
        
        q.push(st);
        visited[st] = 1;

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            if(cur == en) {
      
                break;
            }
            for(int nxt : adj[cur]) {
                if(visited[nxt]) continue;
                q.push(nxt);
                visited[nxt] = 1;
            }
        }

        
        if(visited[en] == 0) {
            check = false;
            break;
        }

    }

    if(!check) std::cout << "NO";
    else std::cout << "YES";

    return 0;
}