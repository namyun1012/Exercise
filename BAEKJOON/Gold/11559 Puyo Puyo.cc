#include <iostream>
#include <string>
#include <queue>
#include <vector>
// 왠 일로 하자마자 클
char board[12][6]; // 세로 12 가로 6
int visited[12][6];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int result = 0;

bool bfs(int x, int y);

bool BoundCheck(int x, int y) { // 범위 넘으면 true , 아닐 시 false
    if(x < 0 || y < 0 || x > 11 || y > 5)
        return true;
    
    return false;
}

/*
    우선 기존 배열을 . 인 것과 아닌 것으로 받고
    배열을 새롭게 . 으로 먼저 채우고, 그 이후부터 아닌 것으로 채우면 내리는 것 가능

*/

void tounder() {

    
    for(int j = 0; j < 6; j++) {
        std::string temp_void ="";
        std::string temp_puyo = "";

        for(int i = 0; i < 12; i++) {
            if(board[i][j] == '.') {
                temp_void += '.';
            }

            else {
                temp_puyo += board[i][j];
            }
        }

        int index = 0;
        for(auto ch : temp_void) {
            board[index][j] = ch;
            index++;
        }

        for(auto ch : temp_puyo) {
            board[index][j] = ch;
            index++;
        }

    }
}

/*
    동시에 터져야 한다. 그러므로 내리는 것은 bfs로 다 터트린 이후에 진행함
    연쇄는 1번만 추가
*/

bool Puyocheck() { // 4개 이상이면 다 터지니 bfs로 검사하자.
    bool check = false; // 터진 것이 있는 지 확인
    std::fill(&visited[0][0], &visited[11][5] + 1, 0);

    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 6; j++) {
            if(board[i][j] == '.' || visited[i][j]) continue;
            
            if(bfs(i, j))
                check = true;
        }
    }


    if(check) {
        result++;
        return true;    
    }

    else {
        return false;
    }
}

bool bfs(int x, int y) {
    
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> result_vec; // size가 4이상일 시 .으로 변경
    char cur_val = board[x][y];

    q.push({x,y});
    result_vec.push_back({x,y});
    visited[x][y] = 1;

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nxt_x = cur.first + dx[dir];
            int nxt_y = cur.second + dy[dir];
            
            if(BoundCheck(nxt_x, nxt_y)) continue;
            if(visited[nxt_x][nxt_y] || cur_val != board[nxt_x][nxt_y]) continue;
            
            q.push({nxt_x, nxt_y});
            visited[nxt_x][nxt_y] = 1;
            result_vec.push_back({nxt_x, nxt_y});
        }
    }

    // BFS end

    if(result_vec.size() >= 4) {
        for(auto ele : result_vec) {
            board[ele.first][ele.second] = '.';
        }
        return true;
    }

    else {
        return false;
    }
}


int main() {
    for(int i = 0; i < 12; i++) {
        std::string temp;
        std::cin >> temp;
        for(int j = 0; j < 6; j++) {
            board[i][j] = temp[j];
        }
    }

    while(true) {
        bool check = false;
        check = Puyocheck();
        
        if(check) { // 터졌을 시 남은 것들을 밑으로 내림
            tounder();
        }

        else {
            break;
        }
    }
    
    std::cout << result << "\n";
    /*
    테스트 용 코드
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 6; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
    */
    return 0;
}