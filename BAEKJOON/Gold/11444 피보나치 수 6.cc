#include <iostream>
#include <algorithm>
#include <vector>

#define vvi std::vector<std::vector<long long>>


/*
  fn+2 =  Fn+1 fn
  fn+1 =  fn  fn-1
 
 >>
    1 1
    1 0 의 n제곱
    증명은 귀납법 통해서 진행함
    1일 때 성립
    n일 때 성립 가정할 때
    n + 1 에서 또한 성립함
*/

vvi board(6, std::vector<long long>(6,0)); // int board[6][6];
vvi result_board(6, std::vector<long long>(6,0));

int N = 2;
long long B;

vvi calc(vvi matrixA, vvi matrixB) { // 행렬의 곱을 구하는 함수
    vvi temp_board(6, std::vector<long long>(6,0));
    
    for(int i = 1; i <=  N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                temp_board[i][j] += ((matrixA[i][k] % 1000000007) * (matrixB[k][j]) % 1000000007) % 1000000007;
            }
                
            temp_board[i][j] %= 1000000007;
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
    std::cin >> B;
    board[1][1] = 1;
    board[1][2] = 1;
    board[2][1] = 1;
    board[2][2] = 0;

    result_board = power(board, B);

    std::cout << result_board[2][1];
    return 0;
}