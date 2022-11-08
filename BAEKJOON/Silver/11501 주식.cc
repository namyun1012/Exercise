#include <iostream>
#include <algorithm>

int arr[1000002];
/*
    시작 부터 하면 힘듬 2중 for문 사용시 시간 초과
    끝에서 구현하기

*/
int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;

        for(int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        long long result = 0;
        int max = arr[n-1];
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] > max) { // 예전 께 그 이후 것보다 크면 못 팜
                max = arr[i];
            }
        
            else { // 아닌 경우 가능한 최대 치에서 팜
                result += (max - arr[i]);
            }
        }

        std::cout << result << "\n";

    }

    return 0;
}