#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    int ele = a;
    a = b;
    b = ele;
}


int main() {
    int N;
    std::cin >> N;
    std::vector<int> vec;

    for(int i = 0; i < N; i++) {
        int ele;
        std::cin >> ele;    vec.push_back(ele);
    }

    for(int j = 0; j < N; j++) {
        for(int i = 0; i < N - 1; i++) {
            if(vec[i] > vec[i+1])
                swap(vec[i], vec[i+1]);
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << vec[i] << std::endl;
    }

    return 0;
}