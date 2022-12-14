#include <iostream>
#include <algorithm>
#include <vector>

// 순환형 보드
int n, m;
int board[52][52];
int exist_board[52][52];

std::pair<int, int> orders[102];
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

std::vector<std::pair<int, int>> clouds;
std::vector<std::pair<int, int>> existed_clouds;

int circulate(int x) {
    while(x > n) {
        x -= n;
    }

    while(x < 1) {
        x += n;
    }

    return x;
}

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > n) return true;
    return false;
}


int main() {
    // 초기 설정
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            std::cin >> board[i][j];
        }
    }

    for(int i = 1; i <= m; i++) {
        int d, s;
        std::cin >> d >> s;
        orders[i].first = d - 1;
        orders[i].second = s;    
    }

    clouds.push_back({n,1});
    clouds.push_back({n, 2});
    clouds.push_back({n-1, 1});
    clouds.push_back({n-1, 2});

    for(int i = 1; i <= m; i++) {
        std::fill(&exist_board[0][0], &exist_board[51][51], 0);
        existed_clouds.clear();

        

        int dir = orders[i].first;
        int s = orders[i].second;


        // 이동하고 비를 내림
        for(auto &cloud : clouds) {
            int temp_x = cloud.first + (s *dx[dir]);
            int temp_y = cloud.second + (s *dy[dir]);
            cloud = {circulate(temp_x), circulate(temp_y)};
            board[cloud.first][cloud.second] += 1;
            existed_clouds.push_back({cloud.first, cloud.second});
            exist_board[cloud.first][cloud.second] = 1;
        }

        clouds.clear();
        

        for(auto cloud : existed_clouds) {
            int water_exist = 0;
            for(int temp_dir = 1; temp_dir < 8; temp_dir += 2) {
                int temp_x = (cloud.first + dx[temp_dir]);
                int temp_y = (cloud.second + dy[temp_dir]);
                if(OOP(temp_x, temp_y)) continue;
                if(board[temp_x][temp_y] > 0) water_exist++;
            }

            board[cloud.first][cloud.second] += water_exist;

        }
 
        for(int x = 1; x <= n; x++) {
            for(int y = 1; y <= n; y++) {
                if(board[x][y] >= 2 && exist_board[x][y] == 0) {
                    clouds.push_back({x, y});
                    board[x][y] -= 2;
                }
            }
        }

        // Testing Code

    }


    int result = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            result += board[i][j];
    }

    std::cout << result;
    return 0;
}