#include <iostream>
#include <string>
#include <vector>

int dp[1002];
int arr1[1002];
int arr2[1002];

int main() {
    std::string str1;
    std::string str2;

    std::cin >> str1 >> str2;

    //int type으로 전환
    for(int i = 0; i < str1.size(); i++) {
        int temp1 = str1[i] - 'A';
        int temp2 = str2[i] = 'A';
        arr1[i] = temp1;
        arr2[i] = temp2;
    }

    
}