#include <iostream>

void Hanoi(int n, int a, int b, int c) {  // a = 1 b = 3 c = 2 fr, to, x

    if(n <= 1) { 
        printf("%d %d\n", a,b);
        return; //가로 치기
    }


    Hanoi(n-1, a, c ,b);
    printf("%d %d\n", a,b);
    Hanoi(n-1, c, b, a);

}

int Hanoi_count(int n) {
    if(n ==1) return 1;
    int ans = 2*Hanoi_count(n-1) + 1;
    return ans;
}

int main() {
    int N;
    std::cin >> N;
    std::cout << Hanoi_count(N) << std::endl;
    Hanoi(N,1,3,2);
    return 0;

}