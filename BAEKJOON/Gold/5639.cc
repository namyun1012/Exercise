#include <iostream>
#include <deque>
#include <vector>

int tree[10002];
/*
    순회는 재귀로 하자
    푼 방향이 잘못되었었음
    index 를 이용해서 재귀를 진행하는 것을 바로 떠올리기는 어려웠다.
*/
// st == root
void postOrder(int st, int en) {
    if(st > en) return ;

    if(st == en) {
        std::cout << tree[st] << "\n";
        return ;
    }

    // st < en 인 경우임
    int slice;
    for(slice = st; slice <= en; slice++) {
        if(tree[st] < tree[slice]) {
            break;
        }
    }
    
    postOrder(st + 1, slice - 1);
    postOrder(slice, en);
    std::cout << tree[st] << "\n";
    return ;
}




int main() {
    int index = 0;
    int temp;
    while(std::cin >> temp) {
        tree[index] = temp;
        index++;
    }




    postOrder(0, index - 1);
    return 0;
}