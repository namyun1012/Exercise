#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
/*
    문자열을 저장하는 trie 자료 구조임
    더 알아봐야 할 듯
*/
class trie {
public: 
    map<string , trie*> child;
    bool end;

    trie() {
        child.clear();
        end = false;
    }
    
    void insert(vector<string>& v, int index) {
        if(index == v.size()) {
            end = true;
            return ;
        }
        
        string temp = v[index];
        if(child[temp] == NULL) 
            child[temp] = new trie();

        child[temp]->insert(v, index + 1); 

    }

    void print(int index) {
        for(auto it = child.begin(); it != child.end(); it++) {
            for(int i = 0; i < index; i++)
                cout << "--";
            

            cout << it->first << "\n";
            it->second->print(index + 1); // ++index를 하면 당연히 오류남
        }
    }

};


int main() {
    trie* root = new trie();
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        vector<string> temp_vec;
        int temp;
        std::cin >> temp;
        for(int j = 0; j < temp; j++) {
            string c;
            std::cin >> c;
            temp_vec.push_back(c);
        }

        root->insert(temp_vec, 0);
    }

    root->print(0);
    return 0;
}
