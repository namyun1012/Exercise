#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
#include <math.h>
using namespace std;

int n, m;
/*
    그냥 길이다 일일이 구하고 크루스칼 알고리즘 진행하면 됨
    프림은 까다로울 것 같아서 크루스칼로 진행함
    프림으로 진행했으면 거리값을 서로 연결되어있는 부분은 0으로 하는 것도 좋았을 듯
*/
pair<int, int> gods[1002];

int parent[1002];
int union_size[1002];
vector<tuple<double, double, double>> edges;

double dis(double xa,double xb, double ya, double yb) {
    return sqrt(pow((xa-xb),2) + pow((ya-yb), 2));
}

int find(int x) {
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) { 
        parent[y] = x;
    }
}

bool sameparent(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return true;
    else return false;
}

int main() {
    // 초기 입력
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> gods[i].first >> gods[i].second;
      
    }

    // Kruscal Algorithm 사용
    // 이미 합쳐놓음
    for(int i = 0; i < m; i++) {
        int st, en;
        cin >> st >> en;
        Union(st-1, en-1);
    }


    // 거리 값들 구해 놓기
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            edges.push_back({dis(gods[i].first, gods[j].first, gods[i].second, gods[j].second), i, j});
        }
    }
    


    sort(edges.begin(), edges.end());

    double ans = 0;

    for(int i = 0; i < edges.size(); i++) {
        int a,b;
        double cost;
        tie(cost, a, b) = edges[i];
        
        if(sameparent(a,b)) continue;
        Union(a, b);
        ans += cost;

    }
    
    printf("%.2f", ans);
    return 0;
}
