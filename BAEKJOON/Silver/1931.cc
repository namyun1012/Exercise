#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::pair<int ,int> arr[100002];
// 가능한 회의 중 가장 빨리 끝나는 것을 선정
int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    
    int N;
    std::cin >> N;
   
    for(int i = 0; i < N; i++) // <끝나는 시간, 시작 시간>
        std::cin >> arr[i].second >> arr[i].first; // 끝나는 시간 순서대로 정렬해서 들어옴
    std::sort(arr, arr+N);

    int count = 0;
    int time = 0;

    for(int i = 0; i < N; i++) {
        if(time > arr[i].second) continue; // time 이 시작 시간보다큰 경우 안됨
        count++; // 아닐 경우에는 바로 ㄱ
        time = arr[i].first;
    }
    
    std::cout << count;
    return 0;
}