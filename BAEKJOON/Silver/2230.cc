#include <iostream>
#include <algorithm>

#define INT_MAX 2000000000
int arr[100002];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int N, M;
    std::cin >> N >> M;
    
    int result = INT_MAX;
    int prev_result = result;

    for(int i = 0; i < N; i++)
        std::cin >> arr[i];
    
    std::sort(arr, arr+N);
    //sort
    for(int i = 0; i < N; i++) {
        result = std::min((*std::lower_bound(arr, arr + N, arr[i] + M)) - arr[i], result);
        if(result < M) result = prev_result;
        else prev_result = result;
    }

    // lower_bound :: 해당 값 이상이 최초로 나올 때의 it 반환, 그러므로 arr[i] + M 을 조회하게 함, M의 최솟값을 찾음
    // m보다 작은 경우에는 이전 값으로 다시 변경

    std::cout << result;
    return 0;
}