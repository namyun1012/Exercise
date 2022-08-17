#include <iostream>
#include <algorithm>

int arr[1000000];

int main() {
    int N;
    std::cin >> N;

    

    for(int i =0; i < N; i++)
        std::cin >> arr[i];
    
    std::sort(arr, arr+N);

    for(int i = 0; i < N; i++) 
        std::cout << arr[i] << "\n";    // std::endl 시간 많이 걸림

    return 0;

}