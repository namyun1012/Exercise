#include <iostream>
#include <string>
#include <queue>
char board[1002][1002];
int dis[1002][1002];
int visited[1002][1002];
int fired[1002][1002];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
//fire 처리 필요
int main() {
    int T;
    std::cin >> T;
    while(T--) {
        std::fill(&board[0][0], &board[1001][1001], NULL);
        std::fill(&dis[0][0], &dis[1001][1001], 0);
        std::fill(&visited[0][0], &visited[1001][1001], 0);
        std::fill(&fired[0][0], &fired[1001][1001], 0);

        std::queue<std::pair<int, int>> q_me;
        std::queue<int> q; // q_me가 me인지 fire인지 확인 me >> 0 fire >> 1

        int w,h;
        std::cin >> w >> h;
        std::string temp;
        std::pair<int, int> temp_me;
        bool isExist = false;

        for(int i = 0 ; i < h; i++) {
            std::cin >> temp;
            for(int j = 0; j < w; j++) {
                board[i][j] = temp[j];
                if(temp[j] == '@') { // Me
                    temp_me = {i,j};
                    visited[i][j] = 1;
                    dis[i][j] = 1;
                }

                if(temp[j] == '*') { // Fire
                    q_me.push({i,j});
                    q.push(1); //
                    visited[i][j] = 1;
                    fired[i][j] = 1;
                }
            }
        }
        //fire 처리를 먼저하고 그 뒤에 me 처리를 하자
        int result = 1e9;
        
        bool check = false; // 빠져나갔을 시
        
        q_me.push(temp_me);
        q.push(0);
        
        while(!q_me.empty()) {
            std::pair<int, int> cur = q_me.front();
            int cur_value = q.front();
            q_me.pop();
            q.pop();

            if(cur_value == 0) {// me 일때
                if(cur.first == h-1 || cur.first == 0 || cur.second == w-1 || cur.second == 0) {
                    result = std::min(result, dis[cur.first][cur.second]);
                    check = true;
                    break;
                }



                for(int dir = 0; dir < 4; dir++) {
                    std::pair<int, int> nxt = {cur.first+ dx[dir], cur.second + dy[dir]};
                    if(nxt.first < 0 || nxt.second < 0 || nxt.first >= h || nxt.second >= w) continue;
                    if(board[nxt.first][nxt.second] == '#' || board[nxt.first][nxt.second] == '*' || visited[nxt.first][nxt.second]) continue;
                    visited[nxt.first][nxt.second] = 1;
                    q_me.push({nxt.first, nxt.second});
                    dis[nxt.first][nxt.second] = dis[cur.first][cur.second] + 1;
                    q.push(0);
                }
            }

            else if(cur_value == 1) {
                for(int dir = 0; dir < 4; dir++) {
                    std::pair<int, int> nxt = {cur.first+ dx[dir], cur.second + dy[dir]};
                    if(nxt.first < 0 || nxt.second < 0 || nxt.first >= h || nxt.second >= w) continue;
                    if(board[nxt.first][nxt.second] == '#' || board[nxt.first][nxt.second] == '*' || fired[nxt.first][nxt.second]) continue;
                    visited[nxt.first][nxt.second] = 1;
                    q_me.push({nxt.first, nxt.second});
                    board[nxt.first][nxt.second] = '*';
                    q.push(1);
                }
            }

        }





        if(check) {
            std::cout << result << "\n";
        }
            
        else {
            std::cout << "IMPOSSIBLE" << "\n";
        }

        
    }

    return 0;
}