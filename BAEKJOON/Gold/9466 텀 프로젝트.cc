#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int board[100002];
int visited[100002];
/*
    Test Case가 빡빡한 편임
    중간 부터 시작하는 것 넣어주었더니 정답뜸
*/
void Test() {
    int n;
    std::cin >> n;
    
    std::fill(board, board + n + 1, 0);
    // 더 이상 방문 필요 X >> 1
    // 임시적으로 방문했음 >> 2
    std::fill(visited, visited + n + 1, 0);

    for(int i = 1; i <= n; i++) {
        std::cin >> board[i];
    }

    int teams = 0;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 1) continue;
        if(board[i] == i) {
            teams++;
            visited[i] = 1; 
            continue;
        }

        int st = i;

        std::queue<std::pair<int, int>> q;
        std::vector<int> temp;

        visited[st] = 1;
        temp.push_back(st);
        q.push({st, -1});
        int mid_st = st;

        bool teamed = false;
        while(!q.empty()) {
            int cur = q.front().first;
            int prev = q.front().second;
            int nxt = board[cur];
            q.pop();

            if(prev == cur) {
                break;
            }
            // 첫 번째 부터 끝 까지
            if(nxt == st) {
                teamed = true;
                break;
            }

            if(visited[nxt] == 1) 
                break;
            
            // 중간 부터 끝 까지
            if(visited[nxt] == 2) {
                // 중간 지점 설정
                mid_st = nxt;
                teamed = true;
                break;
            }

            q.push({nxt, cur});
            visited[nxt] = 2;
            temp.push_back(nxt);
       
        }

        if(!teamed) {
            for(int ele : temp) {
                visited[ele] = 0;
            }
            // st는 어처피 더 이상 안됨
            visited[st] = 1;
            continue;
        }    

        bool start = false;
        for(int ele : temp) {
            if(ele == mid_st) start = true;
            visited[ele] = 1;
            // start 지점부터 추가해줌
            if(start) {
                teams++;
            }
        }

    }

    std::cout << n - teams << "\n";
    return ;
}



int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    
    while(t--) {
        Test();
    }




    return 0;

}