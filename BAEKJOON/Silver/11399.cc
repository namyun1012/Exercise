#include <iostream>
#include <algorithm>

int time[1003];
int main() {
    int N;
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> time[i];
    }

    std::sort(time, time+N);

    int result = 0;
    int final_result = 0;
    for(int i = 0; i < N; i++) {
        
        result += time[i];
        final_result += result;
    }

    std::cout << final_result;
    return 0;
}