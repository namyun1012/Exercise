#include <iostream>
#include <vector>

int visited[16];
int visited2[33]; // x+y
int visited3[33];

std::vector<std::pair<int, int>> vec;
int count = 0;

void bt(int N, int i) {


    if(vec.size() == N) {
        count++;
        return ;
    }
    
    for(int j = 1; j <= N; j++) {
            if(visited[j] || visited2[i+j] || visited3[N - i + j]) continue;
            
            visited[j] = 1;
            visited2[i+j] = 1;
            visited3[N-i+j] = 1;
            vec.push_back({i,j});
            bt(N ,i+1);
            vec.pop_back();
            visited[j] = 0;
            visited2[i+j] = 0;
            visited3[N-i+j] = 0;

    }
}

int main() {
    int N;
    std::cin >> N;
    bt(N, 1);
    std::cout << count;
    return 0;
}