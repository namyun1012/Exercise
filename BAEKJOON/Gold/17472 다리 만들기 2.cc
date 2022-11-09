#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

/*
    원트 
    섬의 개수는 6개를 안 넘음
*/

/*
    BFS로 섬을 구분 그 후
    섬 끼리의 거리를 정함
    그 후 연결하는 가장 작은 거리를 MST로 구함

*/

int board[12][12];
int visited[12][12];
int isl_viisted[12]; // MST 사용
std::vector<std::pair<int, int>> islands[10];
// 섬의 개수를 모아 놓는 곳
int distances[10][10];
std::vector<std::pair<int, int>> adj[10];
// 거리를 모아 두는 곳
// 거리, End

int n, m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x >n || y > m)
        return true;
    
    return false;
}

int main() {
    
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> board[i][j];
        }
    }

    int isl = 2; // 섬을 구별해줄 index  2 ~ 7 까지 존재함
    //BFS Start 섬들을 전부 구별함
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ; j++) {
            if(visited[i][j] || board[i][j] != 1) continue;
            std::queue<std::pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = 1;
            board[i][j] = isl;
            islands[isl].push_back({i,j});


            while(!q.empty()) {
                auto cur = q.front();
                q.pop();

                for(int dir = 0; dir < 4; dir++) {
                    int nxt_x = cur.first + dx[dir];
                    int nxt_y = cur.second + dy[dir];
                    if(OOP(nxt_x, nxt_y)) continue;
                    if(board[nxt_x][nxt_y] != 1 || visited[nxt_x][nxt_y]) continue;
                    q.push({nxt_x, nxt_y});
                    visited[nxt_x][nxt_y] = 1;
                    board[nxt_x][nxt_y] = isl;
                    islands[isl].push_back({nxt_x, nxt_y});

                }
            }

            isl++;
        }
    }
    
    /*
        현재 섬에는 2~ isl-1까지의 index 를 가진 섬들이 존재함
        섬 끼리 거리 구하는 것부터 구현 필요
    
    */

    std::fill(&distances[0][0], &distances[9][9], 1e9);

    for(int i = 2; i < isl; i++) { 
        distances[i][i] = 0;
        for(auto cur : islands[i]) { // 섬의 대륙 마다 하나 씩 해보기 상하좌우 4방향 해서 다른 섬 나오자 마자 최솟값
            
            
            for(int dir = 0; dir < 4; dir++) {
                int nxt_x = cur.first;
                int nxt_y = cur.second;
                int temp = 0;
                
                while(true) {
                    nxt_x += dx[dir];
                    nxt_y += dy[dir];
                    
                    if(OOP(nxt_x, nxt_y)) break;
                    
                    if(board[nxt_x][nxt_y] == i) break;

                    if(board[nxt_x][nxt_y] != 0 && board[nxt_x][nxt_y] != i) {
                        if(temp < 2) break;
                        distances[i][board[nxt_x][nxt_y]] = std::min(temp, distances[i][board[nxt_x][nxt_y]]);
                        distances[board[nxt_x][nxt_y]][i] = distances[i][board[nxt_x][nxt_y]];
                        break;
                    }



                    temp++;
                }
            
            }
        }
    }

    /*
        거리 구하기 완료 MST 시작
    */
    for(int i = 2; i < isl; i++) {
        for(int j = 2; j <isl ; j++) {
            adj[i].push_back({distances[i][j], j});
        }
    }


    int result = 0;
    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>,
                        std::greater<std::tuple<int, int, int>> > pq;
    
    
    isl_viisted[2] = 1;
    for(auto nxt : adj[2]) {
        pq.push({nxt.first, 2, nxt.second});
    }

    while(!pq.empty()) {
        int weight, start, end;
        std::tie(weight, start, end) = pq.top();
        pq.pop();
        if(weight == 1e9) continue;
        if(isl_viisted[end]) continue;
        result += weight;
        isl_viisted[end] = 1;

        for(auto nxt : adj[end]) {
            if(isl_viisted[nxt.second]) continue;
            pq.push({nxt.first, end, nxt.second});
        }


    }
    for(int i = 2; i < isl; i++) {
        if(isl_viisted[i] == 0) {
            result = -1;
            break;
        }
    }
    
    std::cout << result;

    return 0;
}