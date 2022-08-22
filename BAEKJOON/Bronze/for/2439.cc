#include <iostream>

int main() {
    int N;
    std::cin >> N;
    for(int i = 1; i <= N; i++) {
        int M = N-i;
        for(int j = 1; j <= M; j++)
            std::cout << " ";
        for(int j = 1; j <= i; j++)
            std::cout << "*";
        std::cout << std::endl;
    }

    return 0;
}