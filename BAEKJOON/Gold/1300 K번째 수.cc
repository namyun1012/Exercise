#include <iostream>
#include <algorithm>

/*
    A 나 B 를 따로 저장을 하면 안 될 듯
    일부만 저장할 수 있게

    N = 3일 경우에는
    1,2,2,3,3,4,6,6,9 이런 식으로 감
    N 이 10^5 일 때
    1 ~ 10^10 까지가 탐색 범위임

    A[i][j];

*/
int main() {
    long long n, k;
    std::cin >> n >> k;

    // 기본값
    long long st = 1;
    long long en = n*n;

    // st, en 을 index 로 써보자
    while (st <= en)
    {
        
        long long mid = (st + en)/2;

        /*
            1 ~ n 까지 해서
            mid 밑에 몇 개의 index 가 있는지 확인함        

        */
        long long sum = 0;
        for(long long i = 1; i <= n ;i++) {
            sum += std::min(mid / i, n);
        }
      
        // 인덱스가 K보다 높을 때
        if(sum >= k) {
            en = mid - 1;
    
        }

        else{
            st = mid + 1;
        }
        
    }
   
   std::cout << st;
   return 0;

}




