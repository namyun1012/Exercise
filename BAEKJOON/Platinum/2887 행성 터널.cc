#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
/*
    구할 거리를 최소화하고
    그 이후 MST를 생성
    필요한 값을 찾고 진행
    x,y,z 끼리 정렬
    x, y, z 간선들끼리 비교 그리고 그리고 간선을 MST에 추가
    결국 1개씩은 다 연결됨

*/
// 별 저장용
// 지점, 번호
std::vector<std::pair<int, int>> x_vec;
std::vector<std::pair<int, int>> y_vec;
std::vector<std::pair<int, int>> z_vec;
// 거리, 끝 지점, 시작 지점
std::vector<std::pair<int, int>> adj[100002];
int visited[100002];


int main() {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        int x,y,z;
        std::cin >> x >> y >> z;
        x_vec.push_back({x, i});
        y_vec.push_back({y, i});
        z_vec.push_back({z, i});
    }

    std::sort(x_vec.begin(), x_vec.end());
    std::sort(y_vec.begin(), y_vec.end());
    std::sort(z_vec.begin(), z_vec.end());


    // adj에 간선을 추가한다.
    for(int i = 0; i < n-1; i++) {
        // i 와 i + 1의 거리
        int x_temp = x_vec[i+1].first - x_vec[i].first;
        adj[x_vec[i].second].push_back({x_temp, x_vec[i+1].second});
        adj[x_vec[i+1].second].push_back({x_temp, x_vec[i].second});


        int y_temp = y_vec[i+1].first - y_vec[i].first;
        adj[y_vec[i].second].push_back({y_temp, y_vec[i+1].second});
        adj[y_vec[i+1].second].push_back({y_temp, y_vec[i].second});

        int z_temp = z_vec[i+1].first - z_vec[i].first;
        adj[z_vec[i].second].push_back({z_temp, z_vec[i+1].second});
        adj[z_vec[i+1].second].push_back({z_temp, z_vec[i].second});
    }


    // 0번 부터 시작하는 MST 만들기
    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>,
                        std::greater<std::tuple<int, int, int>> > pq;

    
    visited[0] = 1;
    // 0번과 관련된 간선 1개씩 집어넣기
    for(auto nxt : adj[0]) {
        pq.push({nxt.first, 0, nxt.second});
    }
    
    long long result = 0;
    while(!pq.empty()) {
        int weight, st, en;
        std::tie(weight, st, en) = pq.top();
        pq.pop();
        if(visited[en]) continue;

        // visited는 여기서 해주자 밑에서 하면
        // priority_queue 특성상 망가짐
        result += weight;
        visited[en] = 1;

        for(auto nxt : adj[en]) {
            if(visited[nxt.second]) continue;
            pq.push({nxt.first, en, nxt.second});
            
        }

    }

    std::cout << result;
    return 0;
}