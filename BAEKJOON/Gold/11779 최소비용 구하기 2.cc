#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#define INF 1e9

using namespace std;
/*
    1. 역추적 사용해 보기
    메모리 초과?
    동적 할당 써야 풀림
*/

int n, m;
int st, en;
vector<int> result_vec;
int dis[1001];
int prev_adj[1001];


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    cin >> n >> m;
    vector<pair<int, int>> *adj = new vector<pair<int, int>>[n+1];
    
    for(int i = 0; i < m; i++) {
        int fromV, toV, weight;
        cin >> fromV >> toV >> weight;
        adj[fromV].push_back({weight, toV});
    }

    cin >> st >> en;
   
    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>> > pq;
    
    fill(dis, dis + n + 1, INF);
    
    // 다익스트라 시작
    dis[st] = 0;
    prev_adj[st] = -1;

    pq.push({0, st});

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(dis[cur.second] < cur.first) continue;
        for(auto nxt : adj[cur.second]) {
            if(dis[cur.second] + nxt.first >= dis[nxt.second]) continue;
            dis[nxt.second] = dis[cur.second] + nxt.first;
            pq.push({dis[cur.second] + nxt.first, nxt.second});
            prev_adj[nxt.second] = cur.second;
        }
    }

    int temp = en;
    while(temp != -1) {
        result_vec.push_back(temp);
        temp = prev_adj[temp];
    } 

    cout << dis[en] << "\n" << result_vec.size() << "\n";
    for(int i = result_vec.size() - 1; i >= 0; i--) {
        cout << result_vec[i] << " ";
    }
    
    return 0;

}