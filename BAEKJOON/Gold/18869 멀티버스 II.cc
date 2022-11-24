#include <iostream>
#include <algorithm>
#include <vector>
/*
    좌표 압축 하고 일일이 다 비교하는 방식으로 진행함
    시간을 꽤 많이 먹는 코드이긴 함

*/
int board[102][10002];
int zipped_board[102][10002];

std::vector<int> uniq_vec[102];

int main() {
    int m, n;
    std::cin >> m >> n;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> board[i][j];
            uniq_vec[i].push_back(board[i][j]);     
        }
    }


    // 정렬 후 중복 원소 제거
    for(int i = 0; i < m; i++) {
        std::sort(uniq_vec[i].begin(), uniq_vec[i].end());
        // std::unique는 중복을 제거하지만 길이를 안 줄여주어서 이렇게 해주어야 함

        uniq_vec[i].erase(std::unique(uniq_vec[i].begin(), uniq_vec[i].end()), uniq_vec[i].end());


        for(int j = 0; j < n; j++) {
            zipped_board[i][j] = std::lower_bound(uniq_vec[i].begin(), uniq_vec[i].end(), board[i][j]) - uniq_vec[i].begin();
        }
    }

    // 좌표 압축 값을 비교
    int result = 0;
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            // 두 배열의 값을 비교함
            if(std::equal(&zipped_board[i][0], &zipped_board[i][n], &zipped_board[j][0]))
                result++;
        }
    }
    
    std::cout << result;
    return 0;

}