#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

int board[51][51];
bool visited[51][51];

/*
    DFS, BFS 아님
    방향 관리 이상하게 하다가 헤맴
    무한 반복 방지 위해 return 을 각 경우의 수마다 넣어야 함
*/

// 북, 동, 남, 서
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int N, M;

int left_dir(int dir) {
    if(dir == 0) return 3;
    else return (dir - 1);
}

int behind_dir(int dir) {
    if(dir == 0) return 2;
    else if(dir == 1) return 3;
    else if(dir == 2) return 0;
    else return 1;
}

void Search(int r, int c, int d) {
    if(board[r][c]) return;
    
    //4방향 검사부터 우선
    bool check = false;
    for(int dir = 0; dir < 4; dir++) {
        int temp_x = r + dx[dir];
        int temp_y = c + dy[dir];

        if(board[temp_x][temp_y] == 0 && visited[temp_x][temp_y] == 0) // 탐색 가능 지점이 있는가?
            check = true; // 아닌 것이 하나라도 있을 경우 true
    }
    
    // 4방향 전부 진행 불가일 경우
    if(!check) {
        int behind_d = behind_dir(d);
        int temp_x = r + dx[behind_d]; // 뒤쪽
        int temp_y = c + dy[behind_d];

        if(board[temp_x][temp_y] == 1) { // 뒤 쪽도 1일 경우 로봇 청소기 종료
            return ;
        }

        else {
            Search(temp_x, temp_y, d); // 바라 보는 방향을 유지한체 후진
            return;
        }
    }

    
    //왼쪽 방향
    int nxt_x = r + dx[left_dir(d)];
    int nxt_y = c + dy[left_dir(d)];
    
    // 1. 왼쪽 방향에 청소 X 공간 존재시 회전 후 한 칸 전진 후 반복
    if(board[nxt_x][nxt_y] == 0 && visited[nxt_x][nxt_y] == 0) {
        visited[nxt_x][nxt_y] = true;
        Search(nxt_x, nxt_y, left_dir(d));
        return ;
       
    }
    
    //2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
    else if(board[nxt_x][nxt_y] == 1 || visited[nxt_x][nxt_y] == 1) {
        Search(r, c, left_dir(d));
        return ;
    }


    std::cout << "Error Occur\n" ;
}
int main() {
    
    
    std::cin >> N >> M;
    int r, c, d;
    std::cin >> r >> c >> d; // (r, c) 세로, 가로 0,0 부터 시작
    // d = 0 일 때 북쪽 이 후 시계 방향으로 3까지 증가
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> board[i][j];
        }
    }
    /*
        북일 때 서부터 탐색 
    
    */
    
   visited[r][c] = true;
   Search(r,c,d);

   int result = 0;
   for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j]) result++;
        }
   }

    std::cout << result << "\n";
    return 0;
}