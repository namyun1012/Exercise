#include <iostream>
#include <algorithm>
#include <queue>
/*
    x,y 에서는 끝까지 갈 수 잇는 경로의 수 저장하기
    그래도 40 % 선에서 시간초과가 발생함
    어떻게 더 줄이는가?
    갈 수 있는 경로가 0인 경우도 기록하자

*/
int board[502][502];
int dp[502][502];
int visited[502][502];
int X, Y;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool OOP(int a, int b) {
    if(a < 1 || b < 1 || a > X || b > Y)
        return true;

    return false;
}

int dfs(int x, int y) {
    /*
        dp[X][Y] = 0 이 되므로 순서를 잘 고려해야함
        
    
    */

    if(x == X && y == Y) {
        return 1;
    }

    if(dp[x][y] != 0) return dp[x][y];
    if(visited[x][y]) return dp[x][y]; // 순서를 밑에다 두어야 함

    for(int dir = 0; dir < 4; dir++) {
        int nxt_x = x + dx[dir];
        int nxt_y = y + dy[dir];
        if(OOP(nxt_x, nxt_y)) continue;
        if(board[nxt_x][nxt_y] >= board[x][y]) continue;
        
        dp[x][y] += dfs(nxt_x, nxt_y);
        visited[nxt_x][nxt_y] = 1;
    }

    
    return dp[x][y];
    
}

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    
    std::cin >> X >> Y;

    for(int i = 1; i <= X; i++) {
        for(int j = 1; j <= Y ; j++) {
            std::cin >> board[i][j];
        }
    }

    dfs(1,1);

    std::cout << dp[1][1];
    return 0;
}