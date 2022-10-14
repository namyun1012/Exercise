#include <iostream>

int board[9][9];
int result = 81; // 최솟값


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int N,M;
    std::cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++)
            std::cin >> board[i][j];
    }

    
    return 0;
}