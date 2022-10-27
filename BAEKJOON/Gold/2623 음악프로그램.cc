#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
//위상 정렬을 이용한 문제, 그래프만 잘 만들어주면 됨

std::vector<int> adj[1002];
int indegrees[1002];

int temp_arr[1002]; // graph 생성을 도움
std::vector<int> result;

int main() {
    int n, m;
    std::cin >> n >> m;
    while(m--) {
        int temp_num;
        std::cin >> temp_num;

        for(int i = 0; i < temp_num; i++) { // graph 만들기
            std::cin >> temp_arr[i];
            if(i >= 1) {
                adj[temp_arr[i-1]].push_back(temp_arr[i]);
                indegrees[temp_arr[i]]++ ; 
            }
        }
    }


    std::queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indegrees[i] == 0) {
            q.push(i);
            result.push_back(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]) {
            indegrees[nxt]--;
            if(indegrees[nxt] == 0) {
                q.push(nxt);
                result.push_back(nxt);
            }
        }
    }

    if(result.size() == n) {
        for(int ele : result) {
            std::cout << ele << "\n";
        }
    }

    else{
        std::cout << 0;
    }
}