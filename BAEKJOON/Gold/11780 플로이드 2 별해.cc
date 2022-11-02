#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 0x3f3f3f3f

int board[102][102];
std::vector<int> prev_board[102][102]; // i ~ j 까지 가는데 경로 추적

int main() {
    int n, m;
    std::cin >> n >> m;
    std::fill(&board[0][0], &board[101][101], MAX);

    for(int i = 1; i <= n ; i++) {
        board[i][i] = 0;
        prev_board[i][i].push_back(i);
    }

    for(int i = 0; i < m; i++) {
        int fromV, toV, weight;
        std::cin >> fromV >> toV >> weight;
        
        if(board[fromV][toV] > weight) {
            board[fromV][toV] = weight;
            prev_board[fromV][toV].clear();
            prev_board[fromV][toV].push_back(fromV);
            prev_board[fromV][toV].push_back(toV);
        }
    
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n ; i++) {
            for(int j = 1; j <= n; j++) {
                
                if(board[i][j] > board[i][k] + board[k][j]) {
                    prev_board[i][j].clear();
                    
                    for(int l = 0; l < prev_board[i][k].size() ; l++)
                        prev_board[i][j].push_back(prev_board[i][k][l]);

                    
                    for(int l = 1; l < prev_board[k][j].size() ; l++) // 중복 방지 위해 index 1 부터
                        prev_board[i][j].push_back(prev_board[k][j][l]);
                    
                    board[i][j] = board[i][k] + board[k][j];
                }
        
            }
        }
    }

    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= n; j++) {
            if(board[i][j] >= MAX)
                std::cout << 0 << " ";
            else {
                std::cout << board[i][j] << " ";
            }

        }

        std::cout << "\n";
    }

    for(int i = 1; i <= n ; i++) {
        for(int j = 1 ; j <= n; j++){
            if(board[i][j] == 0 || board[i][j] == MAX) {
                std::cout << 0 << "\n";
            }

            else {
                std::cout << prev_board[i][j].size() << " ";
                for(int ele : prev_board[i][j])
                    std::cout << ele << " ";
                std::cout << "\n";
            }
        }
    }

    return 0;
}