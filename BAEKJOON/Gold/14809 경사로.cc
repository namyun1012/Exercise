#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
/*
    좀 난해했던 구현문제, 처음에는 잘 이해가 안 됐고
    경사로를 어떻게 설정해야 할 지 고민이 었음

*/
using namespace std;
int n, l;
int result = 0;

int board[102][102];
int exist_slope[102][102];

bool OOP(int x, int y){
    if(x < 1 || y < 1 || x > n || y > n) return true;
    return false;
}

bool making_slope_row(int x, int y) {
    int cur_board = board[x][y];
    int nxt_board = board[x][y+1];

    // 증가함
    if(cur_board < nxt_board) {
        for(int temp = 0; temp < l; temp++) {
            if(OOP(x, y - temp)) return false;
            if(board[x][y- temp] != cur_board) return false;
            if(exist_slope[x][y-temp] != 0) return false; 
        }

        for(int temp = 0; temp < l; temp++) {
            exist_slope[x][y-temp] = 1;
        }
    }

    // cur > nxt
    else {
        for(int temp = 1; temp <= l; temp++) {
            if(OOP(x, y + temp)) return false;
            if(board[x][y + temp] != nxt_board) return false;
            if(exist_slope[x][y + temp] != 0) return false; 
        }

        for(int temp = 1; temp <= l; temp++) {
            exist_slope[x][y + temp] = 1;
        }
    }

    return true;
}

bool making_slope_col(int x, int y) {
    int cur_board = board[x][y];
    int nxt_board = board[x+1][y];

    if(cur_board < nxt_board) {
        for(int temp = 0; temp < l; temp++) {
            if(OOP(x - temp, y)) return false;
            if(board[x-temp][y] != cur_board) return false;
            if(exist_slope[x-temp][y] != 0) return false; 
        }

        for(int temp = 0; temp < l; temp++) {
            exist_slope[x-temp][y] = 1;
        }
    }
    // cur > nxt
    else {
        for(int temp = 1; temp <= l; temp++) {
            if(OOP(x + temp, y)) return false;
            if(board[x + temp][y] != nxt_board) return false;
            if(exist_slope[x + temp][y] != 0) return false; 
        }

        for(int temp = 1; temp <= l; temp++) {
            exist_slope[x + temp][y] = 1;
        }
    }

    return true;
}


int main() {
    //Input n은 보드의 크기, l은 경사로의 길이
    cin >> n >> l;

    for(int i = 1; i<= n; i++) {
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];
    }

    // 각 길 별로 한번씩 검토
    // 가로선
    /*
        이 쪽에서는 경사로가 있는 지 확인안하고 경사로 부터 만들어도 될 듯
        세로선에는 영향을 안줌
    */
    for(int i = 1; i <= n; i++) {
        bool check = true;
        for(int j = 1; j < n; j++) {
            if(!check) break;

            int cur_board = board[i][j];
            int nxt_board = board[i][j+1];
            // 2이상 차이가 날 때는 안 됨
            if(cur_board - nxt_board >= 2 || cur_board - nxt_board <= -2) {
                check = false;
                break;
            }

            // 같을 경우에는 continue 로 넘어감
            if(cur_board == nxt_board) continue;
            // 1, - 1 차이가 날 때
            // 경사로 만들기, 실패시 끝
            if(!making_slope_row(i, j)) {
                check = false;
                break;
            }

            // 1,-1 차이날때 성공시 넘어감
            continue;
        }

        if(check) result++;
    }
    // 가로선과 세로선은 서로 영향을 주지 않음
    fill(&exist_slope[0][0], &exist_slope[100][100], 0);
    
    // 세로선
    for(int j = 1; j <= n; j++) {
        bool check = true;
        for(int i = 1; i < n; i++) {
            if(!check) break;

            int cur_board = board[i][j];
            int nxt_board = board[i+1][j];
            // 2이상 차이가 날 때는 안 됨
            if(cur_board - nxt_board >= 2 || cur_board - nxt_board <= -2) {
                check = false;
                break;
            }
            // 같을 경우에는 continue 로 넘어감
            if(cur_board == nxt_board) continue;
            // 1, - 1 차이가 날 때
            if(!making_slope_col(i, j)) {
                check = false;
                break;
            }

            continue;
        }

        if(check) result++;
    }



    cout << result;
    return 0;
}