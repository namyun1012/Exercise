#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    if(M > N) {
        int temp = M;
        M = N;
        N = temp;
    }
    int N2 = N;
    int M2 = M;
    int a;

    int R = N % M;
    while(R != 0) {
        N = M;
        M = R;
        R = N % M;
    }
    a = M;
    std::cout << a << "\n";
    std::cout << N2*M2/a;
}