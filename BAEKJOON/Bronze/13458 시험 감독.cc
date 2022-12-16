#include <iostream>
#include <algorithm>
#include <math.h>
int board[1000002];
// 열심히 뻘짓함
int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> board[i];
    }

    long long result = 0;

    // 총 감독관, 부 감독관
    int b, c;
    std::cin >> b >> c;

    for(int i = 0; i < n; i++) {
        board[i] -= b;
        result++;


        if(board[i] > 0) {
            result += ceil(double(board[i]) / double(c));
        }
    }

    std::cout << result;
    return 0;
}