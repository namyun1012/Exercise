#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1e9

std::vector<std::pair<int, int>> adj[1002];
int distances[1002];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int N,M;
    std::cin >> N >> M;
    int u,v,w;
    for(int i = 0; i < M; i++) {
        std::cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    int startV, toV;
    std::cin >> startV >> toV;

    std::fill(distances, distances+N+1, INF);
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>> pq;

    //{w, v} 가중치, 끝나는 지점

    distances[startV] = 0;
    pq.push({0, startV});

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(distances[cur.second] != cur.first) continue;
        for(std::pair<int, int> nxt : adj[cur.second]) {
            if(distances[nxt.second] <= distances[cur.second] + nxt.first) continue; // nxt 거리가 현재 거리와 간선 합과 작거나 같을 시 할 필요 X 
            distances[nxt.second] = distances[cur.second] + nxt.first;
            pq.push({distances[nxt.second], nxt.second});
        }
    }

    std::cout << distances[toV];
    return 0;
}