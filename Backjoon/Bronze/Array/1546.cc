#include <iostream>

int main(void) {
    int N, M;
    float X = 0;
    std::cin >> N;

    int *scores = new int[N];
    
    for(int i = 0; i < N; i++) std::cin >> scores[i];
    M = scores[0];

    for(int i = 0; i < N; i++) {
       if(scores[i] > M) M = scores[i];
    }

    float *new_scores = new float[N];
    
    for(int i = 0; i < N; i++) {
        new_scores[i] = float(scores[i]/float(M)*100);
    }
    
    for(int i = 0; i < N; i++) X += new_scores[i];
    X = X / N;

    std::cout << X ;

    delete[] scores;
    delete[] new_scores;
    return 0;

}