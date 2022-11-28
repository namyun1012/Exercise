#include <iostream>
#include <string>
#include <map>
int parent[200004];
int size[200004];
/*
    Union Find 이해하기
    친구 관계가 최대 100000이니
    친구는 최대 200000 까지는 가능함
*/

int find(int x) {
    if(parent[x] == x) return x;
    else {
        return find(parent[x]);
    }


}
void union_parent(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return ;

    parent[b] = a;
    size[a] += size[b]; // size 계산
}



int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while(t--) {
        
        int n;
        std::cin >> n;
        std::map<std::string, int> m;

        for(int i = 1; i <= 200002 ; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        int index = 1;
        for(int i = 1; i <= n; i++) {
            std::string temp1, temp2;
            std::cin >> temp1 >> temp2;
            if(m[temp1] == 0) {
                m[temp1] = index;
                index++;
            }

            if(m[temp2] == 0) {
                m[temp2] = index;
                index++;
            }
            
            union_parent(m[temp1], m[temp2]);
            std::cout << size[find(m[temp1])] << "\n";
        }
    }

    return 0;
}