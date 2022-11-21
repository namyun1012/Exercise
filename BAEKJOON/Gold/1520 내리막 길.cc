#include <iostream>
#include <algorithm>
#include <queue>
/*
    x,y 에서는 끝까지 갈 수 잇는 경로의 수 저장하기


*/
int board[502][502];
int x, y;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool OOP(int a, int b) {
    if(a < 1 || b < 1 || a > x || b > y)
        return true;

    return false;
}


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    
    std::cin >> x >> y;

    for(int i = 1; i <= x; i++) {
        for(int j = 1; j <= y ; j++) {
            std::cin >> board[i][j];
        }
    }

    int result = 0;
    std::queue<std::pair<int, int>> q;
    q.push({1, 1});


    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        if(cur.first == x && cur.second == y) {
            result++;
            continue;
        }


        for(int dir = 0; dir < 4; dir++) {
            int nxt_x = cur.first + dx[dir];
            int nxt_y = cur.second + dy[dir];

            if(OOP(nxt_x, nxt_y)) continue;
            if(board[nxt_x][nxt_y] >= board[cur.first][cur.second]) continue;
            q.push({nxt_x, nxt_y});
        }


    }
    std::cout << result;
    return 0;
}