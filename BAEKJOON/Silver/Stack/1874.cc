#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
int main() {
    int N;
    std::stack<int> s;
    std::vector<char> c_vec;
    std::cin >> N;
    int cur = 2;
    bool check = false;

    c_vec.push_back('+');
    s.push(1);
    for(int i = 0; i < N; i++) {
        int data;
        std::cin >> data; 
        if(s.empty()) s.push(0); // stack이 완전히 비면 뒷 코드가 안굴러감
        
        if(data > s.top()) {
            while(data != s.top()) {
                s.push(cur);
                cur++;
                c_vec.push_back('+');
            }
        }

        if(data <= s.top()) {
            int pop_value = s.top();
            s.pop();
            if(data != pop_value) {
                std::cout << "NO";
                check = true;
                break;
            }

            else {
                c_vec.push_back('-');
            }
        }
    }
    if(!check) {
    for(auto ele : c_vec)
        std::cout << ele << "\n";

    }

    return 0;
}