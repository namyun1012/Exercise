#include <iostream>
#include <vector>
#include <algorithm>
/** 
*@param vec 벡터임
*@param N 크기

*/
void sort(std::vector<std::pair<int, int>> &vec, int N) {
    for(int i = 0; i < N; i++) {
        for(int j = i; j <N; j++) {
            if(vec[i].first > vec[j].first) {
                std::pair<int, int> temp;
                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }

            else if(vec[i].first == vec[j].first) {
                if(vec[i].second > vec[j].second) {
                    std::pair<int, int> temp;
                    temp = vec[i];
                    vec[i] = vec[j];
                    vec[j] = temp;
                }
            }
        }
    }

}


int main() {
    std::ios::sync_with_stdio(false); // 시간
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> vec;
    for(int i = 0; i < N; i++) {
        int x,y;
        std::cin >> x >> y;
        std::pair<int, int> p = {x, y};
        vec.push_back(p);
    }

    std::sort(vec.begin(), vec.end()); //sort
    for(int i =0; i < N; i++) {
        std::cout << vec[i].first << " " << vec[i].second << "\n";
    }

}