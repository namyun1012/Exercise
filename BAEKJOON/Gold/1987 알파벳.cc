#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
/*
    백트래킹임을 알고리즘 분류 보고 알음
*/
int board[22][22];
int visited[30];

std::vector<int> temp_vec;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int r, c;
int result = 0;

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > r || y > c) return true;
    return false;
}

void dfs(int x, int y) {
    result = std::max(result, (int)temp_vec.size());

    for(int dir = 0; dir < 4; dir++) {
        int nxt_x = x + dx[dir];
        int nxt_y = y + dy[dir];
        if(visited[board[nxt_x][nxt_y]]) continue;
        if(OOP(nxt_x, nxt_y)) continue;
        visited[board[nxt_x][nxt_y]] = 1;
        temp_vec.push_back(board[nxt_x][nxt_y]);
        dfs(nxt_x, nxt_y);
        temp_vec.pop_back();
        visited[board[nxt_x][nxt_y]] = 0;

    }
}

int main() {
    
    std::cin >> r >> c;

    for(int i = 1; i <= r; i++) {
        std::string temp;
        std::cin >> temp;
        for(int j = 1; j <= c; j++) {
            board[i][j] = int(temp[j-1] - 'A');
        }
    }
    
    visited[board[1][1]] = 1;
    temp_vec.push_back(board[1][1]);
    dfs(1,1);

    
    std::cout << result;
}