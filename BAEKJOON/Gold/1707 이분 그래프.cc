/*
    인접한 정점 끼리 서로 다른 색으로 칠해 모든 정점을 두 그룹으로 나누고
    서로 다른 색의 정점을 간선으로 연결함

    따라서 모든 인접한 정점이 서로 다른 색으로 칠해지면 이분 그래프임

*/



#include <iostream>
#include <vector>
#include <queue>

std::vector<int> adj[20002];
int visited[20002]; // 0 , 1, 2

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    int k;
    std::cin >> k;

    while(k--) {
        int v, e;
        std::cin >> v >> e;

        for(int i = 1; i <= v; i++) {
            adj[i].clear();
            visited[i] = 0;
        }

        for(int i = 0; i < e; i++) {
            int fromV, toV;
            std::cin >> fromV >> toV;
            adj[fromV].push_back(toV);
            adj[toV].push_back(fromV);
        }

        //BFS 실행 다른 색으로 칠하기
        for(int i = 1; i <= v; i++) { // 모든 그래프가 연결이 안되어 있을 경우를 고려함
            if(visited[i]) continue;
            
            std::queue<int> q;
            q.push(i);
            visited[i] = 1;

            while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for(int nxt : adj[cur]) {
                if(visited[nxt]) continue;
                q.push(nxt);
                if(visited[cur] == 1)
                    visited[nxt] = 2;
                else
                    visited[nxt] = 1;

            }
            }
        }
        bool check = true;
        for(int i = 1; i <= v; i++) {
            for(int nxt : adj[i]) {
                if(visited[nxt] == visited[i]) {
                    check = false;
                    break;
                }
            }

            if(!check) break;
        }

        if(check) std::cout << "YES\n";
        else std::cout << "NO\n"; 

    }

    return 0;
}