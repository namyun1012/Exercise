#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
std::vector<std::pair<int, int>> adj[1002];
int board[1002][1002];
int visited[1002];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int v;

    std::cin >> v;
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            std::cin >> board[i][j];
        }
    }

    // 밑에 있는 삼각형만 구해서 무방향 그래프 만들기
    for(int i = 2; i <= v ; i++) {
        for(int j = 1; j <= i-1; j++) {
            adj[i].push_back({board[i][j], j});
            adj[j].push_back({board[i][j], i});
        }
    }
    
    std::priority_queue<std::tuple<int, int, int>, 
                        std::vector<std::tuple<int, int, int>>,
                        std::greater<std::tuple<int, int, int>>> pq; //최소 힙

    int cnt = 1; // 최소 신장 트리의 간선 개수는 V-1개이다.
    long long result = 0; // 결괏값이 클 수도 있음
    visited[1] = 1; // 시작 지점은 상관 없음
    
    for(auto nxt : adj[1])
        pq.push({nxt.first, 1, nxt.second}); // <값, 시작, 끝>
    
    while(cnt <= v-1) { // 간선의 수가 V-1개가 될 때까지
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