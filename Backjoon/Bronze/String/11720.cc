#include <iostream>

int main() {
    int N;
    std::cin >> N;
    char* str = new char[N];
    std::cin >> str;
    
    int total = 0;
    for(int i = 0; i < N; i++)
        total += (str[i] - '0');

    std::cout << total;


    return 0;
}