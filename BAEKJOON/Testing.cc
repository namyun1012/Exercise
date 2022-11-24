#include <iostream>
#include <String>

int main() {
    for(int i = 0; i < 10; i++) {
        if(true) 
            printf("OOO\n");
        else 
            printf("NO\n");
    }
    
    std::string str = "123";
    std::cout << str;
    return 0;
}