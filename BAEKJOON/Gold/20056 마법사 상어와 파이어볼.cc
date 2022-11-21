#include <iostream>
#include <vector>
#include <queue>
/*
    Board가 원형 구조임
    1 ~ N 까지 사용
    Board[i][j].clear를 따로 해주니까 클리어
*/
class fireBall {
public:
    int x;
    int y;
    int m;
    int d;
    int s;

    fireBall(int x, int y, int m, int s, int d) {
        this->x = x; this->y = y; this->m = m; this->d = d; this->s = s;
    }
};

int n, m_num, k;

void border_check(int &x, int &y) {
    while(x > n) {
        x -= n;
    }

    while(y > n) {
        y -= n;
    }

    while(x < 1) {
        x += n;
    }

    while(y < 1) {
        y += n;
    }

}

std::vector<fireBall> board[52][52];
std::vector<fireBall> fireBalls;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};






int main() {
    std::cin >> n >> m_num >> k;


    // FireBall 을 생성
    for(int i = 0; i < m_num; i++) {
        int x, y, m, s, d;
        std::cin >> x >> y >> m >> s >> d;
        fireBall temp = fireBall(x, y, m, s, d);
        fireBalls.push_back(temp);
    }

    // K번 이동
    // 이동 후 합치고 나누기 다시함
    for(int i = 0; i < k; i++) {
        for(fireBall fireball : fireBalls) {
            fireball.x = fireball.x += (dx[fireball.d] * fireball.s);
            fireball.y = fireball.y += (dy[fireball.d] * fireball.s);
            border_check(fireball.x, fireball.y);
            board[fireball.x][fireball.y].push_back(fireball); 
        }

        // 이동 완료 인제 fireballs를 초기화 한 후 다시 집어넣기
        fireBalls.clear();
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(board[i][j].size() <= 0) continue;// 파이어볼 X 일 때 무시
                
                else if(board[i][j].size() == 1) fireBalls.push_back(board[i][j].front());
                
                //그 위치에 파이어볼이 합쳐져 있을 경우 그 파이어볼을 없애고 4개의 파이어볼을 생성함
                else {
                    int new_m = 0;
                    int new_s= 0;
                    int temp_d = board[i][j][0].d % 2;
                    bool evened = true;
                    for(fireBall fireball : board[i][j]) {
                        new_m += fireball.m;
                        new_s += fireball.s;

                        if(temp_d != fireball.d % 2)
                            evened = false;
                    }

                    new_m /= 5;
                    new_s /= board[i][j].size();

                    // 새로운 질량이 0일 때는 생성 없이 넘어감
                    if(new_m <= 0) continue;
                    
                    // 4개 만드는 거 구현
                    for(int dir = 0; dir < 4; dir++) {
                        fireBall temp = fireBall(i, j, new_m, new_s, 0);
                        if(evened) {
                            temp.d = dir * 2;
                        }
                        else {
                            temp.d = (dir * 2) + 1;
                        }

                        fireBalls.push_back(temp);
                    }

                
                
                }

               
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) 
                board[i][j].clear();
        }
    }

    int result = 0;
    for(fireBall fireball : fireBalls) {
        result += fireball.m;
    }

    


    std::cout << result;
    return 0;
}
