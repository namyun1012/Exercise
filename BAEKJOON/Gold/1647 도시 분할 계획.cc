#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

int visited[100002];
std::vector<std::pair<int, int>> adj[100002];
/*
    무난하게 풀림
    우선 MST를 만듬 그리고 그 중에서 가장 큰 경로를 빼버림


*/
int main() {
    int result = 0;
    int max_value = 0;

    int n, m;
    std::cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int fromV, toV, weight;
        std::cin >> fromV >> toV >> weight;
        adj[fromV].push_back({weight, toV});
        adj[toV].push_back({weight, fromV}); // 양방향 경로임
    }

    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>,
                        std::greater<std::tuple<int, int, int>> > pq;

    
    visited[1] = 1;
    for(auto nxt : adj[1]) {
        pq.push({nxt.first, 1, nxt.second});
    }
    
    while(!pq.empty()) {
        int fromV, toV, weight;
        std::tie(weight, fromV, toV) = pq.top(); pq.pop();

        if(visited[toV]) continue;
        result += weight;
        max_value = std::max(weight, max_value);
        visited[toV] = 1;

        for(auto nxt : adj[toV]) {
            if(visited[nxt.second]) continue;
            pq.push({nxt.first, toV, nxt.second});
        }
    }

    std::cout << result - max_value ;
    return 0;
}