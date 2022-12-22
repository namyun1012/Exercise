#include <iostream>
#include <algorithm>
#include <stack>
// 오큰수 변형판
using namespace std;

int n;
int arr[1000002];
int fre[1000002];
int result[1000002];

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        fre[arr[i]]++;
    }

    // first = value, second = result_index
    stack<pair<int, int>> s;

    for(int i = 0; i < n; i++) {
        int cur = arr[i];
    
        while(!s.empty() && (fre[cur] > fre[s.top().first])) {
            result[s.top().second] = cur;
            s.pop();
        }
        
        s.push({cur, i});

    }

    while(!s.empty()) {
        result[s.top().second] = -1;
        s.pop();
    }



    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }    


    return 0;
}