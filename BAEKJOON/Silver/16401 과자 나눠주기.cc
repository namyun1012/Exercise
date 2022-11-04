#include <iostream>
#include <algorithm>
/*
    모든 조카에게 같은 길이의 막대 과자를 나눠 주어야 함
    나눠주는 길이를 이분 탐색으로 구해서 진행함
    이분 탐색 조건은 공부를 더 해야 할 듯 하다.
*/

long long snacks[1000002];


int main() {
    int m, n;
    std::cin >> m >> n;
    long long result = 0;

    for(int i = 0; i < n; i++) {
        std::cin >> snacks[i];
    }

    std::sort(snacks, snacks + n);

    // 나눠줄 수 있는 과자의 길이 1~snacks[n-1]
    long long st = 1;
    long long en = snacks[n-1];

    while(st <=  en) {
        long long mid = (st + en) / 2;
        
        long long temp = 0;
        
        for(int i = 0; i < n; i++) {
            long long snack = snacks[i];
            
            while(snack >= mid) {
                snack -= mid;
                temp++;
            }
        }

        if(temp >= m) { // 과자 조각 수가 조카 수보다 많을 시 길이를 늘려봄
            st = mid + 1;
            result = std::max(result, mid);
        }

        else {
            en = mid - 1;
        }

    }

    std::cout << result;
    return 0;

}