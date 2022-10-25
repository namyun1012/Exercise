#include <iostream>
#include <algorithm>

int board[1000002]; // 1부터 시작 날짜 별 주가

int main() {
    int T;
    std::cin >> T;

    while(T--) {

        int n;
        std::cin >> n;
        std::fill(board, board+n,0);

        for(int i = 1; i <= n; i++) {
            std::cin >> board[i];
        }

    }
}