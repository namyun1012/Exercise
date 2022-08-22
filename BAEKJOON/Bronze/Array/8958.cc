#include <iostream>



int main() {
    int N;
    std::cin >> N;
    
    char arr[N][80];
    int score_arr[N];

    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        int total_score = 0;
        int score = 0;
        int last_score = 0;
        for(auto word : arr[i]) {
            if(word == '\0')
                break;
            
            
            if(word == 'O') {
                score = last_score + 1;
                total_score += score;
                last_score++;
            }

            else if(word == 'X') {
                score = 0;
                last_score = 0;
            }
            
        }

        score_arr[i] = total_score;
    }

    for(int i =0; i < N; i++) {
        std::cout << score_arr[i] << std::endl;
    }


    return 0;
}