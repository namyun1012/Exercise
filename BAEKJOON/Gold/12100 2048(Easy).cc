#include <iostream>
#include <vector>
#include <algorithm>
/*
    다행히 원트클 
*/
int n;
//board 판은 1~n 까지만 사용
int start_board[22][22];
int board[22][22];
int check_board[22][22]; // 이미 합쳐진 볼록인지 확인함 , 이동마다 초기화
// 최대 5번 까지만 진행
void bt();
void move_control(int s);
void check_result();
bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > n) return true;
    return false;
}

std::vector<int> vec;


int result = 0;
// 순서 제조기
void bt() {
    if(vec.size() == 5) {
        for(auto ele : vec) {
            move_control(ele);
        }
        check_result();
        std::copy(&start_board[0][0], &start_board[n][n] + 1, &board[0][0]); // 배열 초기화 copy 도 + 1해야 값 나옴
        return ;
    }

    for(int i = 0; i < 4; i++) {
        vec.push_back(i);
        bt();
        vec.pop_back();
    }
}



void check_result() {
    int temp = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            temp = std::max(temp, board[i][j]);
    }

    result = std::max(temp, result);
}


// i-- 생각보단 잘 굴러감
void move_up() {
    std::fill(&check_board[0][0], &check_board[21][21], 0);
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= n; j++) {
            int nxt_x = i;
            int nxt_y = j;
            int value = board[nxt_x][nxt_y];
            // 위에 아무것도 없을 때까지 올라감
            while(!OOP(nxt_x - 1, nxt_y) && board[nxt_x - 1][nxt_y] == 0) {
                board[nxt_x - 1][nxt_y] = value;
                board[nxt_x][nxt_y] = 0;
                nxt_x--;
            }

            // 위에가 맨 끝일시 
            if(OOP(nxt_x - 1, nxt_y)) continue;
            
            //위의 값과 현재 값이 같으면서 합쳐진 적이 없을 때
            if(board[nxt_x - 1][nxt_y] == value && check_board[nxt_x - 1][nxt_y] == 0) {
                board[nxt_x -1][nxt_y] = value * 2;
                board[nxt_x][nxt_y] = 0;
                check_board[nxt_x-1][nxt_y] = 1;
            }

        }
    }
}
// i++ 밑에서 부터 시작해야 한다
void move_down() {
    std::fill(&check_board[0][0], &check_board[21][21], 0);
    for(int i = n; i >= 1 ;i--) {
        for(int j = 1; j <= n; j++) {
            int nxt_x = i;
            int nxt_y = j;
            int value = board[nxt_x][nxt_y];
            // 위에 아무것도 없을 때까지 올라감
            while(!OOP(nxt_x + 1, nxt_y) && board[nxt_x + 1][nxt_y] == 0) {
                board[nxt_x + 1][nxt_y] = value;
                board[nxt_x][nxt_y] = 0;
                nxt_x++;
            }

            // 위에가 맨 끝일시 
            if(OOP(nxt_x + 1, nxt_y)) continue;
            
            //위의 값과 현재 값이 같으면서 합쳐진 적이 없을 때
            if(board[nxt_x + 1][nxt_y] == value && check_board[nxt_x + 1][nxt_y] == 0) {
                board[nxt_x + 1][nxt_y] = value * 2;
                board[nxt_x][nxt_y] = 0;
                check_board[nxt_x + 1][nxt_y] = 1;
            }

        }
    }
}
// j-- 왼쪽에 있는 것 부터 시작해야 함
void move_left() {
    std::fill(&check_board[0][0], &check_board[21][21], 0);
    for(int j = 1; j <= n ; j++) {
        for(int i = 1; i <= n; i++) {
            int nxt_x = i;
            int nxt_y = j;
            int value = board[nxt_x][nxt_y];
            // 위에 아무것도 없을 때까지 올라감
            while(!OOP(nxt_x, nxt_y - 1) && board[nxt_x][nxt_y - 1] == 0) {
                board[nxt_x][nxt_y - 1] = value;
                board[nxt_x][nxt_y] = 0;
                nxt_y--;
            }

            // 위에가 맨 끝일시 
            if(OOP(nxt_x, nxt_y - 1)) continue;
            
            //위의 값과 현재 값이 같으면서 합쳐진 적이 없을 때
            if(board[nxt_x][nxt_y - 1] == value && check_board[nxt_x][nxt_y - 1] == 0) {
                board[nxt_x][nxt_y - 1] = value * 2;
                board[nxt_x][nxt_y] = 0;
                check_board[nxt_x][nxt_y - 1] = 1;
            }

        }
    }
}
// j++ 오른쪽 부터 시작함
void move_right() {
    std::fill(&check_board[0][0], &check_board[21][21], 0);
    for(int j = n; j >= 1 ; j--) {
        for(int i = 1; i <= n; i++) {
            int nxt_x = i;
            int nxt_y = j;
            int value = board[nxt_x][nxt_y];
            // 위에 아무것도 없을 때까지 올라감
            while(!OOP(nxt_x, nxt_y + 1) && board[nxt_x][nxt_y + 1] == 0) {
                board[nxt_x][nxt_y + 1] = value;
                board[nxt_x][nxt_y] = 0;
                nxt_y++;
            }

            // 위에가 맨 끝일시 
            if(OOP(nxt_x, nxt_y + 1)) continue;
            
            //위의 값과 현재 값이 같으면서 합쳐진 적이 없을 때
            if(board[nxt_x][nxt_y + 1] == value && check_board[nxt_x][nxt_y + 1] == 0) {
                board[nxt_x][nxt_y + 1] = value * 2;
                board[nxt_x][nxt_y] = 0;
                check_board[nxt_x][nxt_y + 1] = 1;
            }

        }
    }
}

void move_control(int s) {
    if(s == 0) move_up();
    else if(s == 1) move_down();
    else if(s == 2) move_left();
    else if(s == 3) move_right();
}

int main() {
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            std::cin >> start_board[i][j];
    }
    std::copy(&start_board[0][0], &start_board[n][n] + 1, &board[0][0]);
    // Testing Code
    /*
    for(int i = 1; i <= 5; i++) {
        move_right();
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                std::cout << board[i][j] << " ";

            std::cout << "\n";
        }
    } 
    */



    bt();
    
    std::cout << result;

    return 0;

}