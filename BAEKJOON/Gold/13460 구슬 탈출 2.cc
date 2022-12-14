#include <iostream>
#include <vector>
#include <string>
#include <queue>

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

char board[12][12];
int visited[12][12];
int distance[12][12];

int n, m;

std::pair<int, int> red;
std::pair<int, int> blue;
std::pair<int, int> hole;
/*
    red와 blue의 좌표를 함께 큐의 값으로 받아야 할 듯
*/

int result = 0;

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > m) return true;
    return false;
}

int main() {
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        std::string temp;
        std::cin >> temp;
        for(int j = 1; j <= m; j++) {
            board[i][j] = temp[j-1];
            if(board[i][j] == 'R') red = {i, j};
            if(board[i][j] == 'B') blue = {i, j};
            if(board[i][j] == 'O') hole = {i, j};
        }
    }


    std::queue<std::pair<int, int>> q;


    
    
    return 0;
}