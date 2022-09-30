#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>

int lc[27];
int rc[27];
int parent[27];

void preTraverse(int cur) {
    if(cur == 0) return;
    char ch = cur + 'A' -1;
    std::cout << ch;
    
    preTraverse(lc[cur]);
    preTraverse(rc[cur]);
}

void InorderTraverse(int cur) {
    if(cur == 0) return;
    char ch = cur + 'A' -1;
    
    InorderTraverse(lc[cur]);
    std::cout << ch;
    InorderTraverse(rc[cur]);
}

void postOrderTraverse(int cur) {
    if(cur == 0) return;
    char ch = cur + 'A' -1;
    
    postOrderTraverse(lc[cur]);
    postOrderTraverse(rc[cur]);
    std::cout << ch;
    
}

int main() {
    int N;
    std::cin >> N;

    char select_parent;
    char select_lc;
    char select_rc;

    for(int i = 0; i < N; i++) {
        std::cin >> select_parent >> select_lc >> select_rc;
        int real_select = select_parent - 'A' + 1;
        
        if(select_lc != '.') {
            lc[real_select] = select_lc -'A' + 1;
            
        }

        if(select_rc != '.') {
            rc[real_select] = select_rc - 'A' + 1;
        }

    }
   

    
    
    preTraverse(1);
    std::cout << "\n";
    InorderTraverse(1);
    std::cout << "\n";
    postOrderTraverse(1);
    
    return 0;
}