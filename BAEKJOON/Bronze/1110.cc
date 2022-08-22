#include <iostream>

int main() {
    int N, M;

    std::cin >> N;
    
    int a,b,c;
    M = N;
    int number = 0;
    
    while(true) {
        a = M/10;  //십의 자리
        b = M%10; //일의 자리
        c = a+b;

        if(c>9)
            c = c%10;

        M = b*10 + c;
        number++;
        if(M == N)
            break;
    }
    
    std::cout << number;
    return 0;
}