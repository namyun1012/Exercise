#include <iostream>
#include <algorithm>

#define INF 1e9
int dis[102][102];

int main() {
    int v,e;
    std::cin >> v >> e;

    std::fill(&dis[0][0], &dis[101][101], INF);
    
    int startV, toV, weight;
    for(int i = 0; i < e ; i++) {
        std::cin >> startV >> toV >> weight;
        dis[startV][toV] =std::min(weight, dis[startV][toV]);

    }

    //d[s][t] = d[s][1] + d[t][1];

    for(int i = 1; i <= v; i++) {
        dis[i][i] = 0;
    }

    for(int k = 1; k <= v; k++) {
        for(int i = 1; i <= v; i++) {
            for(int j = 1; j <= v; j++)
                dis[i][j] = std::min(dis[i][k] + dis[k][j], dis[i][j]);

        }
    }
    
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            if(dis[i][j] == INF) std::cout << 0 << " ";
            else std::cout << dis[i][j] << " ";
        }
        std::cout << "\n";
    }
}