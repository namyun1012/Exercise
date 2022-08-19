#include <iostream>
#include <string>
#include <vector>
int main() {
    int T;
    std::cin >> T;
    std::vector<std::string> vec;
    for(int i = 0; i < T; i++) {
        int N;
        std::string str;
        std::string new_str;
        std::cin >> N >> str;
        for(int i = 0; i < str.size(); i++) {
            for(int j = 0; j < N; j++)
                new_str += str[i];
        }
            
        vec.push_back(new_str);
    }

    for(auto ele : vec)
        std::cout << ele << "\n";

    return 0;
}