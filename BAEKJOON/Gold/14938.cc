#include <iostream>
#include <algorithm>
#define INF 1e9
int dis[102][102];
int items[102];


int main() {
    std::fill(&dis[0][0], &dis[101][101], INF);

    int result = 0;
    int n,m,r; // 최대 m 까지의 거리만 갈 수 있음
    std::cin >> n >> m >> r;
    for(int i = 1; i <=n ;i++) {
        std::cin >> items[i];
    }

    for(int i = 0; i < r; i++) {
        int fromV, toV, weight;
        std::cin >> fromV >> toV >> weight;
        dis[fromV][toV] = weight;
        dis[toV][fromV] = weight;
  
    }
    
    

    for(int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }


    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        int temp = 0;
        for(int j =1; j <= n; j++) {
            if(dis[i][j] > m) continue;
            temp += items[j];
        }

        result = std::max(temp, result);
    }


    std::cout << result;
    
    return 0;


}