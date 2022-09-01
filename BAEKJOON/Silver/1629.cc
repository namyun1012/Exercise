#include <iostream>
#include <vector>

long long power(int a, int b, int c) {
    long long tmp = 1;

    if(b == 1)
        return a % c;
    

    if(b % 2 == 0)
        return power(a, b/2, c);
    
    return power((a, b/2, c) * a) % c;
    
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