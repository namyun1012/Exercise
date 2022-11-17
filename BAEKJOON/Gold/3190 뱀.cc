/*
    뱀의 길이 : 처음에는 1
    머리 좌표로 우선 확인
    칸의 크기가 그렇게 크지 않으니 Queue 에 저장해 뒀다가 하나씩 빼는 방식으로 진행
    40분 정도 걸린 듯

*/
#include <iostream>
#include <algorithm>
#include <queue>

// 남서북동 L 일 때 왼쪽 D 일 때 오른쪽으로 회전
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};


//방향 바꾸는 배열
std::queue<std::pair<int, char>> change_dir_que;
int n;

// 사과가 있는 곳은 1 아닌 곳은 0 뱀이 존재하는 곳은 2
int board[102][102];

//방향 전환용

bool OOP(int x, int y) {
    if(x < 1  || y < 1 || x > n || y > n)
        return true;
    
    return false;
}

int change_dir_func(int dir, char temp) {
    //Left
    if(temp == 'L') {
        if(dir == 0)
            return 3;
        else
            return dir - 1;

    }

    else if(temp == 'D') {
        if(dir == 3) 
            return 0;
        else  
            return dir + 1;
    }

}


int main() {
    // 초기화
    std::cin >> n;
    int k, l;
    std::cin >> k;

    for(int i = 0; i < k; i++) {
        int x,y;
        std::cin >> x >> y;
        board[x][y] = 1;
    }

    std::cin >> l;
    
    for(int i = 0; i < l; i++) {
        int time;
        char dir;
        std::cin >> time >> dir;
        change_dir_que.push({time, dir});
    }

    std::queue<std::pair<int, int>> snake;
    snake.push({1,1});
    std::pair<int, int> head = {1,1};
    board[1][1] = 2;
    int cur_dir = 3; // 동
    int cur_length = 1;


    int time = 0;

    while(true) {
        time++;
         
        head = {head.first + dx[cur_dir], head.second + dy[cur_dir]};
        int x = head.first;
        int y = head.second;
        
        
        if(OOP(x, y) || board[x][y] == 2)
            break;
        
        
        
        // tail의 변화는 없음 사과 먹음
        
        if(board[x][y] == 1) {
            board[x][y] = 2;
            snake.push({x,y});
        }

        // tail을 비워야 함 사과 없음
        else if(board[x][y] == 0) {
            board[x][y] = 2;
            snake.push({x,y});
            int delete_x = snake.front().first;
            int delete_y = snake.front().second;
            board[delete_x][delete_y] = 0;
            snake.pop();
        }
        
   
        
        // 시간이 끝난 뒤에 방향 변화 진행
        if(time == change_dir_que.front().first) {
            cur_dir = change_dir_func(cur_dir, change_dir_que.front().second);
            change_dir_que.pop();
        }
        
        
        
        
    }

    std::cout << time << "\n";

    return 0;
}