#include <iostream>
#include <vector>
#include <cmath>
//BT로 치킨집 선정 후 함수로 확인

int board[52][52];
int checked[102];
int N, M;
std::vector<std::pair<int, int>> house_vec;
std::vector<std::pair<int, int>> chick_vec;
std::vector<std::pair<int, int>> result_vec; // M개


int result = 1e9;

//BT를 통해 선정해 준 것들을 가지고 구함
void cal_result() {
    int chick_dis = 0;
    for(auto house :house_vec) {
        int house_dis = 2*N;
        for(auto chick : result_vec) {
            house_dis = std::min(house_dis, std::abs(house.first - chick.first) + std::abs(house.second - chick.second));
        }
        chick_dis += house_dis;
    }

    result = std::min(result, chick_dis);
}


//순열이 아니라 조합으로 바꾸니 성공함
void bt(int index) {
    if(result_vec.size() == M) {
        cal_result();
        return ;
    }

    for(int i = index; i < chick_vec.size(); i++) { 
        if(checked[i]) continue;
        checked[i] = 1;
        result_vec.push_back(chick_vec[i]);
        bt(i);
        result_vec.pop_back();
        checked[i] = 0;
    }
}


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    std::cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> board[i][j];
            if(board[i][j] == 1)
                house_vec.push_back({i,j});
            if(board[i][j] == 2)
                chick_vec.push_back({i,j});

        }
    }

    bt(0);
    std::cout << result;


    return 0;
}