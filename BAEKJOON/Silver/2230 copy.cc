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
    int en = 0;
    for(int st = 0; st < N; st++) {
        while(en < N && arr[en] - arr[st] < M) en++;
        if(en == N) break;
        result = std::min(result, arr[en]- arr[st]);
    }
    
    std::cout << result;
    return 0;
}