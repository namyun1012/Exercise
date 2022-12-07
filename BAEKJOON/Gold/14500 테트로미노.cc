#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
/*  
    붙어있고
    4칸 만 차지한다면 어떤 도형도 되므로
    4방향으로 다 검색해보게 하는 BruteForce 알고리즘으로 해보기
    
    BFS는 안되는 듯
    그냥 polys를 배열에 넣어놓고 회전이랑 대칭을 구현하는 것이 빠를 듯
    회전 4가지의 경우,
    대칭 4가지의 경우를 다 구현하니 통과

*/

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int board[502][502];

std::pair<int, int> polys[5][3] = {
    {{1,0}, {2,0}, {3,0}},
    {{0,1}, {1,0}, {1,1}},
    {{1,0}, {2,0}, {2,1}},
    {{1,0}, {1,1}, {2,1}},
    {{1,0},{1,1},{2,0}}
};




int visited[502][502];
int complete_visited[502][502];



int n, m;

long long result = 0;

bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > m) return true;
    return false;
}


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            std::cin >> board[i][j];
        }
    }


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            visited[i][j] = 1;
            long long temp_result = board[i][j];

            std::pair<int, int> temp[3];
           
            // 도형 선정
            for(int index = 0; index < 5; index++) {
                temp[0] = polys[index][0];
                temp[1] = polys[index][1];
                temp[2] = polys[index][2];

                // 회전은 4번 하고
                for(int cir = 0; cir < 4; cir++) {
                   
                   if(cir == 0) {}
                    // 90 회전
                    else if(cir == 1) {
                        for(int k = 0; k < 3; k++) {
                            temp[k] = {temp[k].second, temp[k].first};
                        }
                    }
                    
                    else if(cir == 2) {
                        for(int k = 0; k < 3; k++) {
                            temp[k] = {temp[k].second, -temp[k].first};
                        }
                    }

                    else if(cir == 3) {
                        for(int k = 0; k < 3; k++) {
                            temp[k] = {-temp[k].second, -temp[k].first};
                        }
                    }

    
                    for(int sym = 0; sym < 4; sym++) {
                        if(sym == 0) {}
                        
                        else if(sym == 1) {
                            for(int k = 0; k < 3; k++) {
                                temp[k] = {-temp[k].first, temp[k].second};
                            }
                        }

                        else if(sym == 2) {
                            for(int k = 0; k < 3; k++) {
                                temp[k] = {temp[k].first, -temp[k].second};
                            }
                        }

                        else if(sym == 3) {
                            for(int k = 0; k < 3; k++) {
                                temp[k] = {-temp[k].first, -temp[k].second};
                            }
                        }

                        bool check = false;
                        for(int k = 0; k < 3; k++) {
                            int nxt_x = i + temp[k].first;
                            int nxt_y = j + temp[k].second;

                            if(OOP(nxt_x, nxt_y)) break;
                            
                            check = true;
                            temp_result += board[nxt_x][nxt_y];
                        
                        }
                        
                        
                        if(!check) continue;
                        result = std::max(temp_result, result);
                        temp_result = board[i][j];
                    }
                }
            }
        }
    }

    std::cout << result;
    return 0;
}