#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

// 틀림
// n >= 3
// BT는 아닌 듯 
int n;
int board[22][22];
int favorited[402][4];
int students;
std::vector<int> order;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


bool OOP(int x, int y) {
    if(x < 1 || y < 1 || x > n || y > n) return true;
    return false;
}

int main() {
    std::cin >> n;
    students = n * n;

    // 주위 비어있는 보드의 개수 초기 설정
   


    for(int i = 1; i <= students; i++) {
        int stu_num;
        std::cin >> stu_num;
        order.push_back(stu_num);
        for(int j = 0; j < 4; j++) {
            std::cin >> favorited[stu_num][j];
        }
    }

    for(int num : order) {
        // 비어있는 경우 + 1 인접한 애들이 있는 경우 + 4
        int check_value = 0;
        int selected_x = 0; 
        int selected_y = 0;

        // 각 구역마다 검사
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                
                // 이미 있는 경우는 들어갈 수 없으므로 검사할 필요 없음
                if(board[i][j] != 0) continue;
                int temp_value = 0;

                for(int dir = 0; dir < 4; dir++) {
                    int nxt_x = i + dx[dir];
                    int nxt_y = j + dy[dir];
                    if(OOP(nxt_x, nxt_y)) continue;
                    
                    // 비어 있을 때
                    if(board[nxt_x][nxt_y] == 0) temp_value++;
                    
                    // 비어있지 않을 때
                    else {
                        for(int index = 0; index < 4; index++) {
                            if(favorited[num][index] == board[nxt_x][nxt_y]) {
                                temp_value += 10; // 4칸이 다 비어있는 경우
                            }
                        }
                    } 

                }

                if(check_value < temp_value) {
                    check_value = temp_value;
                    selected_x = i;
                    selected_y = j;
                }


                if(selected_x == 0) {
                    selected_x = i;
                    selected_y = j;
                }


            }
        }

        board[selected_x][selected_y] = num;
    }


    //만족도 구하기
    int result = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
                int temp_num = 0;
                for(int dir = 0; dir < 4; dir++) {
                    int nxt_x = i + dx[dir];
                    int nxt_y = j + dy[dir];

                    if(OOP(nxt_x, nxt_y)) continue;
                    for(int index = 0; index < 4; index++) {
                        if(favorited[board[i][j]][index] == board[nxt_x][nxt_y]) {
                            temp_num++;
                        }
                    }
                    
                } 
                
                if(temp_num == 0);
                else if(temp_num == 1) result += 1;
                else if(temp_num == 2) result += 10;
                else if(temp_num == 3) result += 100;
                else if(temp_num == 4) result += 1000;      
        }
    }
    
    std::cout << result << "\n";
    /* Testing Code
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }

    */
    return 0;

}