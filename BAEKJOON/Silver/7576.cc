#include <iostream>
#include <queue>
#define X first
#define Y second

int board[1002][1002] = {};
bool vis[1002][1002];
int days[1002][1002] ={};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m;
    std::cin >> m >> n;
    std::queue<std::pair<int, int>> q;
    std::pair<int, int> end_pair;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++) { // 시작점 여러개 검사해서 push
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1) {
                q.push({i,j});
                vis[i][j] = 1;
                days[i][j] = 0; // 거리 측정 0으로 설정
            }
        }
    }
    

    while(!q.empty()) {
        std::pair<int, int> cur = q.front();
        end_pair = cur; // 끝으로 방문하는 pair의 거리값
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx <0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] == -1) continue; // -1이 아닌 경우 방문해야 함
            vis[nx][ny] = 1;
            days[nx][ny] = days[cur.X][cur.Y] + 1; // 거리 측정
            q.push({nx, ny});
        }
    }

    bool check = true;
    // check_f 만약에 방문할 수 없는 것이 있을 경우
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;

            if(!vis[i][j] && board[i][j] != -1) {
                check = false;
                break;
            }
        }

        if(!check)  break;
    }
    
    if(check)
        std::cout << days[end_pair.X][end_pair.Y];
    else   
        std::cout << -1;
    
    return 0;
}