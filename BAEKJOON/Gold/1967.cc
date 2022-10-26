#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*
    모든 노드 사이의 거리를 bfs로 구함
    그 중 최댓값을 찾음
    다익스트라, 플로이드 안 써도 되는 이유
    트리에서는 한 정점에서 다른 정점으로 가는 길이 단 1개 밖에 없기 때문임
    거리 갱신이 안 됨
*/
std::vector<std::pair<int, int>> adj[10003];
int visited[10002];

int result = 0;

int main() {
    int n;
    std::cin >> n;

    int fromV, toV, weight;
    for(int i = 0; i < n-1; i++) {
        std::cin >> fromV >> toV >> weight;
        adj[fromV].push_back({toV, weight});
        adj[toV].push_back({fromV, weight});
    }

    for(int i = 1; i <=  n; i++) {
        std::fill(visited, visited+n, 0);
        std::queue<std::pair<int, int>> q; // 점, 거리
        q.push({i,0});

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            result = std::max(result, cur.second);

            for(auto nxt : adj[cur.first]) {
                if(visited[nxt.first]) continue;
                visited[nxt.first] = 1;
                q.push({nxt.first, nxt.second + cur.second});
            }
        }
    }
    std::cout << result;
    return 0;
}