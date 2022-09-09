#include <iostream>
#include <queue>
#define X first
#define Y second

int board[502][502] = {};
bool vis[502][502];


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n,m;
    std::cin >> n >> m;
    int result = 0;
    int images = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            std::cin >> board[i][j];
    }
    std::queue<std::pair<int, int>> q;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == 0 && board[i][j] == 1) {
                images++;
                int count = 1;
                vis[i][j] = 1;
                q.push({i, j});
                while(!q.empty()) {
                    std::pair<int, int> cur = q.front();
                    q.pop();

                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx <0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                        count++;
                    }
                }
            
                result = std::max(result, count);
            }

            
        }
    }
    
    std::cout << images << "\n" << result;
    return 0;
}