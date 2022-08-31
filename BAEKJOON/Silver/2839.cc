#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    int min_ele = N;

    for(int i = 0; i <= (N/3); i++) {
        int ele = N;
        int num = 0;
        int j = i;
        while(j && ele >= 5) {
            num++;
            ele -= 5;
            j--;
        }

        while(ele >= 3) {
            num++;
            ele -= 3;
        }
        
        if(ele != 0)
            continue;

        if(min_ele > num)
            min_ele = num;
    }
    if(min_ele == N)
        min_ele = -1;

    std::cout << min_ele;
    return 0;
}