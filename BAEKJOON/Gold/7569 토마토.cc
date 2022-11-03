#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

int tomatoes[102][102][102]; // 가로ㅡ 세로 - 높이 (원래의 y, x, h)
bool visited[102][102][102]; // 
int distances[102][102][102];

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dh[6] = {0,0,0,0,1,-1};
/*
    생각하기 귀찮아서 h,n,m 순서를 계속 바꿔보니까 됨

*/

int main() {
    int h, n, m;
    std::cin >> m >> n >> h; // m = 높이 n = 세로 h = 가로  선언을 반대로 했어야 함
    int result = 0;

    for(int i = 1; i <= h; i++) { // 
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                std::cin >> tomatoes[i][j][k];
            }
        }
    }

    std::queue<std::tuple<int, int, int>> q;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                if(tomatoes[i][j][k] == 1) {
                    q.push({i,j,k});
                    visited[i][j][k] = 1;
                }
            }
        }
    }

    while(!q.empty()) {
        int cur_h, cur_x ,cur_y;
        
        std::tie(cur_h,cur_x,cur_y) = q.front();
        result = std::max(result, distances[cur_h][cur_x][cur_y]);
        q.pop();

        for(int dir = 0; dir < 6; dir++) {
            int nxt_h = cur_h + dh[dir];
            int nxt_x = cur_x + dx[dir];
            int nxt_y = cur_y + dy[dir];
            
            if(nxt_h < 1 || nxt_x < 1 || nxt_y < 1 || nxt_h > h || nxt_x > n || nxt_y > m) continue;
            if(visited[nxt_h][nxt_x][nxt_y] || tomatoes[nxt_h][nxt_x][nxt_y] != 0) continue;
            
            q.push({nxt_h, nxt_x, nxt_y});
            visited[nxt_h][nxt_x][nxt_y] = 1;
            distances[nxt_h][nxt_x][nxt_y] = distances[cur_h][cur_x][cur_y] + 1;
        }
    }

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                if(visited[i][j][k] == 0 && tomatoes[i][j][k] == 0) {
                    result = -1;
                    break;
                }
            }
        }
    }

    std::cout << result;
    return 0;
}