#include <iostream>
#include <algorithm>
void change(int &a, int &b, int &c) {
    if( a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    if( b > c) {
        int temp = b;
        b = c;
        c = temp;
    }

    if( a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

}
int main() {
    while(true) {
        int a,b,c;
        std::cin >> a >> b >> c;
        
        change(a,b,c);
        
        if(a == 0 && b == 0 && c ==0)
            break;

        if(a == 0 || b == 0 || c == 0) {
            std::cout << "wrong" << "\n";
            continue;
        }

        if(a*a + b*b == c*c)
            std::cout << "right" << "\n";
        else {
            std::cout << "wrong" << "\n";
        }

        
    }
    return 0;
}