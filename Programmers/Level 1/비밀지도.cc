#include <string>
#include <vector>
#include <cmath>
using namespace std;
/*
    이진수 처리하다 개고생

*/
int board[18][18];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    for(int i = 0 ; i < n; i++) {
        int num = arr1[i];
        
        for(int j = 0; j < n; j++) {
            if(num < pow(2, n - j -1)) {
                continue;
            }
            
            board[i][j] = 1;
            
            
            num -= pow(2, n - j -1);
        }
    }
    
    for(int i = 0 ; i < n; i++) {
        int num = arr2[i];
        
        
        for(int j = 0; j < n; j++) {
            if(num < pow(2, n - j -1)) {
                continue;
            }
            
            board[i][j] = 1;
            
            
            num -= pow(2, n - j -1);
        }
    }
    
    
    vector<string> answer;
    for(int i = 0; i < n; i++) {
        string temp ="";
        
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 1)
                temp += "#";
            else {
                temp += " ";
            }
        }
        
        answer.push_back(temp);
    }
    
    
    return answer;
}