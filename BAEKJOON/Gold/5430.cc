#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
//reverse 안하고 앞, 뒤에서 각각 읽으니 됨
//현재 시간 초과중
int temp_arr[100002];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int T;
    std::cin >> T;

    while(T--) {
        std::deque<int> q;
        std::string p;
        std::cin >> p;
        
        int size;
        std::string arr;
        std::cin >> size >> arr;

        std::string temp; // 문자열 받기
        for(int i = 0 ; i < arr.size(); i++) { // deque에 숫자를 넣음
            if(size == 0) break;

            if(arr[i] == ',' || arr[i] == ']') {
                q.push_back(std::stoi(temp));
                temp.clear();
            }

            else if(isdigit(arr[i])) {
                temp += arr[i];
            }
        }
        
        bool check_error = false;
        bool reverse = false;
        
        for(char order : p) {
            if(check_error)
                break;
            
            if(order == 'R') {
                if(reverse)
                    reverse = false;
                else   
                    reverse = true;
            }

            else if(order == 'D') {
                if(q.empty()) {
                    check_error = true;
                    break;
                }

                if(!reverse){
                   q.pop_front();
                }

                else{ // reverse 일때
                    q.pop_back();
                }

            }
        }
        /*if(reverse)
            std::reverse(q.begin(), q.end());
        */
        
        if(check_error) {
            std::cout << "error\n";
        }
        else {
            if(reverse) {
                std::cout << "[";
                while(!q.empty()) {
                    std::cout << q.back();
                    q.pop_back();
                    if(!q.empty())
                        std::cout << ",";
                }

                std::cout << "]\n";
            }

            else {
                std::cout << "[";
                while(!q.empty()) {
                    std::cout << q.front();
                    q.pop_front();
                    if(!q.empty())
                        std::cout << ",";
                }

                std::cout << "]\n";
            }
        }
        /*else {
            std::cout << "[";
            for(auto ele : q) {
                std::cout << ele;
                if(ele != q.back())
                    std::cout << ",";
            }
            std::cout << "]\n";
        }
        */
    }
    return 0;
}