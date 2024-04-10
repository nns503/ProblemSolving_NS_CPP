#include <bits/stdc++.h>

using namespace std;

int BFS(vector<vector<int>> &adj, int n, int st){
    queue<int> q;
    vector<bool> vis(n+1, false);
    int answer = 0;
    q.push(st); vis[st] = true;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt]) continue;
            answer++;
            vis[nxt] = true;
            q.push(nxt);
        }
    }

    return answer;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    int n, x, a, b;

    while(T--){
        cin >> n >> x;
        vector<vector<int>> adj(n+1);
        for(int i=0; i<x; i++){
            cin >> a >> b;
            adj[a].push_back(b);  
            adj[b].push_back(a);          
        }
        cout << BFS(adj, n, 1) << '\n';
    }

    return 0;
}