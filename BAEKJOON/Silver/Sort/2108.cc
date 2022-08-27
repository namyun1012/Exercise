#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

struct cmp {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const{
        if(a.first == b.first)
            return a.second < b.second; // 내림차순

        else
            return a.first > b.first;  // 오름차순      
    }
};


int main() {
    int N;
    std::cin >> N;
    std::vector<int> vec;

    for(int i = 0; i < N; i++) {
        int ele;
        std::cin >> ele;
        vec.push_back(ele);
    }
    std::sort(vec.begin(), vec.end());

    //1 산술평균
    float sum = 0;
    for(auto ele : vec)
        sum += ele;
    
    std::cout << floor(sum / vec.size() + 0.5) << std::endl;

    //2 중앙값
    std::cout << vec[(vec.size()/2)] << std::endl;

    //3 최빈값
    std::set<std::pair<int ,int>,cmp> check_set;

    for(int ele : vec) {
        check_set.insert({0, ele});
    }

    for(int ele : vec) {
        for(std::pair<int, int> pairs : check_set) {
            if(ele == pairs.second) {
                std::pair<int, int> new_pair = {pairs.first+1, ele};
                check_set.insert(new_pair);
                break;
            }
        }
    }
    
    int check_num = (*check_set.begin()).first;
    std::vector<int> check_vec;
    for(std::pair<int, int> ele : check_set) {
        if(check_num == ele.first) {
            check_vec.push_back(ele.second);
        }
    }

    if(check_vec.size() == 1) std::cout << check_vec[0] << "\n";
    else std::cout << check_vec[1] << "\n";
    
    //4 범위
    int result = vec[vec.size()-1] - vec[0];
    std::cout << result << "\n";
    return 0;
}