#include <iostream>
#include <string>
#include <vector>
//max는 1000
int dp[1002][1002];



int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;

    int size_1= str1.size();
    int size_2 = str2.size();

    for(int i = 1; i <= size_1; i++) { // dp[]
        for(int j = 1; j <= size_2; j++) {
            dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
        }
    }

    std::cout << dp[size_1][size_2];
    return 0;
}