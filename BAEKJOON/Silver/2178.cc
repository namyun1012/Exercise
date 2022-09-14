#include <iostream>
#include <queue>
#include <string>
#define X first
#define Y second

int board[502][502] = {};
bool vis[502][502];


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n,m;
    std::cin >> n >> m;
    std::queue<std::pair<int, int>> q;
    int result = 0;
    std::string str;
    std::pair<int, int> end_pair = {n-1, m-1};
    for(int i = 0; i < n; i++) {
        std::cin >> str;
        for(int j = 0; j < m; j++)
            board[i][j] = str[j] -'0';
    }

    vis[0][0] = 1;
    q.push({0, 0});

    while(!q.empty()) {
        std::pair<int, int> cur = q.front();
        if(cur == end_pair) break;
        q.pop();
        result++;

        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx <0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    std::cout << result;
    return 0;
}