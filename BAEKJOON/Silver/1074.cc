#include <iostream>
#include <math.h>
int count = 0;

void search(int N, int r, int c) {

    if(N == 0)
        return ;

    int tmp = 1 << (N-1); // 2^(N-1) 비트마스킹 기법 사용
    if(r >= tmp && c >= tmp) {
        r-=tmp; c-=tmp;
        count += tmp*tmp*3;
        search(N-1, r, c);
    }

    else if(r >= tmp && c < tmp) {
        r-=tmp;
        count += tmp*tmp*2;
        search(N-1, r, c);
    }

    else if(r < tmp && c >= tmp) {
        c-=tmp;
        count += tmp*tmp;
        search(N-1, r, c);
    }

    else 
        search(N-1, r, c);
}


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int N, r, c; 
    std::cin >> N >> r >> c;
    search(N,r,c);
    std::cout << count;
    return 0;

}