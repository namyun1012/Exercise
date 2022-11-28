#include <iostream>
#include <algorithm>
#include <vector>
/*
    robot을 -1 로 하고 무시하는 것은 역시 안되는 듯 하다.
    그냥 따로 robot을 만들지 말고 robot_board를 회전시키자.
    개인적으로 실수가 많았다.
    
*/

int n, k;
// 1~2n 까지 사용
// 1번칸 올리는 위치, n번칸 내리는 위치
int board[202];
int temp_board[202];
int robot_board[202];
int temp_robot_board[202];
std::vector<int> robots;



// 회전
void rotate() {
    for(int i = 1; i <= 2*n; i++) {
        temp_board[i] = board[i];
    }

    for(int i = 1; i <= 2*n-1; i++) {
        board[i+1] = temp_board[i];
    }

    board[1] = temp_board[2*n];


    // robot_board
    for(int i = 1; i <= n; i++) {
        temp_robot_board[i] = robot_board[i];
    }

    for(int i = 1; i <= n-1; i++) {
        robot_board[i+1] = temp_robot_board[i];
    }
    robot_board[1] = 0;
    robot_board[n] = 0;

    //robot_board[1] = temp_robot_board[2*n];
    
}
/*
    1번 회전


*/


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    int time = 1;
    std::cin >> n >> k;
    for(int i = 1; i <= 2*n; i++) {
        std::cin >> board[i];
    }

    while (true)
    {
        // 1번 회전
        rotate();

        //2번 로봇 별로 이동 가능할시 이동
        //가장 먼저 올라간 로봇 순이므로 n-1 일 때 부터 진행하자 n+ 1부터는 robot 없음
       for(int i = n-1; i  >= 1 ; i--) {
            if(robot_board[i] == 0) continue;
            
            if(robot_board[i+1] == 0 && board[i+1] > 0) {
                int temp_robots = robot_board[i];
                robot_board[i] -= 1;
                robot_board[i+1] += 1;
                board[i+1] -= 1;
            }

            robot_board[n] = 0;
       }
        

        // 3번째 로봇 올리기
        if(board[1] > 0) { 
            robot_board[1]++;
            board[1]--;
        }

        //4. 검사 후 체크
        int temp = 0;
        for(int j = 1; j <= 2*n; j++) {
            if(board[j] == 0) temp++;
        }

        if(temp >= k)
            break;
    

        time++;

    }
    
    std::cout << time;
    return 0;
}