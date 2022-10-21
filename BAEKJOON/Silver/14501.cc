#include <iostream>
#include <algorithm>
#include <vector>
// i랑 time의 구분을 못해서 거의 망함

int t[16];
int p[16];
int visited[16];

int N;
int result = 0;
std::vector<int> vec;

void bt(int time, int sum) {

    result = std::max(result, sum);
    
    for(int i = time; i < N; i++) {
        if(visited[i]) continue;
        if(i + t[i] <= N) {
        
            visited[i] = 1;
            bt(i + t[i], sum + p[i]);
            visited[i] = 0;

        }
    }
}

int main() {
    std::cin >> N;
    
    for(int i = 0; i < N ; i++) {
        std::cin >> t[i] >> p[i];
    }

    bt(0,0);
    std::cout << result;

    return 0;
}