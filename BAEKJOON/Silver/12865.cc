#include <iostream>
#include <vector>
#include <algorithm>
struct cmp {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const{
        if(a.first == b.first)
            return a.second > b.second;

        else
            return a.first < b.first;     
    }
};


int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<std::pair<int, int>> vec;
    std::vector<std::pair<int, int>> vec_result;
    for(int i = 0; i <N; i++) {
        int w, v;

        std::cin >> w >> v;
        vec.push_back({w, v});
    }

    int vec_size = vec.size();
    for(int i = 0; i < vec_size; i++)
       vec_result.push_back({(vec[i].first / vec[i].second), vec[i].first});

    std::sort(vec_result.begin(), vec_result.end());

    
        

}