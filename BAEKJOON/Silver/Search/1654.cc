#include <iostream>
#include <vector>
#include <algorithm>

int TestCount(std::vector<int> vec, int K, int mid) {
    int result = 0;
    for(int i = 0; i < K; i++){
        result += (vec[i] / mid);
    }
    return result;
}
int main() {
    int K, N;
    std::cin >> K >> N;
    std::vector<int> vec;

    for(int i =0; i < K; i++) {
        int ele;
        
        std::cin >> ele;
        vec.push_back(ele);
    }
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    int start = 1;
    int end = vec.front();
    int mid;
    while(start <= end) {
        mid = (start + end) / 2;
        if(TestCount(vec, K, mid) == N) {
            while(TestCount(vec, K, mid) == N) {
                mid++;
            }
            break;
        }

        if(TestCount(vec, K, mid) > N) start = mid + 1;
        
        else end = mid - 1;


    }

    std::cout << mid-1;
    return 0;
}