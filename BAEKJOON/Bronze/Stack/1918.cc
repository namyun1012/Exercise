#include <iostream>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>

int forward(char c) {
    switch (c) {
    
    case '*':
        return 5;
        break;
    case '/':
        return 5;
        break;
    
    case '+':
        return 3;
        break;
    
    case '-':
        return 3;
        break;

    case '(':
        return 1;
        break;
    
    default:
        break;
    }
}

int compare_forward(char c1, char c2) {
    if(forward(c1) > forward(c2))
        return 1;
    else if(forward(c1) == forward(c2))
        return 0;
    else return -1;

}

bool isInt(char c1) {
    if('A' <= c1 && c1 <= 'Z')
        return true;
    else return false;


}

using namespace std;
int main() {
    int arrLen;
    char arr[100];
    
    stack<char> s;
    string str;
    cin >> str;

    arrLen = str.size();
    string after_arr;

    int i = 0;
    
    for(i = 0; i < arrLen; i++) {
        char c = str[i];
        
        if(isInt(c)) {
            after_arr.push_back(c);
        
        }

        else if(c == '(') {
            s.push(c);
        }

        else if(c == ')') {
            while(s.top() != '(') {
                after_arr.push_back(s.top());
                s.pop();
            }

            s.pop();
        }
        
        else {
            while(true) {
                if(!s.empty() && compare_forward(s.top(), c) >= 0) {
                    after_arr.push_back(s.top());
                    s.pop();
                    
                }
                else break;
            }

            s.push(c);


        }
    }

    while(!s.empty()) {
            after_arr.push_back(s.top());
            s.pop();
        }

    
    cout << after_arr;

    return 0;
}