#include <iostream>
//에라토스테네스의 체 사용
int main(){
    int M, N;
    std::cin >> M >> N;

    bool *arr = new bool[N+1];

    for(int i = 2; i <= N ;i++)
        arr[i] = true;

    for(int i = 2; i*i <= N; i++) {
        if(arr[i]) {
            for(int j = i*i; j <= N; j+=i)
                arr[j] = false;
        }

    }

    for(int i = M; i <= N; i++) {
        if(arr[i])
            std::cout << i << "\n";
    }

    
    return 0;
}
