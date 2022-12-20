#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int arr[1000002];
int result[1000002];
/*
    느릿느릿함
    원트클
*/
int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    cin >> n;
    fill(result, result + n + 1 , -1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    
    stack<pair<int, int>> s;
    s.push({arr[1], 1});

    for(int i = 2; i <= n; i++) {
        int cur = arr[i];
        while(!s.empty() && s.top().first < cur) {
            result[s.top().second] = cur;
            s.pop();
        }

        s.push({cur, i});
    }

    for(int i = 1; i <= n; i++)
        cout << result[i] << " ";

    return 0;
}