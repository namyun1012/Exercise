#include <iostream>
#include <string>
#include <vector>
//max는 1000
int dp[1002];
int arr1[1002];
int arr2[1002];

int main() {
    std::string str1;
    std::string str2;

    int size1 = str1.size();
    int size2 = str2.size();

    std::cin >> str1 >> str2;

    for(int i = 0; i < size1 ; i++) {
        if(str1[i] == str2[0]) {
            dp[0] = 1;
            break;
        }
    }

    for(int i = 1; i < size2; i++) {
        dp[i] = dp[i-1];
        int temp = 0;
        for(int j = 0; j < size1; j++) {
            
        }
    }

    std::cout << dp[size1-1] << "\n";
    return 0;
}