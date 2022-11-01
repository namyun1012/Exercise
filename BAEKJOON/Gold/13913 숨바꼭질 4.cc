#include <iostream>
#include <queue>
#include <stack>

int dp[100002];
int prev_dp[100002];
int visited[100002];

bool OOP(int x) {
    if(x < 0 || x > 100000) return true;
    return false;
}

int Calc(int x, int dir) {
    if(dir == 0)
        return x + 1;
    if(dir == 1)
        return x - 1;
    if(dir == 2)
        return x * 2;
} 

int main() {
    int n, k;
    std::cin >> n >> k;

    std::queue<int> q;
    q.push(n);
    visited[n] = 1;
    dp[n] = 0;
    prev_dp[n] = -1; // k가 0 일때를 고려


    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int dir = 0; dir < 3; dir++) {
            int nxt = Calc(cur, dir);
            if(OOP(nxt)) continue;
            if(visited[nxt]) continue;

            q.push(nxt);
            visited[nxt] = 1;
            prev_dp[nxt] = cur;
            dp[nxt] = dp[cur] + 1;

        }
        
    }

    std::cout << dp[k] << "\n";
    
    std::stack<int> s;
    int temp = k;
    
    while(temp != -1) {
        s.push(temp);
        temp = prev_dp[temp];
    }

    while(!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }

    return 0;
}