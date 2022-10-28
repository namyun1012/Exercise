#include <iostream>
#include <algorithm>
#include <string>


int gears[4][8]; // i 번째 기어에 j번째 상태 N 0   S 1
int rotations[102][2]; // 1 시계 방향, -1 시계 반대 방향
int temp[8];
bool check[4]; // 회전을 이미 했는 지 안 했는 지 체크함, 회전 1번 진행마다 초기화
//회전 전에 극을 기준으로  옆에가 회전할 지 안할 지 정함
/*
    0 일 때 1 닿는 index 2
    1일 때 0, 2 닿는 index 6 2
    2일 때 1, 3
    3 일 때 2 
*/

void rotate_clock(int cur, int dir);

void rotate(int cur, int dir) {
    

    bool check_prev = false;
    bool check_next = false;

    
    int prev = cur - 1;
    int next = cur + 1;
    if(prev >= 0 && gears[cur][6] != gears[prev][2] && check[prev] == 0) 
        check_prev = true;
    if(next < 4 && gears[cur][2] != gears[next][6] && check[next] == 0) 
        check_next = true;

    rotate_clock(cur, dir);
    check[cur] = true;

    if(check_prev) {
        rotate(prev, -dir);
    }

    if(check_next) {
        rotate(next, -dir);
    }
    
}

void rotate_clock(int cur, int dir) { // 단순 회전만
    if(dir == 1) { // 시계 방향
        temp[0] = gears[cur][7];
        for(int i  = 1; i <= 7; i++) {
            temp[i] = gears[cur][i-1];
        }

        for(int i = 0; i < 8; i++) {
            gears[cur][i] = temp[i];
        }
    }

    else if(dir == -1) {
        temp[7] = gears[cur][0];
        for(int i = 6; i >= 0 ;i--) {
            temp[i] = gears[cur][i+1];
        }

        for(int i = 0; i < 8; i++) {
            gears[cur][i] = temp[i];
        }
    }

}

int GetScore() {
    int result = 0;
    for(int i = 0; i < 4; i++) {
        if(gears[i][0] == 1)
            result += (1<<i);
    }

    return result;
}


int main() {
    for(int i = 0; i < 4; i++) {
        std::string temp;
        std::cin >> temp;
        for(int j = 0; j <8; j++) {
            gears[i][j] = temp[j] - '0';
        }
    }

    int k;
    std::cin >> k;

    for(int i = 0; i < k; i++) {
        std::cin >> rotations[i][0] >> rotations[i][1];
    }

    for(int i = 0; i < k; i++) {
        std::fill(check, check + 4, false);
        rotate(rotations[i][0] - 1, rotations[i][1]); // 사용 배열은 0~3 실제 입력은 1~4이므로 보정 필요

    }

    std::cout << GetScore();
    return 0;
}