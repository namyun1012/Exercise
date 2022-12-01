#include <iostream>
#include <algorithm>
#include <math.h>

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
    
    double result = 0;

    for(int i = 1; i < n-1; i++) {
        double temp = 0;
        /*
            x1y2 - x2y1
        
        */
        temp = ((dots[i+1].second - dots[0].second) * (dots[i].first - dots[0].first)) -
                    ((dots[i].second - dots[0].second) * (dots[i+1].first - dots[0].first));

        result += (temp/2);
    }

    
    
    
    std::cout.precision(1);
    std::cout << std::fixed;
    std::cout << abs(result);

    return 0;
}