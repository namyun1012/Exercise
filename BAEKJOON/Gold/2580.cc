#include <iostream>
#include <vector>

// 0이 많은 것을 못 받아서 나중에 다시 조정하기
int board[9][9];
int visited[9][9];
std::vector<std::pair<int, int>> vec_zero; // 0 의 좌표를 모아놓음

bool answer_trued = false; // 정답 찾았을 때 더 이상의 보드 변경 중단
/*
    bt를 진행할 때 다른 것과 다르게 for 문으로 찾을 필요가 없었음


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

void bt(int n) {
    
    if(n == vec_zero.size()) {
        answer_trued = true; 
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
   
        exit(0);
    }

    if(answer_trued) {
        return ;
    }

    
    int index = n;
    int i = vec_zero[index].first; int j = vec_zero[index].second;
    if(board[i][j] != 0) return ; // 실질적으로 작동하지 않음
    
    for(int k = 1; k <= 9; k++) {
            
        if(!check(i,j,k)) continue;
        board[i][j] = k;      
        bt(n + 1);
        board[i][j] = 0;   // 최적해를 못 찾았을 때 다시 초기화 해줌 for 문 없어도 작동함
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


    return 0;
}