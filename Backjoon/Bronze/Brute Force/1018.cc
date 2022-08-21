#include <iostream>
#include <algorithm>

char BArr [8][8] = {{'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'}};

/*char WArr [8][8] = {
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'}}; */





int main() {
    int N, M;
    std::cin >> M >>  N;
    int result_count = 64;
    char **arr =  (char**)malloc(sizeof(char*) * M);
    
    //초기화
    
    for(int i =0; i < M; i++) {
        arr[i] = (char*)malloc(sizeof(char) * N);
    }

    for(int i = 0; i < M; i++)
        std::cin >> arr[i];

    //배열 생성
    for(int i = 0; i <= M-8; i++) {
        
        
        for(int j = 0; j <= N-8; j++) {
            int count = 0;
            int x = j; int y = i;
            if(true) {
                for(int k = y; k < y+8; k++) {
                    for(int l = x; l < x+8; l++) {
                        if(arr[k][l] != BArr[k-y][l-x])
                            count++;
                    }
                }
            }

            /*if(arr[y][x] == 'W') {
                for(int k = y; k < y+8; k++) {
                    for(int l = x; l < x+8; l++) {
                        if(arr[k][l] != WArr[k-y][l-x])
                            count++;
                    }
                }
            }*/
            if(arr[y][x] == 'W') {
                count = 64-count;
            }
            if(count > 32) count = 64-count;
            if(count < result_count)
                result_count = count;
            
        }
        
    }
    //각 8*8 만큼 칠해야 되는 갯수 찾기 + 최솟값 정하기
    

    std::cout << result_count;
    /*for(int i =0; i < M; i++) {
        free(arr[i]);


    }

    free(arr); */
    //배열 삭제
    //백준에서 메모리 삭제시 메모리 초과됨
    return 0;
}