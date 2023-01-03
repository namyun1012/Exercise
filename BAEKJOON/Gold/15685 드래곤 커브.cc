/*
    원트 한게 신기한 문제
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int board[102][102];

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

// x, y, d, g 시작 점, 시작 방향
vector<int> curve[20];

// 세대가 달성 될 때까지 돌림
int generation[20];

// 그릴 때마다 지속적으로 바꿔야 함
pair<int, int> end_location[20];

int change_dir(int dir) {
    if(dir < 3) return (dir + 1);
    return 0;
}

bool OOP(int x, int y) {
    if(x < 0 || y < 0 || x > 100 | y > 100) return true;
    return false;
}

int main() {
    // 처음 드래곤 커브들을 받음
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        curve[i].push_back(d);
        generation[i] = g;
        
        board[y][x] = 1;
        board[y + dx[d]][x + dy[d]] = 1;
        end_location[i] = {y + dx[d], x + dy[d]};
    }

    // 드래곤 커브들을 보드상에 그림
    for(int i = 0; i < n; i++) {
        bool check = false;
        for(int g = 1; g <= generation[i]; g++) {    
            int cur_size = curve[i].size();
            
            // 끝지점 부터 시작해야 함
            for(int j = cur_size - 1; j >= 0; j--) {
                int cur_x = end_location[i].first;
                int cur_y = end_location[i].second;

                // 코드 상 방향을 시계 반대 방향으로 돌림
                // 그리고 진행함
                int d = change_dir(curve[i][j]);
                int nxt_x = cur_x + dx[d];
                int nxt_y = cur_y + dy[d];
                
                if(OOP(nxt_x, nxt_y)) {
                    check = true;
                    break;
                }

                board[nxt_x][nxt_y] = 1;
                end_location[i].first = nxt_x;
                end_location[i].second = nxt_y;

                // 시계 반대 방향으로 돌려져 있는 상태인 것을 추가함
                // 위에서 curve의 size를 미리설정해 두었기 때문에
                // 추가될 당시에는 돌아가지 않음
                curve[i].push_back(d);

            }

            if(check) break;
        }
    }
    int result = 0;
    // 4개의 꼭짓점이 전부 드래곤 커브인 것 확인
    for(int i = 0; i <= 99; i++) {
        for(int j = 0; j <= 99; j++) {
            if(board[i][j] && board[i][j+1] && board[i+1][j] && board[i+1][j+1])
                result++;
        }
    }

    /*
    testing code
    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= 10; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    */

    cout << result;
    return 0;
}

