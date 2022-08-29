#include <iostream>
#include <queue>

int main() {
    int N;
    std::queue<int> q;
    std::cin >> N;
    
    for(int i = 1; i <= N; i++)
        q.push(i);

    while(q.size() > 1)  {
        q.pop();
        int ele = q.front();
        q.push(ele);
        q.pop();
    }

    std::cout << q.front();
    return 0;
        
}