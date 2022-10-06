#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9 

int distances[20002];
std::vector<std::pair<int, int>> adj[20002];
// weight, v priority queue 이용 
int main() {
    int V, E, K;
    std::cin >> V >> E >> K;

    int u,v,w;
    for(int i = 0; i < E; i++) {
        std::cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    std::fill(distances, distances+V+1, INF);
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>> pq;
    // {weight, v} min Heap

    distances[K] = 0;
    pq.push({0, K}); // {0, start} 넣음

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        //해당 원소 중 가장 작은 원소 선정, 해당 거리가 최단 거리 테이블 값과 다를 경우 넘어감
        if(distances[cur.second] != cur.first) continue; // 가장 작은 원소는 이미 예전에 진행해서 필요 없음
        for(std::pair<int, int> nxt : adj[cur.second]) {
            if(distances[nxt.second] <= distances[cur.second] + nxt.first) continue; // nxt 거리가 현재 거리와 간선 합과 작거나 같을 시 할 필요 X 
            distances[nxt.second] = distances[cur.second] + nxt.first;
            pq.push({distances[nxt.second], nxt.second});
        }

    }

    for(int i = 1 ; i <= V ; i++) {
        if(distances[i] == INF) std::cout << "INF" << "\n";
        else std::cout << distances[i] << "\n";
    }

    return 0;
}