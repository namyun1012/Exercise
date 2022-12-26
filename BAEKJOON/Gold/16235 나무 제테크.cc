#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

/*
    나이가 어린 나무부터 양분을 먹음
    벡터로 두고 뒤쪽 부터 먹게 하면 될 듯
    47% 가량에서 시간초과 >> 이후 76%
    pq로는 안되나? >> vector로 하니까 정답뜸
*/
using namespace std;

int n, m, k;
int food[11][11];
int saved_food[11][11];

vector<int> board[11][11];

int dx[8] = {-1,-1,-1,1,1,1,0,0};
int dy[8] = {1,0,-1,-1,0,1,-1,1};

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > n) return true;
    return false;
}

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> saved_food[i][j];
            food[i][j] = 5;
        }
    }

    // 나무의 위치가 일단은 모두 다르기 때문에 상관은 없음
    // 넣을 때는
    for(int i = 0; i < m; i++) {
        int x, y, age;
        cin >> x >> y >> age;
        board[x][y].push_back(age);
    }

    
    
    while(k--) {
        // x, y, age;
        vector<tuple<int, int, int>> lived;
        vector<tuple<int, int, int>> dead;
        // 봄
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // 뒤에가 작으므로 뒤에서 부터 처리함
                while(!board[i][j].empty()) {
                    int cur = board[i][j].back();

                    if(food[i][j] >= cur) {
                        // 작은 것들이 lived에 먼저들어 옴
                        lived.push_back({i, j, cur + 1});
                        food[i][j] -= cur;
                    }

                    else {
                        dead.push_back({i, j, cur});
                    }

                    board[i][j].pop_back();
                }
            }
        }

        // 여름
        // 봄에 죽은 나무가 양분으로 변함
        for(auto tree : dead) {
            int x, y, age;
            tie(x, y, age) = tree;
            food[x][y] += (age/2);
        }
        
        for(int i = lived.size() -1 ; i >= 0; i--) {
            int x, y, age;
            tie(x, y, age) = lived[i];
            // 예전 것 추가해 주기
            board[x][y].push_back(age);  
        }

        // 가을, 나무가 번식함 age가 5의 배수인 친구들만
        for(auto tree : lived) {
            int x, y, age;
            tie(x, y, age) = tree;

            // 5의 배수가 아닌 경우 필요없음
            if(age % 5 != 0) continue;
            for(int dir = 0; dir <8; dir++) {
                int nxt_x = x + dx[dir];
                int nxt_y = y + dy[dir];
                if(OOP(nxt_x, nxt_y)) continue;
                board[nxt_x][nxt_y].push_back(1);
            }
        }

        //겨울 양분 재 추가
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                food[i][j] += saved_food[i][j];
            }
        }
    }

    

    int result = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            result += board[i][j].size();
        }
    }

    cout << result;
    return 0;
}