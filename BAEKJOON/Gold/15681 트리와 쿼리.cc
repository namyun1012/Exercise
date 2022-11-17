#include <iostream>
#include <vector>
#include <queue>
std::vector<int> adj[100002];

//Parent 주소
int parented[100002];

int visited[100002];
std::vector<int> child[100002];
int subtrees[100002];

// 정점의 수, 루트의 번호, 쿼리의 수
int n, r, q;


// 재귀를 이용해서 서브 트리 수 계산
void CountSubTrees(int num) {
    subtrees[num] = 1;
    for(int nxt: child[num]) {

        CountSubTrees(nxt);
        subtrees[num] += subtrees[nxt];
    }
} 

int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    std::cin >> n >> r >> q;
    parented[r] = 0;

    for(int i = 0; i < n - 1; i++) {
        int fromV, toV;
        std::cin >> fromV >> toV;
        adj[fromV].push_back(toV);
        adj[toV].push_back(fromV);
    }
    
    //  BFS로 부모 자식 관계 설정, 트리를 만듬
    // 생각해 보니 별 필요 없는 듯 위에서 visited로 구분하면 그만이긴 했음
    std::queue<int> que;
    que.push(r);
    visited[r] = 1;
    
    
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        
        for(int nxt : adj[cur]) { 
            if(visited[nxt]) continue; 
            
            parented[nxt] = cur;
            child[cur].push_back(nxt);

            visited[nxt] = 1;
            que.push(nxt);    
        }

    }

    CountSubTrees(r);

    // Query 에 대한 대답
    while (q--)
    {
        int query;
        std::cin >> query;
        std::cout << subtrees[query] << "\n";
    }
    

    return 0;
}