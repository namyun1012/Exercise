#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//tree, 노드 간의 최장 경로

std::vector<std::pair<int, int>> adj[10003];

int result = 0;

int main() {
    int n;
    std::cin >> n;

    int fromV, toV, weight;
    for(int i = 0; i < n-1; i++) {
        std::cin >> fromV >> toV >> weight;
        adj[fromV].push_back({weight, toV});

    }


    std::priority_queue<std::pair<int, int>> pq;

    

}