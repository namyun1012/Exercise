#include <iostream>
#include <algorithm>
/*
    이분탐색을 사용?
    가장 긴 증가하는 부분 수열을 구하기 위해서

    1. LIS를 만들 수열을 1개 더 만듬
    2. 만약 더 클 경우에는 리스트에 원소 삽입
    3. 아닐 경우 위치를 찾아내서 그 원소랑 교체
        교체 이유는 하한을 낮춰서 계속 들어갈 수 있게 하기 위해서

    가장 긴 증가하는 부분수열 2와 별 차이 없는 문제인가?

*/
long long arr[1000002];
long long list[1000002];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    // 입력
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    list[0] = arr[0];
    int index = 0; // List의 마지막 index
    for(int i = 1; i < n; i++) {
        if(arr[i] > list[index]) {
            index++;
            list[index] = arr[i];
        }

        else {
            int change_index = (std::lower_bound(list, list + index, arr[i]) - list);
            list[change_index] = arr[i];
        }

    }

   std::cout << index + 1 ;
   return 0;

}