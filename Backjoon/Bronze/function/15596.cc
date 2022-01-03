#include <iostream>
#include <vector>

long long sum(std::vector<int> &a) {
    int total = 0;
    for(auto num : a)
        total += num;
    return total;
}


int main(void) {

    return 0;
}