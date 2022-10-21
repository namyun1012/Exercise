#include <iostream>
#include <vector>

// 0이 많은 것을 못 받아서 나중에 다시 조정하기
int board[9][9];
int visited[9][9];
std::vector<std::pair<int, int>> vec_zero; // 0 의 좌표를 모아놓음

bool answer_trued = false; // 정답 찾았을 때 더 이상의 보드 변경 중단
/*
    123
    456
    789

*/
bool check(int x, int y, int temp) {
    // 1 row_check

    for(int j = 0; j < 9; j++) {
        if(board[x][j] == temp) {
            return false;
        }
    }

    for(int j = 0; j < 9; j++) {
        if(board[j][y] == temp) {
            return false;
        }
    }

    for(int i = (x/3)*3 ; i < (x/3)*3 + 3; i++) {
        for(int j = (y/3)*3 ; j < (y/3)*3 + 3; j++){
            if(board[i][j] == temp)
                return false;
        }
    }


    return true;
}

bool check_answer() {
    for(auto pair : vec_zero) {
        if(board[pair.first][pair.second] == 0)
            return false;
    }

    return true;
}

void bt(int count) {
    
    if(count == vec_zero.size()) {
        answer_trued = true;     
        return ;
    }

    if(answer_trued) {
        return ;
    }

    
    for(auto pair : vec_zero) {
        int i = pair.first; int j = pair.second;
        if(visited[i][j] == 1) continue;
        for(int k = 1; k <= 9; k++) {
            
            if(!check(i,j,k)) continue;
            board[i][j] = k;      
            bt(count + 1);
             
        }
    }
}


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cin >> board[i][j];
            if(board[i][j] == 0)
                vec_zero.push_back({i,j});
        }
    }
    
    bt(0);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }


    return 0;
}