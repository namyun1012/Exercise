#include <iostream>
#include <vector>
#include <queue>

//use backtracking
int board[20][20];
// 1,1 ~~ N,N

int N;
int count = 0;
//mode 0 , 1, 2
void bt(int i, int j, int mode) {
    if(i == N && j == N) {
        
        count++;
        return ;
    }

    if(mode == 0) { // 가로
        if(j < N && !board[i][j+1]) {
            bt(i, j+1, 0);
        }

        if(j < N && i < N && !board[i][j+1] && !board[i+1][j] && !board[i+1][j+1]) {
            bt(i+1, j+1, 2);
        }
    }

    else if(mode == 1) { // 세로
        if(i < N && !board[i+1][j]) {
            bt(i+1, j, 1);
        }

        if(j < N && i < N && !board[i][j+1] && !board[i+1][j] && !board[i+1][j+1]) {
            bt(i+1, j+1, 2);
        }
    }

    else if(mode == 2) { // 대각선
        if(j < N && !board[i][j+1]) {
            bt(i, j+1, 0);
        }

        if(i < N && !board[i+1][j]) {
            bt(i+1, j, 1);
        }

        if(j < N && i < N && !board[i][j+1] && !board[i+1][j] && !board[i+1][j+1]) {
            bt(i+1, j+1, 2);
        }

    }

    else {
        std::cout << "Error Occur";
        return;
    }

}

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    
    
    std::cin >> N;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            std::cin >> board[i][j];
    }

    bt(1, 2, 0);

    std::cout << count;
    return 0;
}