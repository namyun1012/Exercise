#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

/*
    벨만 포드 배워보기
    음수 사이클 찾고 벨만 포드 진행해야 할 듯
    시작 지점이 INF인 곳은 무시해야 함
    
*/
#define INF 1e12


long long distances[502];
std::tuple<int, int, int> edges[6006];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int fromV, toV, weight;
        std::cin >> fromV >> toV >> weight;
        edges[i] = {fromV, toV, weight};
    }

    std::fill(distances, distances + n + 1, INF);
    bool cycle_check = false;

    distances[1] = 0;
    // 1번과 연결 되어있는 지 확인이 필요하다.
    for(int i = 1; i <= n; i++) {
        if(i == n) {
            for(auto e : edges) {
                int fromV, toV, weight;
                std::tie(fromV, toV, weight) = e;
                if(distances[fromV] == INF) continue;
                if(distances[toV] == INF) continue;
                
                if(distances[toV] > distances[fromV] + weight)
                    cycle_check = true;
            }

        }

        else {
            for(auto e : edges) {
                int fromV, toV, weight;
                std::tie(fromV, toV, weight) = e;
                if(distances[fromV] == INF) continue;
                distances[toV] = std::min(distances[toV], distances[fromV] + weight);
            }

        }
    }
    
    if(!cycle_check) {
        for(int i = 2; i <= n; i++) {
            if(distances[i] == INF)
                std::cout << -1 << "\n";
            else
                std::cout << distances[i] << "\n";
        }
    }

    else {
        std::cout << -1;
    }


    return 0;
}

