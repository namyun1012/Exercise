
/*
    처음에는 문제 이해를 잘 못해 방향을 잘못 잡았다가
    BFS 여러 본 돌리는 것으로 해결됨
    다시 풀어 보니까 그냥 해결되긴 함
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

int n;
int board[23][23];
int visited[23][23];
int distance[23][23];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

std::pair<int, int> shake;

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > n)
        return true;
    return false;

}

int main() {
    std::cin >> n;
    


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            std::cin >> board[i][j];
            if(board[i][j] == 9) {
                shake.first = i;
                shake.second = j;
            }
        }
    }

    int size = 2;
    int eaten = 0;
    int time = 0;
    // 우선 BFS로 먹을 수 있는 물고기들을 검사함
    while(true) {
        std::fill(&visited[0][0], &visited[22][22], 0);
        std::fill(&distance[0][0], &distance[22][22], 0);

        int temp_x = shake.first;
        int temp_y = shake.second;

        std::queue<std::pair<int, int>> q;
        q.push({temp_x, temp_y});
        visited[temp_x][temp_y] = 0;
        distance[temp_x][temp_y] = 0;

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            for(int dir = 0; dir < 4; dir++) {
                int nxt_x = dx[dir] + cur.first;
                int nxt_y = dy[dir] + cur.second;
                if(OOP(nxt_x, nxt_y)) continue;
                if(board[nxt_x][nxt_y] > size || visited[nxt_x][nxt_y]) continue;
                q.push({nxt_x, nxt_y});
                visited[nxt_x][nxt_y] = 1;
                distance[nxt_x][nxt_y] = distance[cur.first][cur.second] + 1;
            }
        }
    /*
        distance 랑 visit를 이용해서 먹을 물고기를 정함
    */
        
        std::pair<int, int> fish = {0,0};
        int temp_dis = 1e9;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(board[i][j] == 0 || board[i][j] == 9) continue; // 물고기가 아님
                if(visited[i][j] == 0) continue; // 방문을 하지 못함
                if(board[i][j] == size) continue; // 같은 크기의 물고기는 못 먹음
                // 기존 거리보다 이 물고기까지의 거리가 더 적을 때
                if(temp_dis > distance[i][j]) {
                    temp_dis = distance[i][j];
                    fish = {i,j};
                }

            }
        }

        // 먹을 물고기가 없는 경우에는 종료
        if(fish.first == 0 && fish.second == 0)
            break;
    
        //물고기를 먹음
        eaten++;
        if(size == eaten) {
            size++;
            eaten = 0;
        }
        
        board[shake.first][shake.second] = 0;
        board[fish.first][fish.second] = 9;
        time += distance[fish.first][fish.second];
        shake.first = fish.first;
        shake.second = fish.second;
        //Testing Code
    }

    std::cout << time;
    return 0;
}