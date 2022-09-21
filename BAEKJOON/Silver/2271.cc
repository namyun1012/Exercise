#include <iostream>
#include <algorithm>

int ropes[100002];
int main() {
    int N;
    std::cin >> N;
    int result = 0;

    for(int i = 0; i < N; i++)
        std::cin >> ropes[i];

    std::sort(ropes, ropes+N);

    for(int i = 0; i < N; i++) {
        result = std::max(result, ropes[i]*(N-i));
    }

    std::cout << result;
    return 0;
}