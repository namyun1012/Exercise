#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0) {
        return cities.size() * 5;
    }
    
    
    deque<string> temp(cacheSize);
    for(string city : cities) {
        // 찾았을 경우 그것을 앞으로 뺌 그리고 값 1 추가
        deque<string>::iterator it;
        for(char &c : city) {
            c = toupper(c);
        }

        
        
        
        it = find(temp.begin(),temp.end(), city);
        // 찾았음
        if(it != temp.end()) {
            temp.erase(it);
            temp.push_back(city);
            answer++;
        }
        
        else {
            // 크기가 부족해질 경우에만 지움
            if(temp.size() == cacheSize)
                temp.pop_front();
            temp.push_back(city);
            answer+=5;
        }
        
        // 만약 있을 시 거기 있던 것을 맨앞으로 꺼내자

    }
    
    
    
    
    return answer;
}