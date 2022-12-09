#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

/*
    배열 회전 필요
    뻘짓이 난무했다
    result는 최대 칸의 개수임 (board 합 아님)
    


*/


int n, q;
int length = 0;

int board[70][70];
int tempBoard[70][70];
int visited[70][70];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > length || y > length) return true;
    return false;

}
void rotate(int L) {
    int part = 1 << L;

    for(int i = 1; i <= length; i += part) {
        for(int j = 1; j <= length; j+= part) {
            //90도 회전한 값을 우선 tempBoard 에 저장
            int start_r = i;
            int end_r = i + part - 1;
            int start_c = j;
            int end_c = j + part - 1;
            /*
                배열을 90도 시계 방향으로 회전할 때
                기존 1열에 있던 것을 1행으로 놓는데 거꾸로 놓음
                2행은 2열 거꾸로

                격자 별 서로를 침범하지 않기 위해
                r, c는 0 ~ part - 1

            
            
            */
            for(int r = 0; r < part; r++) {
                for(int c = 0; c < part; c++) {
                    tempBoard[r + start_r][c + start_c] = board[end_r -c][r + start_c];
                }
            }
        }
    }

    for(int i = 1; i <= length; i++) {
        for(int j = 1; j <= length; j++) {
            board[i][j] = tempBoard[i][j];
        }
    }


}

void melting_ice() {
    for(int i = 1; i <= length; i++) {
        for(int j = 1; j <= length; j++) {
            if(board[i][j] == 0) continue;
            
            int can_dir = 0;
            for(int dir = 0; dir < 4; dir++) {
                int nxt_x = i + dx[dir];
                int nxt_y = j + dy[dir];

                if(OOP(nxt_x, nxt_y)) continue;
                if(board[nxt_x][nxt_y] == 0) continue;
                can_dir++;
            }

            if(can_dir >= 3) tempBoard[i][j] = board[i][j];
            else tempBoard[i][j] = board[i][j] - 1;
        }

    }

    for(int i = 1; i <= length; i++) {
        for(int j = 1; j <= length; j++) {
            board[i][j] = tempBoard[i][j];
        }
    }


}

int main() {
    std::cin >> n >> q;
    length = 1<<n;

    for(int i = 1; i <= length; i++) {
        for(int j = 1; j <= length; j++) {
            std::cin >> board[i][j];
        }
    }


    while(q--) {
        int L;
        std::cin >> L;
        rotate(L);
        melting_ice();
        // Testing Code
        /*
        for(int i = 1; i <= length; i++) {
            for(int j = 1; j <= length; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
        */
    }

    //result
    int sum = 0;
    for(int i = 1; i <= length; i++) {
        for(int j = 1; j <= length; j++) {
            sum += board[i][j];
        }
    }

    int result = 0;
    //BFS로 얼음 덩어리 구하기
    
    for(int i = 1; i <= length; i++) {
        for(int j = 1; j <= length; j++) {
            if(visited[i][j] || board[i][j] == 0) continue;
            std::queue<std::pair<int, int>> q;

            q.push({i, j});
            visited[i][j] = 1;
            int temp_result = 1;

            while(!q.empty()) {
                auto cur = q.front();
                q.pop();

                for(int dir = 0; dir < 4; dir++) {
                    int nxt_x = cur.first + dx[dir];
                    int nxt_y = cur.second + dy[dir];
                    if(OOP(nxt_x, nxt_y)) continue;
                    if(visited[nxt_x][nxt_y] || board[nxt_x][nxt_y] == 0) continue;

                    q.push({nxt_x, nxt_y});
                    visited[nxt_x][nxt_y] = 1;
                    temp_result += 1;

                }

            }

            result = std::max(temp_result, result);
        }
    }


    std::cout << sum << "\n" << result;
    return 0;

}