#include <iostream>
#include <vector>
#include <algorithm>

int TestCount(std::vector<long long> vec, int K, int mid) {
    long long result = 0;
    for(int i = 0; i < K; i++){
        result += (vec[i] / mid);
    }
    return result;
}
int main() {
    long long K, N;
    std::cin >> K >> N;
    std::vector<long long> vec;
    long long sum = 0;
    for(int i =0; i < K; i++) {
        long long ele;
        
        std::cin >> ele;
        sum += ele;
        vec.push_back(ele);
    }
    std::sort(vec.begin(), vec.end(), std::greater<long long>());

    long long start = 1;
    long long end = vec.front();
    long long mid;
    long long result = 1;
    while(start <= end) {
        mid = (start + end) / 2;
        /*if(TestCount(vec, K, mid) == N) {
            while(TestCount(vec, K, mid) == N) {
                if(TestCount(vec, K, mid+1) != N)
                    break;
                mid++;
            }
            break;
        }*/

        if(TestCount(vec, K, mid) >= N) {  
            
            start = mid + 1;
            result = std::max(mid, result);
        }
        else if(TestCount(vec, K, mid) < N) end = mid - 1;


    }

    std::cout << result;
    return 0;
}

/*  계산 결과가 N을 초과하더라도 어쨋든 N개를 만들 수는 있다.
5 3000
4211
1865
7236
9000
12 일 경우 73 >> 304개 나옴

74일 경우
>> 299개가 나오므로
73이 최대다

그러므로 정확하게 N개가 나오지 않는 경우를 고려해야 하므로
N개를 넘었을 경우에도 result 값에는 고려를 해주어야 한다.
*/