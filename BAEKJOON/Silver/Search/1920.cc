#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000

int main() {
    std::ios::sync_with_stdio(false); // 시간
    std::cin.tie(NULL);
    
    int N;
    int M;
    int find_vec[100000];
    int arr_vec[100000];


    std::cin >> N;
    for(int i = 0; i < N; i++) {
        int ele;
        std::cin >> ele;
        find_vec[i] = ele;
       
    }

    std::cin >> M;
    for(int i = 0; i < M; i++) {
        int ele;
        std::cin >> ele;
        arr_vec[i] = ele;
    }

    std::sort(find_vec, find_vec+N);
    for(int i = 0; i < M; i++) {
        int check = 0;
        int a = 0;
        int b = N - 1;
        int mid;
        
        while(a <= b) {
            mid = (a+b) / 2;
            if(find_vec[mid] == arr_vec[i]) {
                break;
            }
            if(find_vec[mid] < arr_vec[i])
                a = mid + 1;
            
            else b = mid - 1;
        }

        if(find_vec[mid] == arr_vec[i])
            std::cout << 1 << "\n";
        else std::cout << 0 << "\n";

        
        
    }

    

    return 0;


}