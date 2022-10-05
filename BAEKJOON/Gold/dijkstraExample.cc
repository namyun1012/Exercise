#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9 

int distances[20002];
std::vector<std::pair<int, int>> adj[20002];
// weight, v
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
    // wieght, V

    distances[K] = 0;
    pq.push({0, K});

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(distances[cur.second] != cur.first) continue;
        for(std::pair<int, int> nxt : adj[cur.second]) {
            if(distances[nxt.second] <= distances[cur.second] + nxt.first) continue;
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