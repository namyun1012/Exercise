/*
    트리의 거리는 BFS로 구하는 것이 가능함, 갱신이 안됨
    다익스트라 등을 사용할 필요는 없음
    전부다 진행할 시 시간초과남 >> 트리의 지름을 구하는 식이 따로 있음
    1. 임의의 정점 x을 잡고 x 에서 가장 먼 정점 y를 구함
    2. y에서 가장 먼 정점 z를 구함
    3. 트리의 지름은 y와 z 사이의 거리임

    트리 dp도 가능하다고 함
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// 끝, 거리 값
std::vector<std::pair<int, int>> adj[100002];
int visited[100002];
long long result = 0;

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    int n;
    std::cin >> n;

    //그래프 생성
    for(int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        
        
        while(true) {
            int temp_num, temp_dis;
            std::cin >> temp_num;
            
            if(temp_num == -1) break;
            std::cin >> temp_dis;
            adj[num].push_back({temp_num, temp_dis});
        }
    }
    int vertex = 0;
    // 1 부터 가장 먼 정점을 찾음
    std::fill(visited, visited+n+1, 0);
    std::queue<std::pair<int, long long>> q;

    q.push({1,0});
    visited[1] = 1;

    while(!q.empty()) {
        auto cur = q.front();
        if(result < cur.second) {
            result = cur.second;
            vertex = cur.first;
        }   
        q.pop();

        for(auto nxt : adj[cur.first]) {
            if(visited[nxt.first]) continue;
            q.push({nxt.first, cur.second + nxt.second});
            visited[nxt.first] = 1;
        }
    }

    std::fill(visited, visited+n+1, 0);
    result = 0;
    q.push({vertex, 0});
    visited[vertex] = 1;

    while(!q.empty()) {
        auto cur = q.front();
        result = std::max(result, cur.second);
        q.pop();

        for(auto nxt : adj[cur.first]) {
            if(visited[nxt.first]) continue;
            q.push({nxt.first, cur.second + nxt.second});
            visited[nxt.first] = 1;
        }
    }
    
    
    std::cout << result;
    return 0;
}