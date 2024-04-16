#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> len(n+1);
    for(int i=0; i<edge.size(); i++){
        int x = edge[i][0]; int y = edge[i][1];
        len[x].push_back(y);
        len[y].push_back(x);
    }
    
    queue<int> q;
    vector<int> dist(n+1, -1);
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : len[cur]){
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    
    int mx = *max_element(dist.begin(), dist.end());
    
    for(auto cur : dist){
        if(cur == mx) answer++;
    }
    
    return answer;
}