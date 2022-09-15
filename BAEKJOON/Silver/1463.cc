#include <iostream> // use greedy


int main() {
    int N;
    int count = 0;
    std::cin >> N;

    while(N != 1) {
        if(N % 3 == 0) 
            N /= 3;
        
        else if(N % 3 == 1)
            N-=1;
        
        else if(N % 2 == 0)
            N /= 2;

        else 
            N-=1;
        count++;
    }
    std::cout << count;
    return 0;
}