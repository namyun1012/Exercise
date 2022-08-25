#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
int main() {
    int N;
    std::stack<int> s;
    int arr[100000];
    std::vector<char> vec_c;
    std::cin >> N;
    int count = 0;
    for(int i = 0; i < N; i++)
        std::cin >> arr[i];
    
    //first Initialize
    for(int i = 1; i <= arr[0]; i++) {
        s.push(i);
        vec_c.push_back('+');
        count++;
    }
    // arr[1] ~~ arr[N-1]
    int i = 1;
    while(i < N) {
        if(s.top() < arr[i]) {}
    
    }


    if(count > 2*N)
        std::cout << "NO";
    return 0;
}