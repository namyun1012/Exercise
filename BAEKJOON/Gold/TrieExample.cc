#include <iostream>
#include <algorithm>
#include <string>

const int root = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
bool chk[MX];
int nxt[MX][26];


int charToInt(char c) {
    return c - 'A';
}

bool insert(std::string &s) {
    int cur = root;
    for(auto c : s) {
        if(nxt[cur][charToInt(c)] == -1)
            nxt[cur][charToInt(c)] = unused++;
        cur = nxt[cur][charToInt(c)];
    }

    chk[cur] = true;

}

bool find(std::string &s) {
    int cur = root;
    for(auto c : s) {
        if(nxt[cur][charToInt(c)] == -1)
            return false;
        cur = nxt[cur][charToInt(c)];
    }

    return chk[cur];
}


void erase(std::string &s) {
    int cur = root;
    for(auto c : s) {
        if(nxt[cur][charToInt(c)] == -1)
            return ;
        cur = nxt[cur][charToInt(c)];
    }
    // 끝 부분만 안 쓴다고 표기
    chk[cur] = false;
}
int main() {
    for(int i = 0; i < MX; i++) {
        std::fill(nxt[i], nxt[i] + 26, -1);
    }

   

}