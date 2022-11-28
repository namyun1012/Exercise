#include <iostream>
#include <string>
#include <map>
int main() {
    std::map<std::string, int> m;
    std::string temp = "Testing";

    std::cout << m[temp]; 
    return 0;
}