#include <iostream>

int board[130][130];
int white = 0;
int blue = 0;
bool isCheck(int N, int row, int col);

void paper(int N, int row, int col) { // (길이, 시작 행, 시작 열)
    if(N == 1) {
        if(board[row][col])
            blue++;
        else
            white++;
        return ;
    }

    if(isCheck(N, row, col)) {
        if(board[row][col])
            blue++;
        else
            white++;
        return ;
    }
    // 4개로 나누고 재귀 수행
    paper(N/2, row, col);
    paper(N/2, row+(N/2), col);
    paper(N/2, row, col+(N/2));
    paper(N/2, row+(N/2), col+(N/2));
}

bool isCheck(int N, int row, int col) {
    bool check = true;
    int temp = board[row][col];
    for(int i = row ; i < row+N; i++) {
        for(int j = col; j < col+N; j++) {
            if(temp == board[i][j]) continue;
            check = false;
            break;
        }
        if(!check)
            break;
    }
    return check;
}

int main() {
    int N;
    std::cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            std::cin >> board[i][j]; // white - 0 , blue - 1
        }
    }
    paper(N, 1, 1);
    std::cout << white << "\n";
    std::cout << blue << "\n";
    return 0;

}