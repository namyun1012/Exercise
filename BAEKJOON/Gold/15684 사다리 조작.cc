#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1e9

using namespace std;
/*
    71 % 정도에서 시간 초과 발생함
    더 줄일 수 있는 방법 찾아보기
    vec의 크기가 3일 때 밑의 bt문을 한 번씩 해보지 않고
    그냥 바로 return 하니까 통과함

*/
int n, m, h;

int board[12];
int exist_line[33][12];
int result = MAX;

vector<pair<int, int>> vec;

void number_change(int *a, int *b) {
    int temp = *a;
    int temp2 = *b;
    *a = temp2;
    *b = temp;
}


// check 에서 실제로 이동하고 검사해봐야 할 듯
bool check() {
    for(int i = 1; i < n; i++) {
        int cur = i;
        for(int j = 1; j <= h; j++) {
            if(exist_line[j][cur]) {
                cur = cur + 1;
            }

            else if(exist_line[j][cur-1]) {
                cur = cur - 1;
            }
        }

        if(cur != i) return false;
    }
    return true;
}

void bt(int index) {
    if(vec.size() > 3) return ;

    if(check()) {
        result = min(result, (int)vec.size());
        return ;
    }

    if(vec.size() == 3) return ;

    for(int i = index; i <= h; i++) {
        for(int j = 1; j < n; j++) {
            if(exist_line[i][j] || exist_line[i][j-1] || exist_line[i][j+1]) continue;
            exist_line[i][j] = 1;
            vec.push_back({i, j});
            
            bt(i);

            exist_line[i][j] = 0;
            vec.pop_back();
        }
    }

    return ;
}




int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);


    // 초기 input
    cin >> n >> m >> h;
    for(int i = 1; i <= n; i++) {
        board[i] = i;
    }


    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        exist_line[a][b] = 1;
    }
    
   
    bt(1);


    if(result > 3) result = -1;
    cout << result;


}