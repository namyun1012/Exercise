#include <iostream>
#include <algorithm>
#include <cmath>
//fabs를 사용했어야 했음
std::pair<double, double> dots[10002];
/*
    공식에 때려놓고 풀기
    다시 한번 식을 봐야 할 듯
*/

int main() {
    int n;
    std::cin >> n;
    

    
    for(int i = 0; i < n; i++) {
        std::cin >> dots[i].first >> dots[i].second;
    }
    dots[n] = dots[0]; 
    double result = 0;
    // 0 ~ n-1 까지
    for(int i = 0; i < n; i++) {
        double temp = 0;
        /*
            x1y2 - x2y1
        */
        temp = dots[i].first * dots[i+1].second - dots[i+1].first * dots[i].second;

        result += (temp/2);
    }

    
    
    // 애초에 소수 둘째 까지 내려갈 일이 안 보임
    std::cout.precision(1);
    std::cout << std::fixed;
    std::cout << fabs(result);

    return 0;
}