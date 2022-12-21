#include <iostream>
#include <string>
#include <vector>
//max는 1000
int dp[1002][1002];
std::pair<int, int> prev[1002][1002];
/*
    단순 저장하는 방식으로 가니 바로 시간초과 뜸
    역 추적 방식으로 prev는 이전 것의 좌표를 받음
*/

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    std::string str1, str2;
    std::cin >> str1 >> str2;

    int size_1 = str1.size();
    int size_2 = str2.size();
    for(int i = 0; i <= size_1; i++)
        prev[i][0] = {-1, -1};
    for(int i = 0; i <= size_2; i++)
        prev[0][i] = {-1, -1};
     

    for(int i = 1; i <= size_1; i++) { // dp[]
        for(int j = 1; j <= size_2; j++) {
            if(dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                prev[i][j] = prev[i-1][j];
            }

            else {
                dp[i][j] = dp[i][j-1];
                prev[i][j] = prev[i][j-1];
            }

            // 하나를 늘릴 때
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                prev[i][j] = {i-1, j-1};
            }
        }
    }

    std::cout << dp[size_1][size_2] << "\n";

    std::pair<int, int> temp = prev[size_1][size_2];
    std::vector<char> result;

    while(!(temp.first == -1 && temp.second == -1)) {
        
        result.push_back(str1[temp.first]);
        temp = prev[temp.first][temp.second];
    }

    for(int i = result.size() - 1; i >= 0; i--) {
        std::cout << result[i];
    }
    
 
    return 0;
}