#include <iostream>

#include <vector>

int N;
int number[12];
int oper[12];
int visited[12];

std::vector<int> op_vec;
int max_result = -1e9;
int min_result = 1e9;
int count = 0;


void bt() {   
    if(op_vec.size() == N-1) {
        int temp = number[0];
        for(int i = 0; i < N-1; i++) {
            if(op_vec[i] == 0) {
                temp += number[i+1];
            }

            else if(op_vec[i] == 1) {
                temp -= number[i+1];
            }

            else if(op_vec[i] == 2) {
                temp *= number[i+1];
            }

            else if(op_vec[i] == 3) {
                temp /= number[i+1];
            }

            else {
                std::cout << "ERROR OCCUR";
            }


        }

        max_result = std::max(temp, max_result);
        min_result = std::min(temp, min_result);
        return ;
    }

    for(int i = 0; i < N-1; i++) {
        if(visited[i]) continue;
        op_vec.push_back(oper[i]);
        visited[i] = 1;
        bt();
        op_vec.pop_back();
        visited[i] = 0;
    }

}

int main() {
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        std::cin >> number[i];
    }

    int idx = 0;
    for(int i = 0; i < 4; i++) {  // + - * /
        int temp;
        std::cin >> temp;
        while(temp--) {
            oper[idx] = i;
            idx++;
        }
    }
    bt();
    std::cout << max_result << "\n" << min_result;
    return 0;
}