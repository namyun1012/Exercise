#include <iostream>
#include <vector>
#include <string>
#include <queue>


using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

char board[12][12];
int visited[12][12][12][12];
int distance[12][12];

int n, m;

pair<int, int> red;
pair<int, int> blue;
pair<int, int> hole;
/*
    red와 blue의 좌표를 함께 큐의 값으로 받아야 할 듯
    무수히 많은 조정
    좌표 이동하는 방식
    개수 조건 등을 여러가지 조절해야 했음

*/

int result = 0;

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > m) return true;
    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        for(int j = 1; j <= m; j++) {
            board[i][j] = temp[j-1];
            if(board[i][j] == 'R') red = {i, j};
            if(board[i][j] == 'B') blue = {i, j};
            if(board[i][j] == 'O') hole = {i, j};
        }
    }


    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{red.first, red.second}, {blue.first, blue.second}});
    // 0번 이동 했을 때 1, 1번 이동 했을 때 2 
    visited[red.first][red.second][blue.first][blue.second] = 1;

    while(!q.empty()) {
        
        auto cur_red = q.front().first;
        auto cur_blue = q.front().second;
        // Testing std::cout << cur_red.first << " " << cur_red.second << " " << cur_blue.first << " " << cur_blue.second <<  "\n";
        if(visited[cur_red.first][cur_red.second][blue.first][blue.second] > 10) {
            std::cout << -1;
            exit(0);
            break;
        }

        q.pop();
        

        for(int dir = 0; dir < 4; dir++) {
        // cur_red의 이동 끝까지
            bool red_reached = false;
            bool blue_reached = false;


            int nxt_red_x = cur_red.first;
            int nxt_red_y = cur_red.second;
            int nxt_blue_x = cur_blue.first;
            int nxt_blue_y = cur_blue.second;
            
            // Red 우선 이동
            while(true) {      
                if(board[nxt_red_x + dx[dir]][nxt_red_y + dy[dir]] != '#' && board[nxt_red_x][nxt_red_y] != 'O') {
                    nxt_red_x += dx[dir];
                    nxt_red_y += dy[dir];
                    continue;
                }

                if(board[nxt_red_x][nxt_red_y] == 'O') {
                    red_reached = true;
                    break;
                }

                break;
            }
            // Blue 이동
            while(true) {

                if(board[nxt_blue_x + dx[dir]][nxt_blue_y + dy[dir]] != '#' && board[nxt_blue_x][nxt_blue_y] != 'O') {
                    nxt_blue_x += dx[dir];
                    nxt_blue_y += dy[dir];
                    continue;
                }

                if(board[nxt_blue_x][nxt_blue_y] == 'O') {
                    blue_reached = true;
                    break;
                }
                break; 
            }
            // 구슬이 겹쳤을 때 dir가 현재 위치에 따라 변경
            // 0 ~ 3 남 북 동 서
    

            if(nxt_red_x == nxt_blue_x && nxt_red_y == nxt_blue_y) {
                if(dir == 0) {
                    // red 가 위에 있었을 때
                    if(cur_red.first < cur_blue.first)
                        nxt_red_x--;
                    else {
                        nxt_blue_x--;
                    }
                }

                else if(dir == 1) {
                    //
                    if(cur_red.first < cur_blue.first)
                        nxt_blue_x++;
                    else {
                        nxt_red_x++;
                    }
                }

                else if(dir == 2) {
                    // red가 왼쪽에 있었을 때
                    if(cur_red.second < cur_blue.second)
                        nxt_red_y--;
                    else
                        nxt_blue_y--;
                }

                else {
                    if(cur_red.second < cur_blue.second)
                        nxt_blue_y++;
                    else
                        nxt_red_y++;
                }
            }
           

            if(blue_reached) continue;

            if(red_reached && visited[cur_red.first][cur_red.second][cur_blue.first][cur_blue.second] <= 10) {
                std::cout << visited[cur_red.first][cur_red.second][cur_blue.first][cur_blue.second];
                exit(0);
            }
            if(visited[nxt_red_x][nxt_red_y][nxt_blue_x][nxt_blue_y]) continue;
            visited[nxt_red_x][nxt_red_y][nxt_blue_x][nxt_blue_y] = visited[cur_red.first][cur_red.second][cur_blue.first][cur_blue.second]  + 1;
            q.push({{nxt_red_x, nxt_red_y}, {nxt_blue_x, nxt_blue_y}});
        }

    }

    std::cout << -1;
    return 0;
}