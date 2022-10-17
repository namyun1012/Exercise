#include <iostream>
#include <algorithm>
#include <queue>
// N이 0 일때의 고려가 필요함

int board[100005];
int visited[100005];
int distance[100005];

int dx[2] = {1,-1};

int main() {
    int N, K;
    std::cin >> N >> K;


    std::queue<int> q;
    
    for(int i = N; i <= 100000; i *= 2) {
        
        q.push(i);
        visited[i] = 1;
        distance[i] = 0;
        if(i == 0) break;
    }

    while ((!q.empty())) {
        if(distance[K] != 0) break;
        int cur = q.front();
        q.pop();

        for(int dir = 0; dir < 2; dir++) {
            int nxt = cur + dx[dir];
            if(nxt < 0 || nxt > 100000) continue;
            if(visited[nxt]) continue;
            
            for(int i = nxt; i <= 100000; i *= 2) {
                if(visited[i]) break;
                q.push(i);
                visited[i] = 1;
                distance[i] = distance[cur] + 1;
                if(i == 0) break;
            }
        }
        
    }
    
    std::cout << distance[K];
    return 0;
}