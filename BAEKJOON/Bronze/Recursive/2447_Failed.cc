#include <iostream> //Failed 계산량 노답
#include <cmath>
#include <string.h>


void star(int N, char** arr, int a, int b, int NN) {
    if(N == 1)
        return ;
    for(int i = a +(N/3); i < a + ((N /3)*2) ; i++) {
        for(int j = b + (N / 3); j < b + ((N / 3)*2); j++) {
            if(i < NN && j < NN)
                arr[i][j] = ' ';
            
        }
    }

    for(int i = 0; i < NN; i+=(N/3)) {
        for(int j = 0; j < NN; j+=(N/3)) {
            star(N/3, arr, i ,j, NN);
        }
    }
}

int main() {
    int N,k;
    k = 0;
    std::cin >> N;
    char ** arr = new char*[N];
    
    for(int i =0; i < N; i++)
        arr[i] = new char[N];

    for(int i = 0; i < N; i++) {
        memset(arr[i], '*', sizeof(char)*N);
    
    }
    

    star(N, arr, 0, 0, N);


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            std::cout << arr[i][j];
        std::cout << "\n";
    }

    return 0;

}