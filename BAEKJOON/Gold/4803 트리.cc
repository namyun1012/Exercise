#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
int n, m;
std::vector<int> adj[502];
int visited[502];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int t = 0;
    while(true) {
        t++;
        std::cin >> n >> m;
        if(n == 0 && m == 0) break;

        // 경우의 수 마다 초기화
        for(int i = 0; i <= 500; i++)
            adj[i].clear();
        std::fill(visited, visited + 501, 0);
        
        for(int i = 0; i < m; i++) {
            int fromV, toV;
            std::cin >> fromV >> toV;
           

            adj[fromV].push_back(toV);
            adj[toV].push_back(fromV);
        }

        int trees = 0;

        for(int i = 1; i <= n ;i++) {
            if(visited[i]) continue;
            bool isTree = true;
            // 현재, 과거
            std::queue<std::pair<int, int>> q;
            q.push({i, 0});
            visited[i] = 1;

            while(!q.empty()) {
                int cur = q.front().first;
                int prev = q.front().second;
                q.pop();

                for(int nxt : adj[cur]) {
                    // 과거 와 미래의 것이 같다는 것은 양방향으로 진행
                    if(nxt == prev) continue;

                    if(visited[nxt] == 1) {
                        isTree = false;
                        continue;
                    } 

                    q.push({nxt, cur});
                    visited[nxt] = 1;
                }
            }

            if(isTree) trees++;
        }

        if(trees > 1) { 
            std::cout << "Case " << t <<  ": A forest of " << trees <<" trees.";
        }

        else if(trees == 1) {
            std::cout << "Case " << t << ": There is one tree.";
        }

        else {
            std::cout << "Case " << t << ": No trees.";
        }

        std::cout << "\n";
    }

    return 0;

}