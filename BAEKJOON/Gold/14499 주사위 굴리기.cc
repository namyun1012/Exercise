#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
    3차원에서의 움직임을 잘 살펴보기

*/
int n, m;
int x, y; // 주사위를 놓은 곳의 좌표
int k; // 명령의 개수

int board[22][22];
vector<int> orders;

int dice[7] = {0,0,0,0,0,0,0};

int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

/*
    order가 1~2 일 때 1,3,4,6 의 index가 영향을 받고
    order가 3~4 일때 1,2,5,6

*/

bool OOP(int a, int b);
void move(int order) {
    int nxt_x = x + dx[order];
    int nxt_y = y + dy[order];

    
    if(OOP(nxt_x, nxt_y)) return;
    x = nxt_x;
    y = nxt_y;

    int temp_dice[7];
    for(int i = 0; i < 7; i++) {
        temp_dice[i] = dice[i];
    }

    // 동쪽 1,3,6,4 >> 4 ,1, 3, 6로 변경
    if(order == 1) {
        dice[1] = temp_dice[4];
        dice[3] = temp_dice[1];
        dice[6] = temp_dice[3];
        dice[4] = temp_dice[6];
    }

    // 서쪽 1,3,6.4 >> 3,6,4,1 
    else if(order == 2) {
        dice[1] = temp_dice[3];
        dice[3] = temp_dice[6];
        dice[6] = temp_dice[4];
        dice[4] = temp_dice[1];
    }

    // 북쪽 1,5,6,2 >> 5,6,2,1
    else if(order == 3) {   
        dice[1] = temp_dice[5];
        dice[5] = temp_dice[6];
        dice[6] = temp_dice[2];
        dice[2] = temp_dice[1];
    }

    // 남쪽 1,5,6,2 >> 2,1,5,6
    else if(order == 4) {
        dice[1] = temp_dice[2];
        dice[5] = temp_dice[1];
        dice[6] = temp_dice[5];
        dice[2] = temp_dice[6];
    }

    else {
        cout << "Error Occur\n";
    }

    // 밑면은  dice[6] 이다.

    if(board[x][y] == 0) {
        board[x][y] = dice[6];
    }

    else {
        dice[6] = board[x][y];
        board[x][y] = 0;
    }
    
    cout << dice[1] << "\n";
    return;
}

bool OOP(int a, int b) {
    if(a < 1 || b < 1 || a > n || b > m) return true;
    return false;
}



int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    cin >> n >> m;
    cin >> x >> y;
    cin >> k;
    x++;
    y++;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        orders.push_back(temp);
    }

    
    for(int i = 0; i < k; i++) {
        int order = orders[i];
        move(order);
    }

    return 0;

}