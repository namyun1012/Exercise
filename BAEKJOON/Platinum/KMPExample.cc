#include <iostream>
#include <vector>
#include <string>
/*
    계속 봐보긴 해야 할 듯
    단번에 이해는 힘들듯 하다

*/

int main() {

    std::string p = "ABABACABA";
    std::string s = "ABABABADABABACABAD";
    //Fail Function
    std::vector<int> f(p.size());
    /*
        index i : 위에서 비교가 이루어지는 문자열의 위치
        index j : 아래에서 비교가 이루어지는 문자열의 위치
        만약에 s[i] == s[j] 일 떄
        바로 j += 1 실행 후 f[i] = j, j

        일치 않을 시
        j = f[j-1] 로 계속해주고 일치하는 곳이 없을 시에는
        j가 0이 됨
    */
    int j = 0;
    for(int i = 1; i < p.size(); i++) {
        while(j > 0 && p[i] != p[j]) j =f[j-1];
        if(p[i] == p[j]) f[i] = ++j; // 같은 게 나왔으면 1 더해준 값으로 함

    }

    for(int i = 0; i < p.size(); i++) {
        std::cout << f[i] << " ";
    } std::cout << "\n\n";

    j = 0;
    for(int i = 0; i < s.size(); ++i) {
        while(j > 0 && s[i] != p[j]) j = f[j-1];
        if(s[i] == p[j]) j++;
        if(j == p.size()) {
            std::cout << "True";
            return 0;
        }

    }
    std::cout << "False";
    return 0;
}