#include <iostream>
#include <algorithm>

int arr[500002];
int reward_arr[500002];
int result_arr[500002];

int main() {
    int N, M;
    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::cin >> M;
    for(int i = 0; i < M; i++) {
        std::cin >> reward_arr[i];
    }

    std::sort(arr, arr+N);

    for(int i = 0; i < M; i++) {
        int t = reward_arr[i];
        std::cout << std::upper_bound(arr, arr+N, t) - std::lower_bound(arr,arr+N,t) << " ";
    }
    return 0;
}