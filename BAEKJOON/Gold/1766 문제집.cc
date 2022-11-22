#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
/*
    위상 정렬에서 추가적인 정렬이 필요함
    우선순위 큐를 사용해서 BFS를 돌림

*/

std::vector<int> adj[32200];
int indegrees[32200];
int visited[32200];
std::vector<int> result;

int main() {
    int n, m;
    std::cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int startV, toV;
        std::cin >> startV >> toV;
        adj[startV].push_back(toV);
        indegrees[toV]++;
    }

    /*
        priority_queue로 BFS를 돌리는 것이 가능한가?
    
    */
    std::priority_queue<int,
                        std::vector<int>,
                        std::greater<int> > q;
    for(int i = 1; i <= n; i++) {
        if(indegrees[i] == 0) {
            q.push(i);
            visited[i] = 0;
        }
    }

    while(!q.empty()) {
        
        int cur = q.top();
        q.pop();

        result.push_back(cur);

        for(int nxt : adj[cur]) {
            indegrees[nxt]--;
            if(visited[nxt]) continue;
            if(indegrees[nxt] == 0) {
            
                q.push(nxt);
                visited[nxt] = 1;


            }
        }



    }

    for(int ele : result) {
        std::cout << ele << " ";
    }

    return 0;
}