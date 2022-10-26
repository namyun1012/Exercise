#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define MAX 10001

int parent[MAX];
std::tuple<int, int, int> edge[10005];

int find(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) parent[y] = x;
}

bool sameparent(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return true;
    else return false;
}

int main() {
    int v,e;
    std::cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int fromV, toV, weight;
        std::cin >> fromV >> toV >> weight;
        edge[i] = {weight, fromV, toV};
    }
    
    for(int i = 0; i <= v; i++) {
        parent[i] = i;
    }
    std::sort(edge, edge + e);
    int cnt = 0;
    int ans = 0;

        for(int i = 0; i < e; i++) {
            int a,b,cost;
            std::tie(cost, a, b) = edge[i];
            if(sameparent(a,b)) continue;
            Union(a, b);
            ans += cost;
            cnt++;
            if(cnt == v-1) break;
        }
    
    std::cout << ans;
    return 0;
}   