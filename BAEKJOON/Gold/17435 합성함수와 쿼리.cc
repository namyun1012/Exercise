#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
/*
    LCA 생성에 필요한
    sparse table 자료구조임
    log를 사용하므로 약간 생소해서 다 자세히 알아봐야 할 듯
    
*/
int m, Q;
int fx[20][200003];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    cin >> m;
    for(int i = 1; i <= m ; i++) {
        cin >> fx[0][i];
    }

    int len = (int)ceil(log2(500000));

    for(int i = 0; i < len; i++) {
        for(int j = 1; j <= m; j++) {
            fx[i+1][j] = fx[i][fx[i][j]];
        }
    }
    cin >> Q;
    
    while(Q--) {
        int n, x;
        cin >> n >> x;
        
        int index = 0;
        while(n != 0) {
            
            if(n % 2 == 1)
                x = fx[index][x];
        
            n = n >> 1;
            index++;
        }

        cout << x << "\n";
    }

    return 0;
}