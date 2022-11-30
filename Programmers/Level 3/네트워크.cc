#include <string>
#include <vector>
#include <queue>
using namespace std;


int visited[202];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i <= n-1; i++) {
        if(visited[i]) continue;
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for(int j = i+1; j <= n-1; j++) {
                if(computers[cur][j] == 0) continue;
                if(visited[j]) continue;
                q.push(j);
                visited[j] = 1;
            
            }
        }
        
        answer++;
        
    }

    return answer;
}