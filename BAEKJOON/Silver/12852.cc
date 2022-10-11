#include <iostream> // use greedy
#include <algorithm>

int arr[1000005];
int result[1000005];
// 배열 크기 부족
int main() {
    int N;
    int count = 0;
    std::cin >> N;
    arr[1] = 0;
    

    for(int i = 2; i <= N; i++ ) {
        arr[i] = arr[i-1] + 1;
        result[i] = i-1;
        
        
        
        if(i % 3 == 0 && arr[i] > arr[i/3] + 1) { 
            arr[i] = arr[i/3]+1;
            result[i] = i/3;
        }

        if(i % 2 == 0 && arr[i] > arr[i/2] + 1){ 
            arr[i] = arr[i/2]+1;
            result[i] = i/2;
        }
    }
    
    std::cout << arr[N] << "\n";

    int cur = N;
    while(true) {
        
        std::cout << cur << " ";
        if(cur == 1) break;
        cur = result[cur];
    }
    return 0;
}