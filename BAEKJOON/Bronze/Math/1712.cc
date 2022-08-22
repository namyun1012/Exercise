#include <iostream>


int main() {
    long A, B, C;

    std::cin >> A >> B >> C;

    long count = 0;

    if(B >= C) {
        std::cout << "-1" << std::endl;
        return 0;
    }


    count = A /(C - B) + 1;

    std::cout << count << std::endl;
    return 0;
}