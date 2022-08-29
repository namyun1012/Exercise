#include <iostream>
#include <algorithm>
#include <string>

char str_to_int[15];

int main() {
    int N;
    std::cin >> N;

    int min_ele = N;

    for(int i = 1; i < N; i++) {
        int ele = i;
        int sum = ele;
        std::string str = std::to_string(ele);
        for(int j = 0; j < str.size(); j++)
            sum += (str[j] - '0');
        
        if(sum == N) {
            if(min_ele > i)
                min_ele = i;
        }
    }

    if(min_ele == N)
        min_ele = 0;

    std::cout << min_ele;
    return 0;
}