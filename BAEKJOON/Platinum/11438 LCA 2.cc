#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define MAX 100002
#define MAX_log 18
// log2 MAX 16.6666
/*
    메모리가 노답
    OutOfBounds 계속 뜸
*/

using namespace std;

int n;
vector<vector<int>> adj;
int depth[MAX];
int parent[MAX][MAX_log];

void dfs(int cur) {
    for(int nxt : adj[cur]) {
        if(depth[nxt] == -1) {
            // 바로 위의 부모는 현재임
            parent[nxt][0] = cur;
            depth[nxt] = depth[cur] + 1;
            dfs(nxt);
        }
    }
    
    return ;
}

void connection() {
    for(int k = 1; k < MAX_log; k++) {
        for(int cur = 1; cur <= n; cur++) {
            // 연결을 해줄 때 parent[cur][k-1] 이 -1 인 경우를 제외해야 했음
            if(parent[cur][k-1] != -1)
                parent[cur][k] = parent[parent[cur][k-1]][k-1];
        
        }
    }

    return ;
}

int LCA(int u, int v) {
    if(depth[u] < depth[v]) {
        swap(u, v);
    }


    int diff = depth[u] - depth[v];

    for(int i = 0; diff > 0; i++) {
        if(diff % 2 == 1)
            u = parent[u][i];

        diff /= 2;
    }

    if(u != v) {
        for(int i = MAX_log - 1; i >= 0; i--) {
            if(parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }

        u = parent[u][0];
    }

    return u;
}


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    cin >> n;

    adj.resize(n+1);
    fill(depth, depth + n + 1, -1);
    memset(parent, -1, sizeof(parent));

    depth[1] = 0;


    for(int i = 0; i < n-1; i++) {
        int fromV, toV;
        cin >> fromV >> toV;
        adj[fromV].push_back(toV);
        adj[toV].push_back(fromV);
    }

    dfs(1);
    connection();
    
    int m;
    cin >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }

    return 0;
}