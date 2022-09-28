#include <iostream>
#include <algorithm>
#include <cmath>

// 0에 가까운 값으로
int arr[100002];


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int N;
    std::cin >> N;
    std::pair<int, int> result;

    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr, arr+N);
    
    int st = 0;
    int en = N-1;
    int count = N; // 계산 수가 N을 넘지는 않음
    int min = 2e9 + 5;
    
    int sum;
    while(st < en) {
        sum = arr[st] + arr[en];
        
        if(abs(sum) < abs(min)) {
            result.first = arr[st];
            result.second = arr[en];
            min = sum;
        }

        if(sum > 0) en--; 
        else st++;

    }
    
    std::cout << result.first << " " << result.second;
    return 0;
}