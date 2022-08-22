#include <iostream>
#include <vector>

int d(int n) {
    return n + n/1000 + n/100 + n/10 + n%10;
}



int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, 97};
    std::vector<int> vec2;
    for(int i = 100; i <= 10000; i++)
        vec2.push_back(i);

    




    for(auto i : vec)
        std::cout << i << std::endl;
}
