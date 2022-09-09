#include <iostream>
#include <queue>
#define X first
#define Y second

int board[52][52] = {};
bool vis[52][52];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int T;
    std::cin >> T;
    while(T--) {

    int n,m,k;
    std::cin >> m >> n >> k;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            board[i][j] = 0;
            vis[i][j] = false;
        }
    }
    
    int images = 0; // Bugs
    
    for(int i = 0; i < k; i++) {
        int x,y;
        std::cin >> x >> y;
        board[y][x] = 1;
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
            
                
            }

            
        }
    }
    
    std::cout << images << "\n";
    
    
    }
    return 0;
}