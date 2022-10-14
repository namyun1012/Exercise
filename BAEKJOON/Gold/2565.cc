#include <iostream>
#include <algorithm>

int arr1[505];
int arr2[505];
int dp[505]; //  arr[i-1] < arr[i]를 만족시키는 가장 긴 수열을 찾고 N에서 빼기

int main() {
    int N;
    std::cin >> N;
    int result = 0;
    int from, to;
    for(int i = 0; i < N; i++) {
        std::cin >> from >> to;
        arr1[from] = to;
        arr2[to] = from;
    }

    for(int i = 1; i <=500; i++) {
        if(arr1[i] == 0) {
            continue;
        }

        for(int j = 1 ; j < i; j++) { // 1~i-1 까지 돌리면서 arr1[i] > arr1[j]를 만족할 때 ㅇ
            if(arr1[j] == 0)
                continue;

            if(arr1[i] > arr1[j]) {
                dp[i] = std::max(dp[j] + 1, dp[i]);
            }

        }

        result = std::max(dp[i], result);
    }

    std::cout << N - result - 1; // 보정용 1
    return 0;
}