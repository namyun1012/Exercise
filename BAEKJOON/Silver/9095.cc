#include <iostream>

int arr[13];

int result(int N){
    

    if(N <= 0) return 0;

    else if(arr[N] != 0 || N == 1) return arr[N];

    arr[N] = result(N-1) + result(N-2) + result(N-3);
    return result(N-1) + result(N-2) + result(N-3);
}


int main() {
    arr[1] = 1;
    arr[2] = 2;   // 11
    arr[3] = 4;   // 111 12 21 3
    int N;
    std::cin >> N;

    int K;
    while(N--) {
        std::cin >> K;
        std::cout << result(K) << "\n";
    }

    return 0;
}