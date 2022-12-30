#include <iostream>
#include <algorithm>
// 펠린드롬은 거꾸로 읽어도 제대로 읽어도 앞뒤가 같은 문장임
using namespace std;
/*
    풀이 방법 가다가 살짝 이상해 진 듯
*/


int n;

int arr[2002];
int dp[2002][2002];

int search(int s, int e) {
    if(dp[s][e] != -1) return dp[s][e];

    if((arr[s] == arr[e]) && search(s+1, e-1)) {
        dp[s][e] = 1;
        return dp[s][e];
    }

    else {
        dp[s][e] = 0;
        return dp[s][e];
    }

}



int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    cin >> n;
    // 초기값은 -1로 설정
    fill(&dp[0][0], &dp[2001][2001], -1);

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++) {
        dp[i][i] = 1;
        if(arr[i] == arr[i+1]) {
            dp[i][i+1] = 1;
        }
        else {
            dp[i][i+1] = 0;
        }
    }
    

    int m;
    cin >> m;
    while(m--) {
        int s, e;
        cin >> s >> e;
        cout << search(s,e) << "\n";
    }

    return 0;
}