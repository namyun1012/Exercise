#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
/*
    두 개의 숫자들의 합을 하나의 배열로 만듬
    a+b+c = K
    a+b = K - C
*/

long long arr[1002];
std::vector<long long> sum_arr; // 두 개의 숫자들의 합

int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    std::sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) // x,y,z, 가 같아도 됨
            sum_arr.push_back(arr[i] + arr[j]);
    }
    
    std::sort(sum_arr.begin(), sum_arr.end());
    
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(std::binary_search(sum_arr.begin(), sum_arr.end(), arr[i] - arr[j])) { // a+b = K- C
                std::cout << arr[i];
                exit(0);

            }
        }
    }
    return 0;
}