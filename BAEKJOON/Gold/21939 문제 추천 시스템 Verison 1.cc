#include <iostream>
#include <set>
#include <map>
#include <string>
// 문제 번호, 난이도
std::map<int, int> m; 
//난이도 문제 번호      난이도 순으로 정렬함
std::multiset<std::pair<int, int>> s;


/*
    2중으로 자료구조 사용법 잘 익히기
*/

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int num, diff;
        std::cin >> num >> diff;
        m.insert({num, diff});
        s.insert({diff, num});
    }


    int t;
    std::cin >> t;

    while(t--) {
        std::string order;
        std::cin >> order;

        if(order == "add") {
            int diff, num;
            std::cin >> num >> diff;
            m.insert({num, diff});
            s.insert({diff, num});
        }

        else if(order == "solved") {
            if(m.empty()) continue;
            int num;
            std::cin >> num;
            int diff = m[num];
            m.erase(num);
            s.erase({diff, num});
        }

        else if(order == "recommend") {
            if(m.empty()) continue;
            int x;
            std::cin >> x;
            // 최댓값 가장 어려움
            if(x == 1) {
                int diff, num;
                auto temp = std::prev(s.end());    
                diff = (*temp).first;
                num = (*temp).second;
                std::cout << num << "\n";
            }

            else if(x == -1) {
                int diff, num;
                auto temp = s.begin();    
                diff = (*temp).first;
                num = (*temp).second;
                std::cout << num << "\n";
            }
        }

        else {
            std::cout << "Error Occur" << "\n";
            exit(0);
        }
    }

    return 0;
}   