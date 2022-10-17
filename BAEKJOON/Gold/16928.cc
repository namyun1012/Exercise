#include <iostream>
#include <queue>

int board[102];
int ladder[102];
int distance[102];
bool visited[102];


int main() {
    int N, M;
    std::cin >> N >> M;
    
    int fromV, toV;

    for(int i = 0; i < N+M; i++) {
        std::cin >> fromV >> toV;
        ladder[fromV]= toV;
    }

    std::queue<int> q;
    int st = 1;

    visited[st] = true;
    q.push({st});
    distance[st] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        while(ladder[cur] != 0) {
            distance[ladder[cur]] = distance[cur];
            cur = ladder[cur]; // 무조건 이동
            
        }

        for(int i = 1; i <= 6; i++) {
            int nxt = cur + i;
            if(nxt > 100) continue;
            if(visited[nxt]) continue;
            
            q.push(nxt);
            visited[nxt] = true;
            distance[nxt] = distance[cur] + 1;

        }
    }
    std::cout << distance[100];
    return 0;
}