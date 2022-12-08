#include <iostream>
#include <vector>
#include <algorithm>

int n;

int inOrder[100002];
int postOrder[100002];


/*
    postOrder 는 현재의 index를
    inOrder는 left, right를 가르는데 사용함

    이럴 때 index 를 그냥 재귀돌리면 꼬이기 때문에
    postOrder의 slice ~ en - 1의 index를 하나 씩 땡겨서 index 가 꼬이지 않고 작동할 수 있게 함
    n log n 같은데 되긴 함

    다른 사람들 한 것보니까
    inOrder 와 PostOrder의 index를 각각 받아서 총 index 4개로 씀
    매개 변수 2개
*/






// preOrder 자신 왼쪽 오른쪽
// inOrder에서 왼쪽 자신 오른쪽
// postOrder에서 왼쪽 오른쪽 자신 
// cur = postOreder[en];
// 왼쪽과 오른쪽 순으로 정해야 함 그 기준

void preOrder(int st, int en) {
    if(st > en) return;
    if(st == en) {
        std::cout << postOrder[en] << " ";
        return ;
    }

    // inOrder 기준 가장 왼쪽
    int slice = st;
    int cur = postOrder[en];

    for(slice = st; slice < en; slice++) {
        if(inOrder[slice] == cur) 
            break;
    }

    for(int i = en - 1; i >= slice; i--) {
        postOrder[i+1] = postOrder[i];
    }

    std::cout << cur <<  " ";


    preOrder(st, slice - 1);
    preOrder(slice +1, en);
    
    return ;
}



int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);
    std::cin >> n;

    for(int i = 0; i < n; i++)
        std::cin >> inOrder[i];
    
    for(int i = 0; i < n; i++)
        std::cin >> postOrder[i];

    // 0 ~ n -1 까지의 index 를 진행
    preOrder(0, n-1);


    return 0;

}