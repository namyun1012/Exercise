#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

std::pair<float, float> stars[102];
std::vector<std::pair<float, int>> adj[102]; // <Value, End>

int visited[102];

float distance(float x1, float y1, float x2, float y2) {
    return sqrtf(powf(x1 - x2, 2) +  powf(y1 - y2,2));
}


int main() {
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> stars[i].first >> stars[i].second;
    }

    for(int i = 2; i <= n ; i++) { // 그래프 만들기
        for(int j = 1; j <= i-1; j++) {
            float dis = distance(stars[i].first, stars[i].second,stars[j].first, stars[j].second);
            adj[i].push_back({dis, j});
            adj[j].push_back({dis, i});
        }
    }

    std::priority_queue<std::tuple<float, int, int>,
                        std::vector<std::tuple<float, int, int>>,
                        std::greater<std::tuple<float, int, int>> > pq; // 최소힙 만들기 

    float result = 0.0;
    int cnt = 1;

    visited[1] = 1;
    for(auto nxt : adj[1]) {
        pq.push({nxt.first, 1, nxt.second});
    }

    while(cnt <= n-1) {
        float cost;
        int start, end;
        std::tie(cost, start, end) = pq.top(); // pq에서 cost 가 최솟값 부터 선정함
        pq.pop();

        if(visited[end]) continue; // 이미 방문했던 지점이면 간선을 pq 에 추가 해 주었기 때문에 별 필요 없음
        visited[end] = 1;
        result += cost;
        cnt++;

        for(auto nxt : adj[end]) {
            if(visited[nxt.second]) continue;
            pq.push({nxt.first, end, nxt.second});
        }
    }

    std::cout.precision(3);
    std::cout << result;
    return 0;
}