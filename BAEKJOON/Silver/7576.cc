#include <iostream>
#include <queue>
#define X first
#define Y second

int board[502][502] = {};
bool vis[502][502];
int days[502][502];
int count = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isfull(int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0)
                return false;
        }
    }
    return true;
}
int main() {
    int n, m;
    std::cin >> n >> m;
    std::queue<std::pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j =0 ; j <m ;j++) {
            std::cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j =0 ; j <m ;j++) {
            if(board[i][j]== 1) {
                vis[i][j] = true;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()) {
        std::pair<int, int> cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx <0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] == -1) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    return 0;
}