#include <iostream>



int a[52][52];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int N;
    std::cin >> N;
    int result = 0;

    int L,R;
    std::cin >> L >> R;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            std::cin >> a[i][j];
    }

    bool exited = false;
    while(true) {
        bool checked = false;
        std::pair<int, int> cur;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                cur = {i, j};
                for(int dir = 0; dir < 4; dir++) {

                }
            }
        }
    }
}