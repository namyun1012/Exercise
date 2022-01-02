#include <iostream>

int main(void) {
    int N, X;
    

    std::cin >> N >> X;
    int *A = new int[N];

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        if(A[i] < X)
            std::cout << A[i] << " ";
    }

    delete[] A;
    
    return 0;
}