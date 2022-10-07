#include <iostream>
//union_find 학습

int parent[1000002];

int getParent(int node) { // parent를 찾기 위해 재귀
    if(parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}

void union_p(int x, int y) { // 합칠 때 더 작은 쪽으로 합침
    x = getParent(x);
    y = getParent(y);
    if(x < y) parent[y] = x;
    else parent[x] = y;
}

bool find_p(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if(x == y) return true;
    else return false;
}

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    for(int i = 0; i <= n ; i++)
        parent[i] = i;
    
    int order, x, y;
    while(m--) {
        std::cin >> order;
        std::cin >> x >> y;
        if(order == 0) {
            union_p(x,y);
        }

        else if(order ==1) {
            if(find_p(x,y)) {
                std::cout << "YES" << "\n";
            }

            else std::cout <<"NO" <<"\n";
        }
    }

    return 0;
}