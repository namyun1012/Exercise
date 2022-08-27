#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


int arr[8001] = {0, };
int main() {
    int N;
    std::cin >> N;
    std::vector<int> vec;

    for(int i = 0; i < N; i++) {
        int ele;
        std::cin >> ele;
        vec.push_back(ele);
        if(ele < 0) arr[4000 - ele]++; // 0 ~ -4000
        else arr[ele]++;
    }
    std::sort(vec.begin(), vec.end());

    //1 산술평균
    double sum = 0;
    for(int i = 0; i <= N; i++)
        sum += vec[i];
    
    std::cout << round(sum /vec.size()) << std::endl;

    //2 중앙값
    std::cout << vec[(vec.size()/2)] << std::endl;

    //3 최빈값
    std::vector<int> check_vec;
    int max = 0;
    for(int i = 0; i < 8001; i++) {
        
        if(arr[i] == 0)
            continue;
        
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    
    for(int i = 0; i < 8001; i++) {
        
        if(arr[i] == 0)
            continue;
        
     
        if(arr[i] == max) 
            check_vec.push_back(i);
    
    }

    for(int i = 0; i < check_vec.size(); i++) {
        if(check_vec[i] > 4000)
            check_vec[i] = 4000 - check_vec[i];
    }
    
    std::sort(check_vec.begin(), check_vec.end());
    
    if(check_vec.size() == 1)
        std::cout << check_vec[0] << "\n";
    
    else if(check_vec.size() > 1)
        std::cout << check_vec[1] << "\n";
    
    else
        return 0;

    //4 범위
    int result = vec[vec.size()-1] - vec[0];
    std::cout << result << "\n";
    return 0;
}