#include <iostream>
#include <vector>

long long power(int a, int b, int c) {
    
    if(b == 1)
        return a % c;
    
    long long tmp = power(a, b/2, c);

    if(b % 2 == 0)
        return tmp * tmp % c;
    
    return tmp * tmp % c * a % c;
    
}


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int a,b,c;
    std::cin >> a >> b >> c;
    long long result = power(a,b,c);

    std::cout << result;
    return 0;

}