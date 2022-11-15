#include <iostream>
#include <algorithm>
#define INF 1e9

int distance[402][402];
/*
    최소 길이의 사이클을 구하는 문제
    플로이드 워셜을 2번 돌려서 정답

*/
int main() {
    int result = INF;
    int v, e;
    std::cin >> v >> e;

    std::fill(&distance[0][0], &distance[401][401] + 1, INF);

    for(int i = 0; i < e; i++) {
        int fromV, toV, weight;
        std::cin >> fromV >> toV >> weight;
        distance[fromV][toV] = weight;
    }

    for(int i = 1; i <= v; i++) {
        distance[i][i] = 0;
    }

    for(int k = 1; k <= v; k++) {
        for(int i = 1; i <= v; i++) {
            for(int j = 1; j <= v; j++) {
                distance[i][j] = std::min(distance[i][k] + distance[k][j] , distance[i][j]);
            }
        }
    }
    /* First Floyd 
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            std::cout << distance[i][j] << " ";
        }
        std::cout << "\n";
    }
    */

   // 두 번째 진행 , 자기 자신까지의 거리는 모름으로 설정
    for(int i = 1; i <= v; i++) {
        distance[i][i] = INF;
    }

    for(int k = 1; k <= v; k++) {
        for(int i = 1; i <= v; i++) {
            for(int j = 1; j <= v; j++) {
                distance[i][j] = std::min(distance[i][k] + distance[k][j] , distance[i][j]);
            }
        }
    }
    /*
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            std::cout << distance[i][j] << " ";
        }
        std::cout << "\n";
    }
    */
    for(int i = 1; i <= v; i++)
        result = std::min(result, distance[i][i]);
    if(result == INF) result = -1;
    std::cout << result;
    return 0;

}