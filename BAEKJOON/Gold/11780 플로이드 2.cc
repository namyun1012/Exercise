#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 0x3f3f3f3f

int board[102][102];
int prev_board[102][102]; // 최솟값 위해서 어디로 가야하는 지
/*



*/
int main() {
    int n, m;
    std::cin >> n >> m;
    std::fill(&board[0][0], &board[101][101], MAX);

    for(int i = 1; i <= n ; i++) {
        board[i][i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int fromV, toV, weight;
        std::cin >> fromV >> toV >> weight;
        
        if(board[fromV][toV] > weight) {
            board[fromV][toV] = weight;
            prev_board[fromV][toV] = toV; // 우선은 j를 위해서는 j로 직행하는 방법이 최선
        }
    
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n ; i++) {
            for(int j = 1; j <= n; j++) {
                
                if(board[i][j] > board[i][k] + board[k][j]) {
                    prev_board[i][j] = prev_board[i][k]; // j 로 가기 위해서는 우선 k로 가야함
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
            if(board[i][j] == 0 || board[i][j] == MAX) { // 자기 자신이거나 갈 수가 없는 경우는 0
                std::cout << 0 << "\n";
            }

            else {
                std::queue<int> s;
                int temp = i;
                
                while(temp != j) {
                    s.push(temp);
                    temp = prev_board[temp][j];
               
               }

                s.push(j);
                std::cout << s.size() << " ";
                while(!s.empty()) {
                    std::cout << s.front() << " ";
                    s.pop();
                    
                }

                std::cout << "\n";
            }
        }
    }

    return 0;
}