#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    int M;

    std::cin >> N >> M;

    std::vector<int> vec;
    

    for(int i = 0; i < N; i++) {
        int ele;
        std::cin >> ele;
        vec.push_back(ele);
    }
    std::sort(vec.begin(), vec.end());
    int result = vec[0] + vec[1] + vec[2];
    std::vector<int> sum_vec;
    for(int i = 0; i < N; i++) {
        for(int j = i+1 ; j < N; j++) {
            for(int k = j+1; k < N; k++)
                sum_vec.push_back(vec[i] + vec[j] + vec[k]);
        }
    }
    std::sort(sum_vec.begin(), sum_vec.end());

    for(auto ele : sum_vec) {
        
        if(ele > M )
            break; 

        result = ele;
    }
    
    std::cout << result;
    return 0;
}