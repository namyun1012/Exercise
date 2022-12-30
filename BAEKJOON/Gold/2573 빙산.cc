#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
/*
    그럭저럭 품
*/
using namespace std;

int board[302][302];
int visited[302][302];
int checked[302][302];

int n, m;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > m) return true;
    return false;
}

int main() {
    cin >> n >> m;
    int sum = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
            sum += board[i][j];
        }
    }

    int time = 0;
    while(true) {
        // 우선 빙산이 바람에 의해 녹음
        fill(&visited[0][0], &visited[301][301], 0);
        fill(&checked[0][0], &checked[301][301], 0);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(visited[i][j] || board[i][j] == 0) continue;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;

                int temp_sum = 0;

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();
                    temp_sum += board[cur.first][cur.second];

                    for(int dir = 0; dir < 4; dir++) {
                        int nxt_x = cur.first + dx[dir];
                        int nxt_y = cur.second + dy[dir];

                        if(OOP(nxt_x, nxt_y)) continue;
                        if(visited[nxt_x][nxt_y]) continue;
                        
                        if(board[nxt_x][nxt_y] == 0) {
                            checked[cur.first][cur.second]++;
                            continue;
                        }

                        q.push({nxt_x, nxt_y});
                        visited[nxt_x][nxt_y] = 1;

                    }
                }
                
                if(temp_sum != sum) {
                    cout << time;
                    exit(0);
                }
            }
        }


        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(board[i][j] < checked[i][j]) {
                    sum -= board[i][j];
                    board[i][j] = 0;
                }

                else {
                    board[i][j] -= checked[i][j];
                    sum -= checked[i][j];
                }
            }
        }
        
        if(sum == 0) break;
        time++;
    }

    cout << 0;
}