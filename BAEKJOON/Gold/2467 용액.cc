#include <iostream>
#include <algorithm>
#include <cmath>
/*
    투포인터
*/
long long arr[100002];

int main() {
    long long n;
    std::cin >> n;

    long long result = 1e18;
    std::pair<long long, long long> result_pair;
    
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    long long st = 0;
    long long en = n-1;

    while(st < en) {
        long long temp = arr[st] + arr[en];
        

        if(result > abs(temp)) {
            result = abs(temp);
            result_pair = {st, en};
        }


        if(temp < 0) {
            st++;
        }

        else{
            en--;
        }

    }

    std::cout << arr[result_pair.first] << " " << arr[result_pair.second];
    return 0;

}