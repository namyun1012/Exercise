#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

/*
    소수를 미리 다 구해놓고 이후에 BFS ?
    이동 방향을 잘 정해야 할 듯
    string 처리를 잘 생각해보고 진행해야 할 듯
*/

int numbers[10002];
int visited[10002];
int distance[10002];

int main() {
    // 소수 다 구해놓기
    numbers[1] = 1;
    numbers[2] = 0;
    for(int i = 2; i <= 10000; i++) {
        if(!numbers[i]) {
            for(int  j = i*i; j <= 10000; j+= i)
                numbers[j] = 1; 
        }
    }

    int t;
    std::cin >> t;
    
    while(t--) {
        // 방문한 곳은 0으로 초기화
        
        std::fill(visited, visited + 10000, 0);
        std::fill(distance, distance + 10000, 0);
        int st, en;
        std::cin >> st >> en;

        std::queue<int> q;
        q.push(st);
        visited[st] = 1;
        distance[st] = 0;

        while(!q.empty()) {
            int cur = q.front();
            
            q.pop();
            std::string cur_string = std::to_string(cur);
            // 자릿수 그 이후에 수
            for(int i = 0; i <= 3 ; i++) {
                for(int j = 0; j <= 9; j++) {
                    // 맨 앞이 0일 경우에는 무시
                    if(i == 0 && j ==0) continue;
                    std::string nxt_string(cur_string);
                    char temp = j + '0';
                    nxt_string[i] = temp;

                    int nxt = std::stoi(nxt_string);
                    



                    if(numbers[nxt] || visited[nxt]) continue;
                    q.push(nxt);
                    visited[nxt] = 1;
                    distance[nxt] = distance[cur] + 1;
                }
            }

            
        
        }
            
        if(visited[en] == 0) std::cout << "Impossible\n";
        else {
            std::cout << distance[en] << "\n";
        }

    }


    return 0;
}