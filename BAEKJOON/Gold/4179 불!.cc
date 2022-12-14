#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
/*
    불과 지훈의 순서를 잘 알아둬야 함

*/
int r, c;
char board[1002][1002];

// Jihoon = 1 Fire - 2
int visited[1002][1002];
int distance[1002][1002];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > r || y > c) return true;
    return false;
}

std::vector<std::pair<int, int>> fires;
std::pair<int, int> jihoon;
int main() {

    std::queue<std::pair<int, int>> q;

    std::cin >> r >> c;

    for(int i = 1; i <= r; i++) {
        std::string temp;
        std::cin >> temp;

        for(int j = 1; j <= c; j++) {
            board[i][j] = temp[j-1];
            
            if(board[i][j] == 'F') {
                visited[i][j] = 2;
                fires.push_back({i, j});
            }

            if(board[i][j] == 'J') {
                visited[i][j] = 1;
                jihoon = {i, j};
            }
        }
    }

    
    for(auto fire : fires) {
        q.push({fire.first, fire.second});
    }
    q.push({jihoon.first, jihoon.second});

    bool failed = true;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nxt_x = cur.first + dx[dir];
            int nxt_y = cur.second + dy[dir];

            if(OOP(nxt_x, nxt_y) && visited[cur.first][cur.second] == 2) continue;
            if(visited[nxt_x][nxt_y] || board[nxt_x][nxt_y] == '#') continue;
            
            q.push({nxt_x, nxt_y});
            visited[nxt_x][nxt_y] = visited[cur.first][cur.second];
            distance[nxt_x][nxt_y] = distance[cur.first][cur.second] + 1;

            if(OOP(nxt_x, nxt_y) && visited[cur.first][cur.second] == 1) {
                std::cout << distance[nxt_x][nxt_y];    
                failed = false;
                exit(0);
            }
        }
        
    }
    
    std::cout << "IMPOSSIBLE";
    return 0;
    
}