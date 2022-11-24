#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int size = queue1.size();
    long long result = 0;
    queue<int> q1;
    queue<int> q2;
    
    long long sum1 = 0;
    long long sum2 = 0;
    for(long long ele : queue1) {
        sum1 += ele;
        q1.push(ele);
    }
    
    for(long long ele : queue2) {
        sum2 += ele;
        q2.push(ele);
    }
    
    if((sum1 + sum2) % 2 == 1) return -1;
    
    while(sum1 != sum2) {
        
        if(result > (size * size))
            return -1;
        
        
        if(sum1 > sum2) {
            long long temp = q1.front();
            q1.pop();
            q2.push(temp);
            sum1 -= temp;
            sum2 += temp;
        }
        
        else {
            long long temp = q2.front();
            q2.pop();
            q1.push(temp);
            sum2 -= temp;
            sum1 += temp;
        }
        
        
        
        
        result++;
    }
    
    
    return result;
}