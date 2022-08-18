#include <iostream>
#define MAX 30

bool check[MAX]= {false};
int num[MAX] = {0,1,1};

int Fibonacci(int N) {
    if(check[N]) return num[N];
    if(N == 0) return 0;
    if(N == 1) return 1;
    if(N == 2) return 1;

    int ans = Fibonacci(N-1) + Fibonacci(N-2);
    check[N] = true;
    num[N] = ans;
    return ans;

}


int main() {
    int N;
    std::cin >> N;
    std::cout << Fibonacci(N);


    return 0;
}