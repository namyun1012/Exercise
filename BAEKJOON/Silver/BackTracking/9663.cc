#include <iostream>
#include <vector>


bool checked[20][20];


int count = 0;

void dfs(int N, int num) { // num은 행
        

    for(int i = num; i <= N; i++) { // i가 행 j가 열
        for(int j = 1; j <= N; j++) {
            if(checked[i][j]) continue;


        
            checked[i][j] = true;
            dfs(N, num + 1);
            checked[i][j] = false;
            

        }

    }


}


int main() {
    int N;
    std::cin >> N;

    dfs(N, 1);

    return 0;
}