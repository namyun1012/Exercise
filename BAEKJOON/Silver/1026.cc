#include <iostream>
#include <algorithm>
// 큰 B에 작은 A를 붙여줌
int A[52];
int B[52];

int main() {
    int N;
    std::cin >> N;

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::sort(A, A+N);

    int result = 0;
    int *pit;
   
    for(int i = 0 ; i < N; i++) {
        pit = std::max_element(B , B+N);
        result += (A[i] * (*pit));
        *pit = 0;
    }

    std::cout << result;
}