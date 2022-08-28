#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M; // 나무의 수 N , 가져가려는 길이 M 결과값은 M보다 커도 되나 최대한 작게 적으면 안됨
    int* arr = new int[N];
    
    std::cin >> N >> M;
    for(int i = 0;i < N; i++) {
        std::cin >> arr[i];
    }

    long long start = 0;
    long long end = *(std::max_element(arr, arr+N)); // arr의 원소 중 제일 큰 값
    long long max_result = start; // 우선 최소치
    while(start <= end) {
        long long mid =(start + end)/2; // 각 나무마다 밸 높이의 최대
        long long sum = 0; // 들고 가는 나무 수 총 합
        
        for(int i = 0; i < N; i++) {
            if(arr[i] >= mid)
                sum += (arr[i] - mid);
        }

        if(sum < M) {  // 들고가는 나무량이 총 들고가야 할 나무량 보다 적을 경우 높이를 낮춤
            end = mid - 1;
        }

        else { // 들고 가는 나무량이 많거나 같을 경우 일단은 넣어봄 + 추가로 높이를 높여보고 되는 지 확인
            max_result = std::max(max_result, mid);
            start = mid + 1;
        }

    }

    std::cout << max_result;
    return 0;
}