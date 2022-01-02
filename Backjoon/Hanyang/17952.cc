#include <iostream>
#include <vector>

struct subject {
    int score =0;
    int time=0;
};

int main() {
    int N =0;
    std::cin >> N;
    int C=0,A=0,T=0;
    int total = 0;
    std::vector<subject> sub_que(N); //vector의 크기를 정해주어야 백준에서 런타임 오류가 안났다. N크기의 벡터를 만들라

    for(int i = 0; i < N; i++){
        std::cin >> C;
        if(C == 1) {
            std::cin >> A >> T;
            subject sub;
            sub.score = A;
            sub.time = T;
            sub_que.push_back(sub);
        }

        if(sub_que[(sub_que.size()-1)].time != 0) {
            sub_que[(sub_que.size()-1)].time -= 1;
            if(sub_que[(sub_que.size()-1)].time == 0) {
                total += sub_que[(sub_que.size()-1)].score;
                sub_que.pop_back();
        }
        }

        else {
            total += sub_que[(sub_que.size()-1)].score;
            sub_que.pop_back();
            sub_que[(sub_que.size()-1)].time -= 1;
        }

        
        C=0; A=0; T=0;
    }

    std::cout << total;
    return 0;
}