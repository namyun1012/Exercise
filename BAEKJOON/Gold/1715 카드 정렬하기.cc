#include <iostream>
#include <queue>

int arr[100002];
/*
    알고리즘 알아서 날먹
    낮은 순서대로 진행하면 됨 이유 : 낮은 것들을 여러분 합하는 것이 높은 것을 여러 번 합하는 것보다 적음
    파일 합치기 11066 과 다른 점 그 쪽은 순서가 있어서 dp로 해결이 필요했음
*/

int main() {
    std::priority_queue<int,
                        std::vector<int>,
                        std::greater<int> > pq;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
        pq.push(arr[i]);
    }

    long long result = 0;
    while(pq.size() >= 2) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a+b);
        result += (a+b);
    }

    std::cout << result;
    return 0;
}