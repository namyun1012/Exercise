#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
/*
    BFS 응용 문제
*/
int board[100002];
int visited[100002];
int dis[100002];
int n, k;

bool OOP(int x) {
    if(x < 0 || x > 100000) return true;
    return false;
}

int main() {
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while(!q.empty()) {
        
        int cur = q.front();
        // Testing code cout << cur << " " << dis[cur] << " " << visited[cur] << "\n";
        q.pop();
        
        for(int dir = 0; dir < 3; dir++) {
            int nxt;
            if(dir == 0) nxt = cur + 1; 
            else if(dir == 1) nxt = cur - 1;
            else nxt = cur * 2;

            if(OOP(nxt)) continue;
            // 방문을 했고 다음 거리가 현재 거리보다 큰 경우는 조사 필요 없음
    
            // 방문을 안했을 경우에는 추가
            if(!visited[nxt]) {
                visited[nxt] += visited[cur];
                q.push(nxt);
                dis[nxt]= dis[cur] + 1;
            }
            
            // 방문을 했던 경우에는 흔적만 남겨줌
            else if(visited[nxt] && (dis[nxt] == dis[cur] + 1))
                visited[nxt] += visited[cur];

        }
        
    }

    cout << dis[k] << "\n" << visited[k];
}