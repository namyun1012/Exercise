#include <iostream>
#include <vector>
//table 정의만 보고 함
int stairs[302]; // 0은 기본으로 설정
int result[302][4]; // result[i][j] 현재까지 j개의 연속해서 계단을 밟고 i까지 올라감

int main() {
    int N;
    std::cin >> N;

    for(int i = 1; i <= N; i++)
        std::cin >> stairs[i];

    result[1][1] = stairs[1];
    result[2][2] = stairs[1] + stairs[2];
    result[2][1] = stairs[2];

    for(int i = 3; i <= N; i++) {
        result[i][1] = std::max(result[i-2][2], result[i-2][1]) + stairs[i];
        result[i][2] = result[i-1][1] + stairs[i];
    }

    std::cout << std::max(result[N][1], result[N][2]);
    return 0;
}