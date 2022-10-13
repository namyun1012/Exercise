#include <iostream>

int board[1025][1025];
int sum[1025][1025];
#define X first
#define Y second
int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int N, M;
    std::cin >> N >> M;
    int row_sum = 0;
    int col_sum = 0;
    for(int i = 1 ; i <= N; i++) {
        int row_sum = 0;
        for(int j = 1; j <= N; j++) {
            std::cin >> board[i][j];
            row_sum += board[i][j];
            sum[i][j] = row_sum;
        }
    }

    while(M--) {
        int result = 0;
        std::pair<int, int> n1, n2;
        std::cin >> n1.X >> n1.Y >> n2.X >> n2.Y;
        for(int i = n1.X ; i <= n2.X; i++) {
            result += sum[i][n2.Y] - sum[i][n1.Y-1];
        }

        std::cout << result << "\n";
    }
}