#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
/*
    의외로 첫트 클
    너무 코드를 못생기게 짰음
*/

vector<pair<int, int>> adj[2002];
int dis[2003];
vector<int> candidate;
vector<int> result;
int temp_result = 1e9;

void func() {
    // 교차로, 도로, 목적지의 후보 개수
    // 초기화
    for(int i = 0; i <= 2001; i++) {
        adj[i].clear();
        dis[i] = 1e9;
    }
    candidate.clear();
    result.clear();

    int n, m, t;
    std::cin >> n >> m >> t;
    
    int s,g,h;
    // s는 출발한 지점 
    // g - h 는 이미 이동한 간선임
    std::cin >> s >> g >> h;

    // 그래프 만들기
    for(int i = 0; i < m; i++) {
        int fromV, toV, weight;
        std::cin >> fromV >> toV >> weight;
        adj[fromV].push_back({weight, toV});
        adj[toV].push_back({weight, fromV});
    }

    // 목적지 만들기
    for(int i = 0; i < t; i++) {
        int temp;
        cin >> temp;
        candidate.push_back(temp);
    }
    
    // 이미 갔던 간선의 길이를 측정하기
    int already_gone;
    for(auto nxt : adj[g]) {
        if(nxt.second == h) {
            already_gone = nxt.first;
            break;
        }
    }


    // S ~ G or H로 가는 길
    // + G-t or S - H 로 가는 길의 합을 구함
    // 그것으로 최솟값 정하기

    //  J 가 0 일 때 s >>  g >> h >> des  : sTog
    // 1 일 때 s >> h >> g >> des : sToh
    for(int i = 0; i < t; i++) {
        int sTog; // g를 우선으로 갈 떄
        int sToh; // h를 우선으로 갈 때
        int destination = candidate[i];
        int min_dis; // 측저앻
        fill(dis, dis + 2001, 1e9);
        priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>> > pq;  

            
        pq.push({0, s});
        dis[s] = 0;

        while(!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            if(dis[cur.second] < cur.first) continue;
            for(auto nxt : adj[cur.second]) {
                if(dis[nxt.second] <= dis[cur.second] + nxt.first) continue; // nxt 거리가 현재 거리와 간선 합과 작거나 같을 시 할 필요 X 
                dis[nxt.second] = dis[cur.second] + nxt.first;
                pq.push({dis[nxt.second], nxt.second});
            }
        }

        min_dis = dis[destination];
        sTog = dis[g];
        sToh = dis[h];
        sTog += already_gone;
        sToh += already_gone;
        
        // s To g 는 h ~ t 까지 
        for(int j = 0; j < 2; j++) {
            fill(dis, dis + 2001, 1e9);
            priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>> > pq;  
            int st;
            if(j == 0) st = h;
            else st = g;
            
            pq.push({0, st});
            dis[st] = 0;
            while(!pq.empty()) {
                auto cur = pq.top();
                pq.pop();

                if(dis[cur.second] < cur.first) continue;
                for(auto nxt : adj[cur.second]) {
                    if(dis[nxt.second] <= dis[cur.second] + nxt.first) continue; // nxt 거리가 현재 거리와 간선 합과 작거나 같을 시 할 필요 X 
                    dis[nxt.second] = dis[cur.second] + nxt.first;
                    pq.push({dis[nxt.second], nxt.second});
                }   
            }

            if(st == h) sTog += dis[destination];
            else sToh += dis[destination];
        }
        int result_length;
        if(sTog > sToh)
            result_length = sToh;

        else 
            result_length = sTog;

        if(min_dis == result_length) {
            result.push_back(destination);
        }
    }

    sort(result.begin(), result.end());
    for(int nxt : result) {
        std::cout << nxt << " ";
    }
    std::cout << "\n";
}


int main() {
    std::ios::sync_with_stdio(0); // time code
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while(t--) {
        func();
    }

    return 0;

}