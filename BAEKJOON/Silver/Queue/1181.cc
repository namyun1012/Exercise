#include <iostream>
#include <queue>
#include <string>
#include <vector>
bool check_function(std::pair<int, std::string> pr, std::pair<int, std::string> pr2) {
    if(pr.first > pr2.first)
        return pr.first < pr2.first;

    else if(pr.first == pr2.first) {
        if(pr.second > pr2.second)
            return pr.second < pr2.second;

        else
            return pr.second > pr2.second;

    }

    else
        return pr.second < pr2.second;
}


int main() {
    int N;
    std::cin >> N;

    std::priority_queue<std::pair<int, std::string>> pq;
    std::vector<std::string> str_vec;
    std::string test;

    for(int i = 0; i < N; i++) {
        std::pair<int, std::string> pr;
        std::cin >> pr.second;
        pr.first = pr.second.size();
        pq.push(pr);
    }

    for(int i = 0; i < N; i++) {
        std::pair<int, std::string> pr = pq.top();
        
        str_vec.push_back(pr.second);
        pq.pop();
    }

    
    test = str_vec[str_vec.size()-1];
    std::cout << test << "\n";
    for(int i = str_vec.size()-1; i >= 0; i-=1) {
        if(str_vec[i] != test && i < str_vec.size()-1) {
            std::cout << str_vec[i] << "\n";
            test = str_vec[i];
        }
    }
    return 0;
}