#include <iostream>
#include <set>
#include <algorithm>
std::pair<int, int> jews[300002];
std::multiset<int> backpacks;
/*
    가방엔 최대 1개의 보석만 들어감
    가장 가치가 큰 보석들을 들어가는 것 중 가장 작은 가방에 집어넣기
    set
*/
int main() {
    int n, k;
    std::cin >> n >> k;

    for(int i = 0; i < n; i++) { // M, V
        std::cin >> jews[i].second >> jews[i].first; // 가치가 높은 순으로 확인하기 위해서
    }

    for(int i = 0; i < k; i++) {
        int temp;
        std::cin >> temp;
        backpacks.insert(temp);
    }
    std::sort(jews, jews + n);
    
    long long result = 0;

    for(int i = n - 1; i >= 0; i--) { // 배열이 오름차순으로 되어 있으므로
        int weight = jews[i].second;
        int value = jews[i].first;

        auto it = backpacks.lower_bound(weight); // 위 보석을 수용 가능한 것 중에서 가장 작은 크기의 가방
        if(it == backpacks.end()) continue; // lower_bound 는 못찾을 시 end 를 반환함
        result += value;
        backpacks.erase(it); // 사용한 가방은 삭제

    }

    std::cout << result;
    return 0;
}