#include <iostream>
#include <cmath>
enum resists {
    black,
    brown,
    red,
    orange,
    yellow,
    green,
    blue,
    violet,
    grey,
    white

};

resists string_int(std::string str) {
    if(str == "black")
        return black;
    else if(str == "brown")
        return brown;
    else if(str == "red")
        return red;
    else if(str == "orange")
        return orange;
    else if(str == "yellow")
        return yellow;
    else if(str == "green")
        return green;
    else if(str == "blue")
        return blue;
    else if(str == "violet")
        return violet;
    else if(str == "grey")
        return grey;
    else if(str == "white")
        return white;
}



int main() {
    long R = 0;
    std::string s1,s2,s3;
    resists r1,r2,r3;
    std::cin >> s1 >> s2 >> s3;
    r1 = string_int(s1);
    r2 = string_int(s2);
    r3 = string_int(s3);

    R = (10*r1+r2) * pow(10,r3);
    std::cout << R;
    return 0;
}