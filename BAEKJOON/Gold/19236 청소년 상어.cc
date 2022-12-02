#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
/*
    물고기 이동 함수만 우선 구현
    이후에 백트래킹을 어떻게 할지는 더 고민해봐야 할 듯
    bt 과정에서 자력 수행을 못한 듯
    문제를 어떻게 풀어야 할 지 더 보고 풀어야 겠음
    물고기 이동 코드 등은 그냥 구현되나 BT를 어떻게 해야할 지 감을 못 잡았었음
    배열을 저장해 놓고 상태를 다시 돌리는 과정에 대한 습득 필요
    
*/
// 물고기의 번호 저장 상어는 -1로 진행
int board[5][5];

// X, Y, dir
std::tuple<int, int, int> fishes[17];



std::tuple<int, int, int> shake;
int dx[9] = {0,-1,-1,0,1,1,1,0,-1};
int dy[9] = {0,0,-1,-1,-1,0,1,1,1};

// 물고기 번호의 합의 최댓값
int result = 0;
bool OOP(int x, int y) {
    if(x < 0 || y < 0 || x >= 4 || y >= 4) return true;
    return false;
}

int changeDir(int dir) {
    if(dir == 8) return 1;
    return dir + 1;
}
int time = 0;
void fish_move() {
    /* Test Code
    time++;
    if(time > 10) std::exit(0);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout <<  board[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
    */

    for(int i = 1; i <= 16; i++) {
            
            int fish_x, fish_y, fish_dir;
            std::tie(fish_x, fish_y, fish_dir) = fishes[i];
           
            // 먹힌 애는 이동안함
            if(fish_x == -1) continue;
            
            // 8번 도니까 만약 이동할 수 있는 칸이 없는 경우에는 방향 원상 복귀됨
            for(int temp = 0; temp < 8; temp++) {
                int nxt_x = fish_x + dx[fish_dir];
                int nxt_y = fish_y + dy[fish_dir];
                
                // 없을 때에는 방향 바꿈
                if(OOP(nxt_x, nxt_y)) {
                    fish_dir = changeDir(fish_dir);
                    continue;
                }

                if(board[nxt_x][nxt_y] == -1) {
                    fish_dir = changeDir(fish_dir);
                    continue;
                }

                // 비었을 때는 그대로 이동
                if(board[nxt_x][nxt_y] == 0) {
                    board[nxt_x][nxt_y] = i;                
                    board[fish_x][fish_y] = 0;
                    fishes[i] = {nxt_x, nxt_y, fish_dir};
                    std::tie(fish_x, fish_y, fish_dir) = fishes[i];
                    break;
                }

                // 다른 물고기가 있을 경우
                else {
                    int change_fish = board[nxt_x][nxt_y];
                    int change_fish_x, change_fish_y, change_fish_dir;
                    std::tie(change_fish_x, change_fish_y, change_fish_dir) = fishes[change_fish];
                    change_fish_x = fish_x;
                    change_fish_y = fish_y;
                    
                    fishes[change_fish] = {change_fish_x, change_fish_y, change_fish_dir};
                    board[change_fish_x][change_fish_y] = change_fish;
                    fishes[i] = {nxt_x, nxt_y, fish_dir};
                    board[nxt_x][nxt_y] = i;
                    break;
                }

            }
     }
}





void bt(int shark_x, int shark_y, int shark_dir, int sum) {
    result = std::max(result, sum);
    
    int current_board[5][5];
    std::tuple<int, int, int> current_fishes[17];
    // 저장해 두었다가 끝날 때 다시 변경

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            current_board[i][j] = board[i][j];
        }
    }

    for(int i = 0; i < 17; i++) {
        current_fishes[i] = fishes[i];
    }
   
    // 물고기 먼저 이동
    fish_move();


    // 그 후 상어이동
    for(int i = 1; i <= 3; i++) {
        int nxt_x = shark_x + (dx[shark_dir] * i);
        int nxt_y = shark_y + (dy[shark_dir] * i);
        
        if(OOP(nxt_x, nxt_y)) break;
        if(board[nxt_x][nxt_y] == 0) continue;

        int eaten_fish = board[nxt_x][nxt_y];
        int fish_x, fish_y, fish_dir;
        std::tie(fish_x, fish_y, fish_dir) = fishes[eaten_fish];

        // 상어가 이동했을 때 변동 사항
        board[shark_x][shark_y] = 0;
        board[fish_x][fish_y] = -1;
        fishes[eaten_fish] = {-1, -1, -1};

        bt(nxt_x, nxt_y, fish_dir, sum + eaten_fish);

        // 위에서 종료 되었을 때 for 문 돌릴 거 있으므로 위에 거를 다시 복구해줌
        board[shark_x][shark_y] = -1;
        board[fish_x][fish_y] = eaten_fish;
        fishes[eaten_fish] = {fish_x, fish_y, fish_dir};

    }

    // 보드들을 위에 과정 수행하기 전으로 원상복구 시켜놈
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            board[i][j] = current_board[i][j];
        }
    }

    for(int i = 0; i < 17; i++) {
        fishes[i] = current_fishes[i];
    }

}




int main() {
    for(int i = 1; i <= 16; i++) {
        fishes[i] = {-1, -1, -1};
    }

    // 물고기의 방향들 입력 받기
    //(0,0) ~ (3,3) 까지
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int num, dir;
            std::cin >> num >> dir;
            fishes[num] = {i, j, dir};
            board[i][j] = num;
        }
    }

    // 상어가 0,0 에 있는 물고기를 먹음
    int shark_x, shark_y, shark_dir;
    int eaten_fish = board[0][0];
    std::tie(shark_x, shark_y, shark_dir) = fishes[eaten_fish];
    board[0][0] = -1; // 상어의 위치는 -1로 표현
    fishes[eaten_fish] = {-1,-1,-1}; // 먹힌 물고기 더 이상 작동 X
    result += eaten_fish;

    bt(shark_x, shark_y, shark_dir, result);
    
    std::cout << result;

}