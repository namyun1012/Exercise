#include <iostream>
#include <queue>
#include <algorithm>
/*
    최대 힙에는 최소 힙보다 작은 원소를 집어넣음
    최소 힙에는 최대 힙보다 큰 원소를 집어넣음
    나중에 다시 한번 생각 방향은 맞는 듯 함
    양 쪽 우선순위 큐를 관리하는 문제

*/
std::priority_queue<int> pq_max; // 최대 힙
std::priority_queue<int,
                    std::vector<int>,
                    std::greater<int>> pq_min; // 최소 힙


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int n;
    std::cin >> n;
    while(n--) {
        int ele;
        std::cin >> ele;

        // 처음에
        if(pq_max.empty()) {
            pq_max.push(ele);
                
        }

        else {

        if(ele > pq_max.top()) {
            pq_min.push(ele);
        } else {
            pq_max.push(ele);
        }


        // 크기의 균형을 맞추기 위해서 
        // 홀 수 일 때 pq_max가 1 큼
        // 짝 수 일 때는 같음 (어처피 작은 것을 내보내야함)
        if(pq_max.size() < pq_min.size()) {
            int temp = pq_min.top();
            pq_min.pop();
            pq_max.push(temp);
        }

        if(pq_max.size() > pq_min.size() + 1) {
            int temp = pq_max.top();
            pq_max.pop();
            pq_min.push(temp);
        }
        }

        
        std::cout << pq_max.top() << "\n";
    }
    return 0;
}