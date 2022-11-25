#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

int board[502][502];
int visited[502][502];

int n;
std::pair<int, int> tornado;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

// cur_dir 방향 , 수직 방향, 날리는 수
std::tuple<int, int, int> winds[] = {{2,0,5}, {1,1,10}, {1,-1,10}, {0,2,2}, {0,-2,2}, {0,1,7}, {0,-1,7}, {-1,1,1}, {-1,-1,1}};

/*
    격자 밖으로 이동한 모래는 삭제함
    삭제된 모래 양을 구하자
    정말 놀랍게도 원트 어캐했지
    1시간 정도 걸림

*/
bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > n) return true;
    return false;
}

// 반시계 방향으로 돌림
int change_dir(int dir) {
    if(dir == 3) return 0;
    else return dir + 1;
}

int change_dir_wind(int dir) {
    if(dir == 0) return 3;
    else return dir - 1;
}

int sand = 0;
/*
    First 토네이도 1칸 움직임,
    그 때마다 다 날림
    우선 토네이도 이동부터 구현 완료
    인제 모래들을 날림
    cur_dir 기준으로 
*/

int main() {
    std::cin >> n;
    tornado = {n/2 + 1, n/2 + 1};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            std::cin >> board[i][j];
            sand += board[i][j];
        }
    }

    // 이동 거리가 1
    int cur_dir = 0;
    int time = 0;
    // 3, 
    int dir_length = 2; // i/2 일 때, i 일 때 방향 전환
    int temp_length = 0;
    visited[tornado.first][tornado.second] = 1;

    while(true) {
        tornado = {tornado.first + dx[cur_dir], tornado.second + dy[cur_dir]};
        if(OOP(tornado.first, tornado.second)) break;
        if(visited[tornado.first][tornado.second]) break;
        
        visited[tornado.first][tornado.second] = 1;
        temp_length++;

        int prev_sand = board[tornado.first][tornado.second];
        int cur_sand = prev_sand;
        
        for(auto wind : winds) {
            std::pair<int, int> target = {tornado.first, tornado.second};
            int tem1, tem2, value;
            std::tie(tem1, tem2, value) = wind;
            // tem1 은 dir 방향임
            target.first +=  (dx[cur_dir]  * tem1);
            target.second += (dy[cur_dir]  * tem1);

            //tm2 는 dir 수직 방향 시계 방향으로 한번 돌림
            int temp_dir = change_dir_wind(cur_dir);
            target.first +=  (dx[temp_dir]  * tem2);
            target.second += (dy[temp_dir]  * tem2);

            // 소수점 버려야 했다. 안틀린게 용함
            int temp_sand = int((float(value * prev_sand) / float(100)));
            cur_sand -= temp_sand;
            if(OOP(target.first, target.second)) continue;
            board[target.first][target.second] += temp_sand;

        }
        
        board[tornado.first + dx[cur_dir]][tornado.second + dy[cur_dir]] += cur_sand;
        board[tornado.first][tornado.second] = 0;

        // tornado 방향 전환은 날리고 난 뒤에 진행하자
        if(temp_length * 2 == dir_length) {
            cur_dir = change_dir(cur_dir);
        }

        if(temp_length == dir_length) {
            cur_dir = change_dir(cur_dir);
            temp_length = 0;
            dir_length += 2;
        }


        time++;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sand -= board[i][j];
        }
    }

    std::cout << sand;
    return 0;
    
}


