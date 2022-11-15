#include <iostream>
#include <algorithm>
/*
    자잘한 걸로 많이 틀린 듯?
*/
int board[55][55][55]; // a,b,c 일때 

int func(int a, int b, int c) {
    

    if(a <= 0 || b <= 0 || c <= 0) return 1;

    if(a > 20 || b > 20 || c > 20) return func(20, 20, 20);
    
    if(board[a][b][c] != 0) return board[a][b][c];
    if(a < b && b < c) {
        board[a][b][c] = func(a,b, c-1) + func(a, b-1, c-1) - func(a, b-1, c);
        return board[a][b][c];
    }

    board[a][b][c] = func(a-1, b, c) + func(a-1, b-1, c) + func(a-1, b, c-1) -func(a-1, b-1, c-1);
    return board[a][b][c];
}



int main() {
    
    while(true) {
        int a,b,c;
        std::cin >> a >> b >> c;
        
        if(a == -1 && b == -1 && c == -1)
            break;
        
        int result = func(a, b, c);

        printf("w(%d, %d, %d) = %d\n",a,b,c ,result);
        
    }

    return 0;
}