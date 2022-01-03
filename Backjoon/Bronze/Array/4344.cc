#include <iostream>
#include <vector>

int main() {
    int C;
    std::cin >> C;
    std::vector<std::vector<int>> score_vec;
    std::vector<int> size_vec;
    std::vector<double> ave_vec;

    for(int i =0; i < C; i++) {
        std::vector<int> vec;
        int N;
        std::cin >> N;
        
        size_vec.push_back(N);
        for(int j = 0; j < N; j++) {
            int score;
            std::cin >> score;
            vec.push_back(score);
        }

        score_vec.push_back(vec);
    }

    for(int i =0; i < C; i++) {
        double ave_score = 0;
        for(int j = 0; j < size_vec[i]; j++)
            ave_score += (double) score_vec[i][j];

        ave_score = (double)ave_score/(double) size_vec[i];
        ave_vec.push_back(ave_score);
    }

    for(int i =0; i < C; i++) {
        double per = 0;
         for(int j = 0; j < size_vec[i]; j++) {
            if(score_vec[i][j] > ave_vec[i])
                per += (double) 1;
        }

        per /= size_vec[i];
        printf("%.3f", (double)(per*100));
        std::cout << "%" << std::endl;
    }

    return 0;
}