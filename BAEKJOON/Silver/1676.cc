#include <iostream>

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N;
    std::cin >> N;
    long long fac_result = 1;
    int count_2 = 0;
    int count_5 = 0;
    int count = 0;
    for(int i = 1; i <= N; i++) {
        int n = i;
        while( n % 2 == 0 || n % 5 == 0) {
            if(n % 2 == 0) {
                n /= 2;
                count_2++;
            }

            if(n % 5 == 0) {
                n /= 5;
                count_5++;
            }
        }
    }

    while(count_2 > 0 && count_5 > 0) {
        count_2-=1;
        count_5 -=1;
        count++;

    }
    std::cout << count;
    return 0;
}