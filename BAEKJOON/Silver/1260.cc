#include <iostream>
#include <vector>
#include <stack>
#include <queue>

bool visited[1002];

int main() {
    int N, M, V;
    std::cin >> N >> M >> V;
    std::vector<int> *adj;

    for(int i = 0; i < M; i++) {
        int fromV, toV;
        std::cin >> fromV >> toV;
        adj[fromV].push_back(toV);
    }

    std::stack<int> s;
    visited[1] = true;
    s.push(1);

    while(!s.empty()) {
        
    }
}