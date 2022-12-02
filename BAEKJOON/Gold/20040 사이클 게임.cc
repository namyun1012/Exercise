#include <iostream>
/*
    약간 시간 제한이 빡빡해 보인다.
    union-find 에 대해서 더 상세히 알아보아야 할 듯

*/
int parent[500002];

int getParent(int n) {
    if(parent[n] == n) return n;

    return parent[n] = getParent(parent[n]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a == b) return ;
    
    if(a < b)
        parent[b] = a;
    else    
        parent[a] = b;
}

bool check_union(int a, int b) {
    if(getParent(a) == getParent(b)) return true;
    return false;
}


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;

    int result = 0;
    for(int i = 0; i < n; i++) 
        parent[i] = i;

    for(int i = 1; i <= m; i++) {
        int fromV, toV;
        std::cin >> fromV >> toV;
        
        if(check_union(fromV, toV) && result == 0) {
            result = i;
        }
        unionParent(fromV, toV);

    }

    std::cout << result;
    return 0;
}