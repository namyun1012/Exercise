#include <iostream>

int main() {
    int T = 0;
    std::cin >> T;
    int* a = new int[T];
    int *b = new int[T];
    for(int i = 0; i < T; i++) {
        std::cin >> a[i] >> b[i];
    }

    for(int i =0; i < T; i++)
        std::cout << a[i]+b[i] << std::endl;
    
    return 0;
}