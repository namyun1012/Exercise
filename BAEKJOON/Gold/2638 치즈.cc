#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
/*
    외부 공기의 이해를 잘못함
    빈칸으로 BFS를 돌리면 될 듯
    시작점을 0,0으로 줘가지고 OOP에서 다 걸림
    
*/
int n, m;
int board[102][102];
int visited[102][102];
int contacted[102][102];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > m) return true;
    return false;
}

bool check() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j]) return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    int time = 0;
    while(check()) {
        queue<pair<int, int>> q;
        q.push({1, 1});
        visited[1][1] = 1;

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            for(int dir = 0; dir < 4; dir++) {
                int nxt_x = cur.first + dx[dir];
                int nxt_y = cur.second + dy[dir];

                if(OOP(nxt_x, nxt_y)) continue;
                if(visited[nxt_x][nxt_y]) continue;
                if(board[nxt_x][nxt_y] == 1) {
                    contacted[nxt_x][nxt_y]++;
                    continue;
                }   

                q.push({nxt_x, nxt_y});
                visited[nxt_x][nxt_y] = 1;
            }

        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(contacted[i][j] >= 2) board[i][j] = 0;
            }
        }

        fill(&visited[0][0], &visited[101][101], 0);
        fill(&contacted[0][0], &contacted[101][101], 0);
        time++;
    }


    cout << time;
    return 0;
}