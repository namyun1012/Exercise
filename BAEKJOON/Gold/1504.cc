#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1e9

int dis[1002][1002];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int n, e;
    std::cin >> n >> e;
    std::fill(&dis[0][0], &dis[1001][1001], INF);
    
    int u, v,w;
    for(int i = 0; i < e; i++) {
        std::cin >> u >> v >> w;
        dis[u][v] = w;
        dis[v][u] = w;
    }    
    
    int v1, v2;
    std::cin >> v1 >> v2;

    

    for(int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                dis[i][j] = std::min(dis[i][k] + dis[k][j], dis[i][j]);
        }
    
    }
    int result = INF;

    if(dis[1][v1] < INF || dis[v1][v2] < INF || dis[v2][n] < INF) {
        result = dis[1][v1] + dis[v1][v2] + dis[v2][n];
        
    }
    
    if(dis[1][v2] < INF || dis[v2][v1] < INF || dis[v1][n] < INF) {
        result = std::min(result, dis[1][v2] + dis[v2][v1] + dis[v1][n]);
       
    }

    
    if(result >= INF) result = -1;
    std::cout << result;
    return 0;
}