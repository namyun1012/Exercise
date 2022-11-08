#include <iostream>
#include <algorithm>
#include <set>
/*
    두 개의 숫자들의 합을 하나의 배열로 만듬

*/
long long arr[1002];
long long result = 0;
std::set<long long> s;
int main() {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
        s.insert(arr[i]);
    }

    std::sort(arr, arr+n);
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            for(int k = j; k < n ; k++) {
                long long temp = arr[i] + arr[j] + arr[k];
                if(s.find(temp) != s.end()) {
                    result = std::max(result, temp);
                }
            }
        }
    }

    std::cout << result;
}