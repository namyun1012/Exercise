#include <iostream>
#include <vector>

//1629번과 같은 방식으로 해결을 진행함
//배열은 불편할 것 같아서 벡터로 사용
//B가 int 범위를 초과할 수 있으므로 long long을 사용
#define vvi std::vector<std::vector<long long>>


vvi board(6, std::vector<long long>(6,0)); // int board[6][6];
vvi result_board(6, std::vector<long long>(6,0));

int N;
long long B;

vvi calc(vvi matrixA, vvi matrixB) { // 행렬의 곱을 구하는 함수
    vvi temp_board(6, std::vector<long long>(6,0));
    
    for(int i = 1; i <=  N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                temp_board[i][j] += ((matrixA[i][k] % 1000) * (matrixB[k][j]) % 1000) % 1000;
            }
                
            temp_board[i][j] %= 1000;
        }
    }

    return temp_board;
}


vvi power(vvi matrix, long long B) {
    
    if(B == 1)
        return matrix;
    
    vvi temp_board = power(matrix, B/2);

    
    if(B % 2 == 0) { // 짝수 일때
        return calc(temp_board, temp_board);
    }

    //  홀 수 일 때
    return calc(calc(temp_board, temp_board), board);

}


int main() {
    std::cin >> N >> B;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            std::cin >> board[i][j];
            board[i][j] %= 1000;
        }
    }
    
    result_board = power(board, B);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            std::cout << result_board[i][j] << " ";
        }

        std::cout << "\n";
    }

    return 0;
}