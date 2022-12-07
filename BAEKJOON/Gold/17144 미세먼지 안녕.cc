#include <iostream>
#include <vector>
#include <algorithm>
/*
    구현에서 살짝 실수가 있었음

*/
int board[55][55];
int temp_board[55][55];
int r, c;
int t;

std::pair<int, int> top_air = {0,0};
std::pair<int, int> down_air= {0,0};

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
// 동북서남으로


bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > r || y > c) return true;
    return false;
}

int main() {
    std::cin >> r >> c >> t;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            std::cin >> board[i][j];
            // 공기청정기 저장
            if(board[i][j] == -1 && top_air.first == 0) {
                top_air = {i, j};
                down_air = {i+1, j};
            }
        }
    }

    //1. 미세먼지들이 확산함
    //모든 칸에 동시에 일어나야 하니까
    //temp_board에서 추가할 것을 저장해 놓고 일일이 다 저장하기
    int time = 0;

    while(time < t) {
        std::fill(&temp_board[0][0], &temp_board[54][54], 0);

        for(int i = 1; i <= r ; i++) {
            for(int j = 1; j <= c; j++) {
            
                if(board[i][j] == -1) continue;
                int can_dirs = 0;
            
                // 가능한 방향들을 구함
                for(int dir = 0 ; dir < 4 ; dir++) {
                    int nxt_x = i + dx[dir];
                    int nxt_y = j + dy[dir];

                    if(OOP(nxt_x, nxt_y)) continue;
                    if(board[nxt_x][nxt_y] == -1) continue;
                    can_dirs++;
                
                }

                int diffusion = board[i][j] / 5;

                for(int dir = 0 ; dir < 4 ; dir++) {
                    int nxt_x = i + dx[dir];
                    int nxt_y = j + dy[dir];

                    if(OOP(nxt_x, nxt_y)) continue;
                    if(board[nxt_x][nxt_y] == -1) continue;
                    temp_board[nxt_x][nxt_y] += diffusion;
                }

                board[i][j] = board[i][j] - (diffusion * can_dirs);

            }
        }

        // 한 번 씩 다 돈 다음 값을 Board에 더해줌
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                board[i][j] += temp_board[i][j];
            }
        }
        // 2. 공기 청정기가 작동함
        // 따로 바람 구현 말고 그냥 결과만 적용하기
        // 바람의 역순으로 진행하자
        // 1. 윗쪽 공기 청정기

        board[top_air.first-1][1] = 0;
        for(int i = top_air.first - 2; i >= 1; i--) {
            board[i+1][1] = board[i][1];
            board[i][1] = 0;
        }

        for(int j = 2; j <= c; j++) {
            board[1][j-1] = board[1][j];
            board[1][j] = 0;
        }

        for(int i = 2; i <= top_air.first; i++) {
            board[i-1][c] = board[i][c];
            board[i][c] = 0;
        }

        for(int j = c - 1; j > 1; j--) {
            board[top_air.first][j+1] = board[top_air.first][j];
            board[top_air.first][j] = 0;
        }

        //2. 아래쪽 공기 청정기

        board[down_air.first + 1][1] = 0;
        for(int i = down_air.first + 2; i <= r; i++) {
            board[i-1][1] = board[i][1];
            board[i][1] = 0;
        }

        for(int j = 2; j <= c; j++) {
            board[r][j-1] = board[r][j];
            board[r][j] = 0;
        }

        for(int i = r - 1; i >= down_air.first; i--) {
            board[i+1][c] = board[i][c];
            board[i][c] = 0;
        }

        for(int j = c - 1; j > 1; j--) {
            board[down_air.first][j+1] = board[down_air.first][j];
            board[down_air.first][j] = 0;
        }

        time++;
    }

    int result = 0;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(board[i][j] == -1) continue;
            result += board[i][j];
        }
    }



    std::cout << result;
    return 0;

}