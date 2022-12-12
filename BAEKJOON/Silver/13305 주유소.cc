#include <iostream>
#include <algorithm>
// Greedy
int n;
long long cities[100002];
long long road[100002];


int main() {
    std::cin >> n;
    for(int i = 0; i < n - 1; i++) {
        std::cin >> road[i];
    }

    for(int i = 0; i < n; i++) {
        std::cin >> cities[i];
    }
    //n = 2 city 0 - road 0 - city 1 - road 1 - city 2
    int cur = 0;
    int en = n - 1;
    long long cost = 0;
    while(cur < en) {
        long long cur_oil = cities[cur];
        cost += (cur_oil * road[cur]);
        
        while(cur < en) {
            int nxt = cur + 1;
            long long nxt_oil = cities[nxt];
            
            // 지금의 기름값이 현재의 기름값보다 클 경우는 무시
            if(cur_oil > nxt_oil) break;
            cur++;
            cost += (cur_oil * road[cur]);
        }
        cur++;
    }
    
    std::cout << cost;
    return 0;
}