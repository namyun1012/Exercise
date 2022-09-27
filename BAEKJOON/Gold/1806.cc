#include <iostream>
#include <algorithm>

int arr[100002];

int main() {
    int N, S;
    std::cin >> N >> S;

    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    int result = N;
    int en = 0;
    int sum = 0;
    bool check = false;
    for(int st = 0; st < N; st++) {
        
        
        while(en < N && sum < S) {
            
            sum += arr[en];
            en++;
        }
        //if(en == N) break; en 이 N이 됬다고 해서 멈출 필요 없음

        if(sum >= S) {
            result = std::min(result, en-st); 
            check = true;
        }

        sum -= arr[st];
    }
    
    if(!check) 
        result = 0;

    std::cout << result;
    return 0;
}