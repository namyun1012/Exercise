#include <iostream>
#include <vector>
#include <algorithm>
class Camera {
public:
    int camera_mode;
    int camera_x;
    int camera_y;


    Camera(int _camera_mode, int x, int y) {
        camera_mode = _camera_mode;
        camera_x = x;
        camera_y = y;
    }


};
//bt를 사용해서 각 경우마다 사각지대의 최소를 구한 후 비교

int N,M;
int board[9][9]; // 변경 X
int temp_board[9][9]; // 검사할 때 사용
int result = 81; // 최솟값

std::vector<Camera> cameras;
std::vector<int> camera_dirs;

void see(int x, int y, int dir);

int check() {
    int temp = 0;
    int i = 0; // i번째 카메라의 dir
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++)
            temp_board[i][j] = board[i][j];
    }

    for(auto camera : cameras) {
        int camera_x = camera.camera_x;
        int camera_y = camera.camera_y;

        if(camera.camera_mode == 1) {
            see(camera_x, camera_y, camera_dirs[i]);
        }

        else if(camera.camera_mode == 2) {
            see(camera_x, camera_y, camera_dirs[i]);
            see(camera_x, camera_y, (camera_dirs[i] + 2) % 4);
        }

        else if(camera.camera_mode == 3) {
            see(camera_x, camera_y, camera_dirs[i]);
            see(camera_x, camera_y, (camera_dirs[i] + 1)% 4);
        }

        else if(camera.camera_mode == 4) {
            see(camera_x, camera_y, camera_dirs[i]);
            see(camera_x, camera_y, (camera_dirs[i] + 1)% 4);
            see(camera_x, camera_y, (camera_dirs[i] + 3)% 4);
        }

        else if(camera.camera_mode == 5) {
            see(camera_x, camera_y, camera_dirs[i]);
            see(camera_x, camera_y, (camera_dirs[i] + 1)% 4);
            see(camera_x, camera_y, (camera_dirs[i] + 2)% 4);
            see(camera_x, camera_y, (camera_dirs[i] + 3)% 4);
        }
        i++; // i를 더해줘야 한다... 짤 때 계속 로직을 바꾸다가 까먹었다.
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(temp_board[i][j] == 0)
                temp++;
            }
        }
    
    
    return temp;
}

void see(int x, int y, int dir) {
    int camera_x = x;
    int camera_y = y;
            if(dir == 0) { // 북
                for(int i = camera_x; i > 0; i--) {
                    if(temp_board[i][camera_y] == 0) {
                        temp_board[i][camera_y] = 7;
                    }

                    else if(temp_board[i][camera_y] == 6) {
                        break;
                    }
                }
            }

            else if(dir == 1) { // 동
                for(int i = camera_y; i <= M; i++) {
                    if(temp_board[camera_x][i] == 0) {
                        temp_board[camera_x][i] = 7;
                    }

                    else if(temp_board[camera_x][i] == 6) {
                        break;
                    }
                }
            }

            else if(dir == 2) { // 남
                for(int i = camera_x; i <= N; i++) {
                    if(temp_board[i][camera_y] == 0) {
                        temp_board[i][camera_y] = 7;
                    }

                    else if(temp_board[i][camera_y] == 6) {
                        break;
                    }
                }
            }

            else if(dir == 3) { // 서
                for(int i = camera_y; i > 0; i--) {
                    if(temp_board[camera_x][i] == 0) {
                        temp_board[camera_x][i] = 7;
                    }

                    else if(temp_board[camera_x][i] == 6) {
                        break;
                    }
                }
            }
}


void bt() {
    
    if(camera_dirs.size() == cameras.size()) {
        int temp = check();
        result = std::min(result, temp);
        return ;
    }


    for(int i = 0; i < 4; i++) {
        camera_dirs.push_back(i);
        bt();
        camera_dirs.pop_back();
    }
    

}



int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    
    std::cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            std::cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6) {
                cameras.push_back(Camera(board[i][j], i, j));
            }

        }
    }

    bt();
    std::cout << result << "\n";
    return 0;
}