#include <iostream>
#include <queue>
#include <algorithm>
/*
    최대 힙에는 최소 힙보다 작은 원소를 집어넣음
    최소 힙에는 최대 힙보다 큰 원소를 집어넣음
    나중에 다시 한번 생각 방향은 맞는 듯 함
*/
std::priority_queue<int> pq_max; // 최대 힙
std::priority_queue<int,
                    std::vector<int>,
                    std::greater<int>> pq_min; // 최소 힙


int main() {
    int n;
    std::cin >> n;
    while(n--) {
        int ele;
        std::cin >> ele;



        if(pq_max.top() > ele) {
            pq_max.push(ele);
        
    }


}