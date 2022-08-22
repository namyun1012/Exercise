#include <iostream>
#include <string>

using namespace std;
int main() {
    int N;
    cin >> N;

    int count = 0;
    int result;
    
    for(int i = 666 ;  ; i++) {
        if(to_string(i).find("666") != string::npos) {   //str.find 성공시 해당 첫번째 index 실패시 string::npos 반환 (npos 는 0이 아님)
            count++;
            result = i;
            
        }
        
        if(count == N)
            break;
        
        
    }
    
    cout << result;
}