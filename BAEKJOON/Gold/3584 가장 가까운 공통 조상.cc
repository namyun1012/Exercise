#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// toV >> fromV 로만 간선을 추가해야 함
// 그래야 root 쪽으로 타고 감
// root 반대편으로 가는 것은 필요 없음
int visited[10002];

void solve() {
    int n;
    cin >> n;
    vector<int> adj[10002];
    for(int i = 1; i <= n; i++) { 
        adj[i].clear();
        visited[i] = 0;
    }

    for(int i = 0; i < n-1; i++) {
        int fromV, toV;
        cin >> fromV >> toV;
        adj[toV].push_back(fromV);
    }

    int a, b;
    cin >> a >> b;
    queue<int> q;
    q.push(a);
    q.push(b);

    // a는 1, b는 2
    visited[a] = 1;
    visited[b] = 2;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt : adj[cur]) {
            if(visited[nxt] == visited[cur]) continue;
            if(visited[nxt] != visited[cur] && visited[nxt] != 0) {
                cout << nxt << "\n";
                return ;
            }

            q.push(nxt);
            visited[nxt] = visited[cur];

        }
    }
    cout << -1 << "\n";
    return ;

}

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
