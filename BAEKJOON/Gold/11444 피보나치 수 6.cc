#include <iostream>
#include <algorithm>

using namespace std;

// Fn = Fn-1 + Fn-2;
// >> Fn = 2Fn-2 + fn-3
// >> Fn = 3fn-3 + 2fn-4;
// >> fn = 5fn-4 + 3fn-5;

int main() {
    long long a,b,c;

    long long n;
    cin >> n;

    a = 0;
    b = 1;
    c = 1;
    if(n == 1) {
        cout << 0;
        return 0;
    }

    if(n == 2) {
        cout << 1;
        return 0;
    }


    for(long long i = 3; i <= n; i++) {
        a = b;
        b = c;
        c = (a + b) % 1000000007;
    }
 
    cout << (c % 1000000007);
    return 0;
}