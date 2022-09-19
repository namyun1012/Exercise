#include <iostream> // use greedy
#include <algorithm>

int arr[1000005];


int main() {
    int N;
    int count = 0;
    int N_copy = N;
    std::cin >> N;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for(int i = 2; i <= N-1; i++ ) {
        arr[i] = arr[i-1] + 1;
        if(i % 2 == 0) arr[i] = std::min(arr[i], arr[i/2]+1);
        if(i % 3 == 0) arr[i] = std::min(arr[i], arr[i/3]+1);

    }
    
    
    
    std::cout << arr[N];
    return 0;
}