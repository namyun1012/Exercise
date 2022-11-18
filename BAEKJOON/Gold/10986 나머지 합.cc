#include <iostream>

long long arr[10000006];
long long sum[10000006];
int remainder[1002];
/*
    n^2 사용시 바로 시간 초과
    누적합 구하는 식을 따로 알아봐야 할 듯
    sum[a] % m == sum[b] % m  일 경우 결과 나옴
    remainder 에 나머지들을 저장
    remainder 들 중에서 2개씩을 뽑아서 중복조합 후 결과 산출
    nH2 = n + 1 C 2
    remainder 0인 경우를 보정해 주어야 함
*/


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    
    long long result = 0;

    int n, m;
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        arr[i] %= m;
    }

    for(int i  = 1; i <= n; i++) {
        sum[i] = (sum[i - 1] % m + arr[i] % m) % m;
        remainder[sum[i]]++;

    }

    // 0일 때를 보정해 주어야 함
    // 나머지가 0인 친구들은 자기 자신만 해도 되기 때문에
    // 이것은 어쩌다가 된 것같고, 원래 맨 마지막 result 에 remainder[0] 을 더해주는 방식이 정확함
    // 그것과 현재 구현한 결과가 결과적으론 같아서 해답이 나온 듯
    // Sum 끼리 하면 자기 자신인 경우들이 빠짐
    remainder[0]++;

    for(int i = 0; i < m; i++) {
        long long temp = remainder[i];
        
        // 조합으로
        result += temp * (temp - 1) / 2;
    }
    
    std::cout << result;

}