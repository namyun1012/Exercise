#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1e9
/*
    다익스트라를 n + 1번 정도하면 해결
    다익스트라를 잘 알아두자

*/
std::vector<std::pair<int, int>> adj[1002];
int distances[1002];
int x_to_distances[1002];
int main() {
    int n, m, x;
    std::cin >> n >> m >> x;

    for(int i = 0; i < m; i++) {
        int fromV, toV, weight;
        std::cin >> fromV >> toV >> weight;
        adj[fromV].push_back({weight, toV});
    }

        std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>> > pq;
        
        std::fill(x_to_distances, x_to_distances + n + 1, INF);

        x_to_distances[x] = 0;
        pq.push({0, x});
        
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            if(x_to_distances[cur.second] < cur.first) continue;
            for(std::pair<int, int> nxt : adj[cur.second]) {
                if(x_to_distances[nxt.second] < x_to_distances[cur.second] + nxt.first) continue;
                x_to_distances[nxt.second] = x_to_distances[cur.second] + nxt.first;
                pq.push({x_to_distances[nxt.second], nxt.second});

            }
        }

    

    int result = 0;
    for(int i = 1; i <= n ; i++ ) {
        std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>> > pq;
        
        // distance를 INF로 초기화
        std::fill(distances, distances + n + 1, INF);

        // 시작점 설정
        distances[i] = 0;
        pq.push({0, i});
        
        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            // 현재 점 까지의 거리보다 현재 간선의 길이가 클 경우 무시함
            if(distances[cur.second] < cur.first) continue;
            for(std::pair<int, int> nxt : adj[cur.second]) {
                // 다음 노선의 거리가 현재 점 까지의 거리 + 다음 노선
                if(distances[nxt.second] < distances[cur.second] + nxt.first) continue;
                
                distances[nxt.second] = distances[cur.second] + nxt.first;
                pq.push({distances[nxt.second], nxt.second});

            }
        }

        result = std::max(result, distances[x] + x_to_distances[i]);
    }

    std::cout << result;
    return 0;
}
