#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

int arr[302];
std::vector<std::pair<int, int>> adj[302];
int visited[302];
/*
    가상의 노드를 만들어서 더하는 방향으로 구해야 했다.
    각 노드에 접근 할 때 물 파는 비용이랑 최솟값을 비교하는 방법은 안됨
    접근 할 때 그게 최소 치인지 모름 + 

*/
int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    int n;
    int min_result = 1e9;
    std::cin >> n;

    for(int i = 1; i <= n ; i++) {
        std::cin >> arr[i];
    }
    
    for(int i = 1; i <= n ; i++) {
        adj[0].push_back({arr[i], i});
    }


    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= n; j++) {
            int temp;
            std::cin >> temp;
            adj[i].push_back({temp, j});
        }
    }
                        // W ,start ,To
    

    
    
   
   
        
        std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>,
                        std::greater<std::tuple<int, int, int>> > pq;

        visited[0] = 1;
        int result = 0;
        
        for(auto nxt : adj[0]) {
            pq.push({nxt.first,  0, nxt.second});
        }


        while(!pq.empty()) {
            int weight, st, en;
            std::tie(weight, st, en) = pq.top();
            pq.pop();

            if(visited[en]) continue;
            visited[en] = 1;
            result += weight;



            for(auto nxt : adj[en]) {
                if(visited[nxt.second]) continue;
                pq.push({nxt.first, en, nxt.second});
            }
        }
    
    
    std::cout << result;
    return 0;
}