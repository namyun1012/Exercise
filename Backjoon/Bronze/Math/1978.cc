#include <iostream>
#include <vector>
int Find(int *arr, int N) {
    std::vector<int> vec = {2,3,5,7};
    
    for(int i = 10; i < 1000; i++) {
        
        for(int j = 0; j < vec.size(); j++) {
            if(i % vec[j] == 0) 
                break;
            if(j == vec.size()-1) vec.push_back(i);
        }
        
    
    }
    
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(auto ele : vec) {
            if(arr[i] == ele) {
                count++;
                break;
            }
        }
        
    }

    return count;
}


int main() {
    int N;
    std::cin >> N;

    int arr[100];
    int count;
    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];

    }

    int result = Find(arr, N);
    std::cout << result;
}