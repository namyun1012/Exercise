#include <iostream>

int main() {
    int N,K;
    std::cin >> N >> K;
    int count = 0;
    
    while(N != K) {
        if( K > N*2) {
            N *=2;
            count++;
        }

        else if(K > N) {
            N++;
            count++;
        }

        else {
            N-=1;
            count++;
        }
    }

    std::cout << count;
}