#include <iostream>


int main() {
    int N, K;
    std::cin >> N >> K;

    int* coins = new int[N];
    for(int i = 0; i < N; i++)
        std::cin >> coins[i];

    int j = N - 1;
    int count = 0;
    while(j >= 0) {
        if(K < coins[j])
            j -= 1;
        else {
            K -= coins[j];
            count ++;
        }
    }
    std::cout << count;
}