#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string str;
    
    while(true) {
        std::stack<char> s; // stack 초기화가 안되고 있엇음
        bool check = true;
        std::getline(std::cin, str);
        
        if(str == ".") {
            break;
        }
        
        for(auto c : str) {
            
            if(c == '(') {
                s.push(c);
            }

            else if(c == '[') {
                s.push(c);
            }

            else if(c == ')') {
                if(s.empty()) {
                    check = false;
                    break;
                }

                if(s.top() == '(') {
                    s.pop();
                    check = true;
                }

                else {
                    check = false;
                    break;
                }
            }

            else if(c == ']') {
                if(s.empty()) {
                    check = false;
                    break;
                }

                if(s.top() == '[') {
                    s.pop();
                    check = true;
                }

                else {
                    check = false;
                    break;
                }
            
            }
        }
        if(!s.empty()) check = false;
        
        if(check) 
            std::cout << "yes\n";
        else 
            std::cout << "no\n";
    }

    return 0;
}