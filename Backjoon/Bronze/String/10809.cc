#include <iostream>
#include <vector>

int main() {
    std::string str;
    std::cin >> str;

    std::vector<int> vec (26,-1);

    for(int i = 0; i < str.size(); i++) {
        if(vec[(str[i]-'a')] == -1)
            vec[(str[i]-'a')] =  i;
    }

    for(auto i : vec)
        std::cout << i << " ";

    return 0;

}