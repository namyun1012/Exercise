#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    string result = s;
    
    int zero_num = 0;
    int time = 0;
    
    while(result != "1") {
       
        string temp = "";
        for(char c : result) {
            if(c == '0') {
                zero_num++;
            }
            else {
                temp += "1";
            }
        }
        
        int size = temp.size();
        result = "";
        
        while(size > 0) {
            if(size % 2 == 1) {
                result += "1";
            }
            else {
                result += "0";
            }
            
            size /= 2;
        }
        
        reverse(s.begin(), s.end());
        
        time++;
 
    }
    

    vector<int> answer;
    answer.push_back(time);
    answer.push_back(zero_num);
    return answer;
}