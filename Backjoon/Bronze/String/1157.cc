#include <iostream>
#include <string>


int main() {
    std::string str;
    int *arr[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    std::cin >> str;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] <= 90) { //대문자 A = 65 a = 97
            int num = str[i] - 65;
            arr[num]++;
        }
        
        else {
            int num = str[i] - 97;
            arr[num]++;
        }
    }
    int max = 0;
    for(int i = 0; i < 26; i++) {
        if(arr[max] < arr[i])
            max = i;
    }

    for(int i = 0; i < 26; i++) {
        if(arr[max] == arr[i] && max != i) {
            std::cout << "?";
            return 0;
        }
            
    }

    char result = max + 65;
    std::cout << result;
    return 0;
    
}