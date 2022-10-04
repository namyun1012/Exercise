#include <iostream> // use greedy
#include <algorithm>

int arr[1000005];
int result[100005];

int main() {
    int N;
    int count = 0;
    std::cin >> N;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    
    result[1] = 0;
    for(int i = 2; i <= N; i++ ) {
        arr[i] = arr[i-1] + 1;
        result[i] = i-1;
        
        if(i % 2 == 0){ 
            arr[i] = std::min(arr[i], arr[i/2]+1);
       
        }
        
        if(i % 3 == 0) { 
            arr[i] = std::min(arr[i], arr[i/3]+1);
            result[i] = i/3;
        }
    }
    
    std::cout << arr[N] << "\n";
    while(true) {
        if(N == 0) break;
        std::cout << N << " ";
        N = result[N];
    }
    return 0;
}