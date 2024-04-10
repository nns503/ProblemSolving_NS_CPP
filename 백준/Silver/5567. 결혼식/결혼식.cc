#include <bits/stdc++.h>

using namespace std;

int DFS(vector<vector<int>> &adj, int cur, int n){
    int answer = 0;
    stack<int> s; s.push(cur);
    vector<int> dist(n+1, -1);
    dist[cur] = 0;
    while(!s.empty()){
        cur = s.top(); s.pop();
        for(auto nxt : adj[cur]){
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            answer++;
            if(dist[nxt] == 1) s.push(nxt);
        }
    }

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, m, a, b;
    T = 1;
    
    while(T--){
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        vector<int> dist(n+1, -1);
        for(int i=0; i<m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout << DFS(adj, 1, n) << '\n';
    }
    return 0;
}