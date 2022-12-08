/*
    n log n LIS 문제 풀이 이후에
    index 를 어느 곳에  교체나 추가했는 지를 저장하고 
    
    그것들을 가지고 LIS를 만들면 되는데
    앞에서 부터 순차적으로 진행할 시
    순서가 꼬일 수 있으므로
    뒤에서 부터 진행한다.
*/

// 73 % 가량에서 틀렸다고 나옴
#include <iostream>
#include <algorithm>
#include <vector>
long long arr[1000002];
long long list[1000002];
int save_index[1000002];
std::vector<int> LIS;


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
    save_index[0] = 0;


    int index = 0; // List의 마지막 index
    for(int i = 1; i < n; i++) {
        if(arr[i] > list[index]) {
            index++;
            list[index] = arr[i];
            save_index[i] = index;
        }

        else {
            int change_index = (std::lower_bound(list, list + index, arr[i]) - list);
            list[change_index] = arr[i];
            save_index[i] = change_index;
        }

    }
    int length = index + 1;
    std::cout << length << "\n";

    for(int i = n-1; i >= 0; i--) { // index는 0 ~  n - 1 까지이다.
        if(save_index[i] == index) {
            LIS.push_back(arr[i]);
            index--;
        }
    }

    for(int i = LIS.size() - 1; i >= 0; i--) {
        std::cout << LIS[i] << " ";
    }
   
   
   return 0;

}