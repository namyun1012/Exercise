#include <iostream>
#include <algorithm>
#define INF 1e9
int board[501][501];

int main() {
    int tc;
    std::cin >> tc;

    while(tc--) {
        std::fill(&board[0][0], &board[500][500], INF);
        int n, m, w;
        std::cin >> n >> m >> w;
        
        for(int i = 1; i <= n; i++) { // 0을 먼저 설정해줘야 했음
            board[i][i] = 0;
        }
        
        for(int i = 0; i < m; i++) {
            int fromV, toV, weight;
            std::cin >> fromV >> toV >> weight;
            if(board[fromV][toV] != INF) { // 중복되는 것이 있을 때는 작은 거를 받아야 함 
                board[fromV][toV] = std::min(board[fromV][toV], weight);
                board[toV][fromV] = board[fromV][toV];
                continue;
            }
            board[fromV][toV] = weight;
            board[toV][fromV] = weight;
        }

        for(int i = 0; i < w; i++) {
            int fromV, toV, weight;
            std::cin >> fromV >> toV >> weight;
            board[fromV][toV] = -weight;
        }

        

        for(int k = 1; k <= n ; k++) { // 여긴 애초부터 맞음
            for(int i =1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    board[i][j] = std::min(board[i][j], board[i][k] + board[k][j]);
                }
            }
        }

        bool result_check = false;

        for(int i = 1; i <= n; i++) {
            if(board[i][i] < 0) {
                result_check = true;
                break;
            }
        }

        if(result_check) std::cout << "YES\n";
        else std::cout << "NO\n";

        
    }

    return 0;

}