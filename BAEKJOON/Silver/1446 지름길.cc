#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

tuple<int, int, int> roads[13];
int dp[10002];

int main() {
    int n, D;
    cin >> n >> D;
    std::fill(dp, dp + 10001, 1e9);

    for(int i = 0; i < n; i++) {
        int fromV, toV, weight;
        std::cin >> fromV >> toV >> weight;
        roads[i] = {fromV, toV, weight};
    }

    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        int fromV, toV, weight;
        std::tie(fromV, toV, weight) = roads[i];
        if(fromV == 0) {
            dp[toV] = min(dp[toV], weight + dp[0]);
        }
    }



    for(int i = 1; i <= D; i++) {
        dp[i] = min(dp[i-1] + 1, dp[i]);

        for(int j = 0; j < n; j++) {
            int fromV, toV, weight;
            tie(fromV, toV, weight) = roads[j];
            if(fromV == i) {
                dp[toV] = min(dp[toV], weight + dp[i]);
            }
        }

    }

    cout << dp[D];
    return 0;
}