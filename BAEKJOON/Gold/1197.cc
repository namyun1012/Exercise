#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

//비용, 정점 번호
std::vector<std::pair<int, int>> adj[10002];
int visited[10002]; // 이 정점을 방문했는가?

int cnt = 0;
int result = 0;

int main() {
    int V, E;
    std::cin >> V >> E;

    int startV, toV, weight;
    for(int i = 0; i < E; i++) {
        std::cin >> startV >> toV >> weight;
        adj[startV].push_back({weight, toV}); // 무방향 그래프이므로 쌍으로
        adj[toV].push_back({weight, startV});
    }
    //weigth, startV, toV
    std::priority_queue<std::tuple<int, int, int>, 
                        std::vector<std::tuple<int, int, int>>,
                        std::greater<std::tuple<int, int, int>>> pq; //최소 힙

    visited[1] = 1;
    for(auto nxt : adj[1])
        pq.push({nxt.first, 1, nxt.second});
    
    while(cnt < V-1) { // 간선의 수가 V-1개가 될 때까지
        int c, start, end;
        std::tie(c, start, end) = pq.top();
        pq.pop();
        

        if(visited[end]) continue;
        visited[end] = 1;
        cnt++;
        result += c;

        for(auto nxt : adj[end]) {
            if(!visited[nxt.second])
                pq.push({nxt.first, end, nxt.second});
            

        }

    }

    std::cout << result;
    return 0;
}