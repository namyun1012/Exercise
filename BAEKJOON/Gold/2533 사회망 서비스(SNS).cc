#include <iostream>
#include <vector>
#include <algorithm>
/*
    tree DP를 활용하는 문제
    BFS로도 가능할 듯?
*/
using namespace std;

vector<int> adj[1000002];
int visited[1000002];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int fromV, toV;
        cin >> fromV >> toV;
        adj[fromV].push_back(toV);
        adj[toV].push_back(fromV);
    }

}

