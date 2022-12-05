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

    long long st = 1;
    long long en = n;


    // st, en 을 index 로 써보자
    while (st <= en)
    {
        std::cout << st << " " << en << "\n";
        // 최소 st * en 만큼의 칸 보다는 크거나 같음 
        long long temp = st * en;
        

        if(k > temp) {
            st++;
        }

        else {
            en--;
        }
    }
   
   std::cout << st * en ;
   return 0;

}




