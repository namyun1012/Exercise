#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

long long list[1000002];
int save_index[1000002];
std::vector<int> LIS;
std::vector<int> not_LIS;

std::map<int, int> m;

/*
    14003 번의 변형문제
    LIS가 아닌 것을 출력하는 것이 차이점이 있고,
    그리고 A -> B 의 LIS를 찾아야 했고, A의 모든 배열이 채워져 있는 것이 아니라서 
    가장 형태에 잘 맞은 map 을 사용함
*/


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    // 입력
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        int fromV, toV;
        std::cin >> fromV >> toV;
        m[fromV] = toV;
    }

    std::map<int, int>::iterator it = m.begin();
    
    list[0] = it->second; 
    save_index[0] = 0;
    

    int index = 0; // List의 마지막 index
    for(int i = 1; i < n; i++) {
        it++;
        
        if(it->second > list[index]) {
            index++;
            list[index] = it->second;
            save_index[i] = index;
        }

        else {
            int change_index = (std::lower_bound(list, list + index, it->second) - list);
            list[change_index] = it->second;
            save_index[i] = change_index;
        }

    }

    int length = index + 1;
    std::cout << n - length << "\n";
    
    it = m.end();


    for(int i = n-1; i >= 0; i--) { // index는 0 ~  n - 1 까지이다.
        it--;
        if(save_index[i] == index) {
            LIS.push_back(it->first);
            index--;
        }

        else {
            not_LIS.push_back(it->first);
        }
    }

    for(int i = not_LIS.size() - 1; i >= 0; i--) {
        std::cout << not_LIS[i] << "\n";
    }
   
   
   return 0;

}