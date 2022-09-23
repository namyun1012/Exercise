#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
int arr[9];
int visited[9];
std::vector<int> vec;

void bt(int N) {
    if(vec.size() == M) {
        for(auto ele : vec)
            std::cout << ele << " ";
        std::cout << "\n";
        return ;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        vec.push_back(arr[i]);
        visited[i] = true;
        bt(N);
        vec.pop_back();
        visited[i] = false;
    }
}

int main() {
    
    std::cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
    } 

    std::sort(arr, arr+N);
    bt(N);
    return 0;
}