
#include <iostream>
#include <algorithm>
#include <vector>

long long houses[200002];
long long result = 0;

int main() {
    int N, C;
    std::cin >> N >> C;

    for(int i = 0; i < N; i++) {
        std::cin >> houses[i];
    }

    std::sort(houses, houses + N);

    long long st = 1;
    long long en = houses[N-1];

    while(st <= en) { // st + 1, en - 1 일 때는 조건이어야 함
        long long mid = (st + en) / 2; // 공유기를 설치하는 최소 거리 이 거리 이상일 때만 설치 가능
        long long temp = 1; // 공유기 하나는 시작 지점에 무조건 설치 함
        long long router = houses[0]; // 마지막 router를 설치한 장소
        long long index = 0; // 처음 설치된 router의 index는 0


        while(temp <= houses[N-1]) {
            long long temp_length =  router + mid;
            
            index = std::lower_bound(houses + index, houses + N, temp_length) - houses;
            // temp_length 이상일 때 그 에 해당하는 index 반환
            if(index >= N) break; // lower_bound가 크거나 같은 원소를 못 찾았을 때
            /*
                lower_bound 는 해당 값을 못 찾았을 때 end를 반환함;
                그러니까 해당 코드를 index >= N 등으로 전환하면 좋을 듯
            
            */
            
            router = houses[index]; // 마지막 공유기 설치 장소 이동
            temp++; // 설치 개수를 늘림
            
        }

        if(temp >= C) { // 공유기의 개수가 많음 >> 거리를 늘려본다.
            st = mid + 1;
            result = std::max(result, mid);
        }

        else {
            en = mid - 1;
        }
    }

    std::cout << result;
}