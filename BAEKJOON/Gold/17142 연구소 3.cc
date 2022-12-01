#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
/*
    BT를 진행할 때 조합으로
    그 외에도 사소한 것들이 약간 많은 문제 였음
*/
int n, m;
int board[52][52];
int distance[52][52];
int visited[52][52];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int result = INF;
std::vector<std::pair<int, int>> viruses;

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > n) return true;
    return false;
}

bool check() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {


            if(board[i][j] != 1 && visited[i][j] == 0)
                return false;

        }
    }

    return true;
}

int visted_virus[12];
std::vector<std::pair<int, int>> selected_vector;

void bfs() {
    std::fill(&visited[0][0], &visited[51][51] + 1 , 0);
    std::fill(&distance[0][0], &distance[51][51] + 1 , 0);
    std::queue<std::pair<int, int>> q;

    for(auto virus : selected_vector) {
        q.push(virus);
        visited[virus.first][virus.second] = 1;
        distance[virus.first][virus.second] = 0;
    }
    int temp = 0;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(board[cur.first][cur.second] == 0) // 바이러스 원래 없는 칸 일 때만 증가
            temp = std::max(temp, distance[cur.first][cur.second]);


        for(int dir = 0; dir < 4; dir++) {
            int nxt_x = cur.first + dx[dir];
            int nxt_y = cur.second + dy[dir];

            if(OOP(nxt_x, nxt_y)) continue;
            if(board[nxt_x][nxt_y] == 1 || visited[nxt_x][nxt_y]) continue;

            q.push({nxt_x, nxt_y});
            visited[nxt_x][nxt_y] = 1;
            distance[nxt_x][nxt_y] = distance[cur.first][cur.second] + 1;
            
        }
    }

    if(check()) {
        result = std::min(temp, result);
        return ;
    }

    return ;
    

}


void bt(int index) {
    if(selected_vector.size() == m) {
        bfs();
        return ;
    }

    for(int i = index; i < viruses.size(); i++) {
        if(visted_virus[i]) continue;
        visted_virus[i] = 1;
        selected_vector.push_back({viruses[i].first, viruses[i].second});
        bt(i + 1);
        visted_virus[i] = 0;
        selected_vector.pop_back();
    }
}





int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    std::cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            std::cin >> board[i][j];
            if(board[i][j] == 2) {
                viruses.push_back({i,j});
            }
        }
    }

    bt(0);

    if(result == INF) result = -1;
    std::cout << result;
    return 0;

}