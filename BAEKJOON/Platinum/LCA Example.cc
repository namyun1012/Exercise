#include <iostream>
#include <vector>
#include <algorithm>
#define N 10000
// log 2  N  == 13.2....
// LCA 다시 한번 보기

using namespace std;

vector<int> adj[N];
int depth[N];
int parent[1000][N];


void dfs(int cur) {
    for(int nxt : adj[cur]) {
        if(depth[nxt] == -1) {
            parent[nxt][0] = cur;
            depth[nxt] = depth[cur] + 1;
            dfs(nxt);
        }
    }
    
}

void connection() {
    for(int k = 1; k <= 14; k++) {
        for(int cur = 1; cur <= N; cur++) {
            parent[cur][k] = parent[parent[cur][k-1]][k-1];
            /*
            parent[cur][k] cur의 2^k 번째 부모는
             =
             parent[parent[cur][k-1]][k-1];
             2^k-1 번째 떨어진 부모의
             2^k-1 번쨰 부모임
            
            
            */
        }
    }

    return ;
}

int LCA(int u, int v) {
    if(depth[u] < depth[v]) {
        swap(u, v);
    }

    int diff = depth[u] - depth[v];

    for(int i = 0; diff != 0; i++) {
        if(diff % 2 == 1)
            u = parent[u][i];

        diff /= 2;
    }
}

