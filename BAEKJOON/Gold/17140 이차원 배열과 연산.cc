#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
/*
    74 % 에서 한 번 틀림 오류있는 지 체크
    >> 최대치 설정 기준에서 약간 문제가 있었는 듯
*/
using namespace std;

int board[101][101];
int r,c,k;

bool OOP(int x) {
    if(x < 1 || x > 100) return true;
    return false;
}


int main() {
    cin >> r >> c >> k;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) 
            cin >> board[i][j];
    }

    int time = 0;
    int row_length = 3;
    int cal_length = 3;

    while(time <= 100) {
        

        if(board[r][c] == k) {
            cout << time;
            return 0;
        }


        // R연산
        if(row_length >= cal_length) {
            int temp_cal = 0;           
            for(int i = 1; i <= row_length; i++) {
                // 들어갈 수 있는 최대치는 100까지 임
                vector<pair<int, int>> v(101, {0, 0});
                for(int j = 1; j <= cal_length; j++) {
                    int cur = board[i][j];
                    // 현재가 0이면 다음 것도 다 0인 듯
                    if(cur == 0) continue;
                    v[cur] = {v[cur].first + 1, cur};

                    // 미리 청소해 놓음
                    board[i][j] = 0;
                }

                int index = 1;
                sort(v.begin(), v.end());
                for(auto ele : v) {
                    if(index > 100) break;
                    if(ele.first == 0) continue;
                    board[i][index] = ele.second;
                    index++;
                    board[i][index] = ele.first;
                    index++;
                }

                // 최고의 길이를 선정함
                temp_cal = max(temp_cal, index-1);

            }
            
            cal_length = temp_cal;
        }

        // C연산
        else {
            int temp_row = 0;
            
            for(int j = 1; j <= cal_length; j++) {

                // 들어갈 수 있는 최대치는 100까지 임
                vector<pair<int, int>> v(101, {0, 0});
                for(int i = 1; i <= row_length; i++) {
                    int cur = board[i][j];
                    // 현재가 0이면 다음 것도 다 0인 듯
                    if(cur == 0) continue;
                    v[cur] = {v[cur].first + 1, cur};

                    // 미리 청소해 놓음
                    board[i][j] = 0;
                }

                int index = 1;
                sort(v.begin(), v.end());
                for(auto ele : v) {
                    if(index > 100) break;
                    if(ele.first == 0) continue;
                    board[index][j] = ele.second;
                    index++;
                    board[index][j] = ele.first;
                    index++;
                }

                // 최고의 길이를 선정함
                temp_row = max(temp_row, index-1);

            }
            
            row_length = temp_row;
        }

        /*testing Code
        for(int i = 1; i <= row_length; i++) {
            for(int j = 1; j <= cal_length; j++) {
                cout << board[i][j] <<" ";
            }
            cout << "\n";
        }
        cout << "\n";
        */
        time++;
    }

    cout << -1;
    return 0;
}