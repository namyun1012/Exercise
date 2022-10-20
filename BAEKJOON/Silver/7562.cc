#include <iostream>
#include <queue>

int board[302][302];
int visited[302][302];
int dis[302][302];
int dx[8] = {2,2,1,1,-2,-2,-1,-1};
int dy[8] = {1,-1,2,-2,1,-1,2,-2};


int main() {
    int T;
    std::cin >> T;
    while(T--) {
        std::fill(&visited[0][0], &visited[301][301], 0);
        std::fill(&dis[0][0], &dis[301][301], 0);

        int l;
        std::cin >> l;
        
        int st_x, st_y;
        std::cin >> st_x >> st_y;
        int end_x, end_y;
        std::cin >> end_x >> end_y;

        std::queue<std::pair<int, int>> q;
        q.push({st_x, st_y});
        visited[st_x][st_y] = 1;
        dis[st_x][st_y] = 0;

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            if(cur.first == end_x && cur.second == end_y) {
                break;
            }


            for(int dir = 0; dir < 8; dir++) {
                std::pair<int, int> nxt = {cur.first + dx[dir], cur.second + dy[dir]};
                if(nxt.first < 0 || nxt.first >= l || nxt.second < 0 || nxt.second >= l) continue;
                if(visited[nxt.first][nxt.second]) continue;
                visited[nxt.first][nxt.second] = 1;
                q.push({nxt.first, nxt.second});
                dis[nxt.first][nxt.second] = dis[cur.first][cur.second] + 1;
            
            }
        }
        
        std::cout << dis[end_x][end_y] << "\n";
    }

    return 0;
}