#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
/*
void fill (ForwardIterator first, ForwardIterator last, const T& val);
last 는 포함이 안되니까 + 1이 필요했다.

*/
int n, m;
int board[9][9];
int used[9][9];

int result = 0;
int visited[9][9];

std::vector<std::pair<int, int>> walls;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int count = 0;
void bfs();

void selectWall() {
    if(walls.size() == 3) {
        bfs();
        return ;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j]|| used[i][j]) continue;
                
                used[i][j] = 1;
                board[i][j] = 1;
                walls.push_back({i,j});
                
                selectWall();
                
                walls.pop_back();
                used[i][j] = 0;
                board[i][j] = 0;
        }
    }
}


void bfs() {
    std::fill(&visited[0][0], &visited[8][8] + 1, 0); // visited[8][8] 에서 + 1을 해주니까 해결되었다..
    std::queue<std::pair<int, int>> q;

    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j] == 2) {
                q.push({i,j});
                visited[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nxt_x = cur.first + dx[dir];
            int nxt_y = cur.second + dy[dir];

            if(nxt_x < 1 || nxt_y < 1 || nxt_x > n || nxt_y > m) continue;
            if(board[nxt_x][nxt_y] || visited[nxt_x][nxt_y]) continue;
            q.push({nxt_x, nxt_y});
            visited[nxt_x][nxt_y] = 1;

        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(visited[i][j] == 0 && board[i][j] == 0)
                sum++;
        }
    }
    
    result = std::max(result, sum);
}
int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= m ; j++) {
            std::cin >> board[i][j];
        }
    }

    selectWall();

    std::cout << result << "\n";
    return 0;
}