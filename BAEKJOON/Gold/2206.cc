#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

//모든 벽을 1개 씩 부수는 건 안됨
/*
    벽을 부쉈을 때랑 아닐 때랑 distance를 따로 관리해야 서로 중복이 안된다.

*/
int board[1002][1002];
int distance[1002][1002][2]; // distance 겸 visit 0 벽 안 부숨, 1 벽 부숨
int destroyed[1002][1002];

std::vector<std::pair<int, int>> walls;


int dx[4] ={1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int result = 1e9;
    int N, M;
    std::cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        std::string temp;
        std::cin >> temp;
        for(int j = 1; j <= M; j++) {
            board[i][j] = temp[j-1] - '0';
            if(board[i][j] == 1) {
                walls.push_back({i,j});
            }
        }
    } 
    
    std::queue<std::tuple<int, int, int>> q;

    q.push({1,1,0});
    distance[1][1][0] = 1;
    destroyed[1][1] = 0;

    while(!q.empty()) {
        int x, y, des;
        std::tie(x,y,des) = q.front();
        q.pop();
        
        if(x == N && y == M) {
            result = std::min(distance[N][M][des], result);
        }

       
        int cur_dis = distance[x][y][des];

        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir]; // nxt x ,y
            int ny = y + dy[dir];
            if(nx < 1 || ny < 1 || nx > N || ny > M) continue;

            if(board[nx][ny] == 0 && distance[nx][ny][des] == 0) {
                distance[nx][ny][des] = cur_dis + 1;
                q.push({nx, ny, des});
            }

            if(board[nx][ny] == 1 && distance[nx][ny][des] == 0 && des == 0) {
                distance[nx][ny][1] = cur_dis + 1;
                q.push({nx, ny, 1});
            }


        }


    }

    if(result == 1e9) {
        std::cout << -1 ;
    }

    else
        std::cout << result;
    return 0;

}