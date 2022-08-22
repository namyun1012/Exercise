#include <iostream>
#include <vector>

int count_1 = 0;
int count_2 = 0;

int fib(int n) {
    
    if(n == 1 || n ==2) {count_1++; return 1;}

    else return (fib(n-1) + fib(n-2));

}

int fibonacci(int n, int *vec) {
    
    for(int i = 3; i <= n; i++) {
        vec[i] = vec[i-1] + vec[i-2];
        count_2++;
    }
    return vec[n];

}

int main() {
    int N;
    std::cin >> N;
    int vec[40] = {0,1,1};
    int a;
    int b;
    
    a = fib(N);
    b = fibonacci(N, vec);
    std::cout << count_1 << " " << count_2;
    return 0;
}