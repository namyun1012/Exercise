#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int board[22][22];
int visited[22];
int result = 1e9;
int n;
std::vector<int> start_team; // 여기 없는 인덱스는 링크 팀
std::vector<int> link_team;

void min_check() {
    link_team.clear();
    for(int i = 1; i <= n; i++) {
        if(!visited[i])
            link_team.push_back(i);        
    }

    int start_score = 0;
    int link_score = 0;

    for(int i : start_team) {
        for(int j : start_team) {
            start_score += board[i][j];
        }
    }

    for(int i : link_team) {
        for(int j : link_team) {
            link_score += board[i][j];
        }
    }

    int temp = abs(start_score - link_score);
    result = std::min(result, temp);
}

void bt(int index) {
    if(start_team.size() == n/2) {
        min_check();
        return ;
    }

    for(int i = index; i < n; i++) {
        if(visited[i]) continue;
        visited[i] = 1;
        start_team.push_back(i);
        bt(i + 1);
        start_team.pop_back();
        visited[i] = false;
    }

}


int main() {
    
    std::cin >> n;

    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= n; j++) {
            std::cin >> board[i][j];
        }
    }

    bt(1);

    std::cout << result;
    return 0;
}