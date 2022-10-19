#include <iostream>
#include <string>

int board[65][65];
std::string result = "";

bool check(int st_x, int st_y, int size) { // 모두 1이거나 0일 때 return true
    int check_temp = board[st_x][st_y];
    for(int i = st_x; i < st_x + size; i++) {
        for(int j = st_y ; j < st_y + size; j++) {
            if(board[i][j] != check_temp)
                return false;
        }
    }

    return true;
}

void QuardTree(int st_x, int st_y, int size) {
    if(check(st_x, st_y, size)){ // 모두 1이거나 0일때
        int temp_char = board[st_x][st_y] -'0';
        result += std::to_string(temp_char);
    }

    else {
        result += "(";
        QuardTree(st_x, st_y, size/2);
        QuardTree(st_x, st_y + size/2, size/2);
        QuardTree(st_x + size/2, st_y, size/2);
        QuardTree(st_x + size/2, st_y + size/2 , size/2);
        result += ")";
    }

}



int main() {
    int N;
   


    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::string tmp;
        std::cin >> tmp;
        for(int j = 0; j < N; j++) {
            board[i][j] = tmp[j];
        }
    }

    QuardTree(0, 0, N);

    std::cout << result;
    return 0;
}