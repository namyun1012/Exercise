#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
//use BFS
std::vector<int> graph[102];
int visited[102];
int dir[102];
int result_arr[102];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    int N, M;
    std::cin >> N >> M;
    int fromV, toV;
    int result = 1000000;
    int result_index;
    for(int i = 0;i < M; i++) {
        std::cin >> fromV >> toV;
        graph[fromV].push_back(toV);
        graph[toV].push_back(fromV);
    }

    std::queue<int> q;
    for(int i = 1; i <= N; i++) {
        q.push(i);
        visited[i] = 1;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for(int nxt : graph[cur]) {
                if(visited[nxt]) continue;
                visited[nxt] = 1;
                q.push(nxt);
                dir[nxt] = dir[cur] + 1;
            }
        }
        
        for(int j = 1; j <= N; j++)
            result_arr[i] += dir[j];
        
        if(result > result_arr[i]) {
            result = result_arr[i];
            result_index = i;
        }

        for(int j = 0; j <= N; j++) {
            visited[j] = 0;
            dir[j] = 0;
        }
        
    }

    std::cout << result_index;
    return 0;
}