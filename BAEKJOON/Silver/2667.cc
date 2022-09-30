#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

int board[27][27];
int visited[27][27];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//bfs
int main() {
    int N;
    int count = 0;
    std::cin >> N;
    std::vector<int> result_set;
    
    std::string temp;
    for(int i = 0; i < N; i++) {
        std::cin >> temp;
        for(int j = 0; j < N; j++) {
            board[i][j] = temp[j] - '0';
        }
    }
    
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j] || board[i][j] != 1) continue;
            
            std::queue<std::pair<int, int>> que;
            que.push({i,j});
            visited[i][j] = 1;
            

            int temp_count = 0;
            
            while(!que.empty()) {
                std::pair<int, int> cur = que.front();
                que.pop();
                temp_count++;

                for(int dir = 0; dir < 4; dir++) {
                    
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx <0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(visited[nx][ny] || board[nx][ny] != 1) continue;
                    visited[nx][ny] = 1;
                    que.push({nx, ny});
                    
                }
            }
            count++;
            result_set.push_back(temp_count);
        }
    }
    
    std::sort(result_set.begin() ,result_set.end());
    
    std::cout << count << "\n";
    for(int ele : result_set) {
        std::cout << ele << "\n";
    }
    

  
    return 0;
}


