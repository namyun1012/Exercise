#include <iostream>

int factorial(int n) {

    long result = 1;    

    for(int i = 1; i <= n; i++)
        result *= i;
    return result;
}


int main() {
    int N;
    std::cin >> N;
    std::cout << factorial(N) << std::endl;

}