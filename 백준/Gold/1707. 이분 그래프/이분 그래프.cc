#include <bits/stdc++.h>

using namespace std;

bool BFS(vector<vector<int>> &adj, int n){
    vector<int> vis(n+1, -1);
    stack<int> s;
    
    for(int i=1; i<=n; i++){
        if(vis[i] != -1) continue;
        s.push(i);
        vis[i] = 0;
        while(!s.empty()){
            auto cur = s.top(); s.pop();
            for(auto nxt : adj[cur]){
                if(vis[nxt] == -1){
                    s.push(nxt);
                    vis[nxt] = (vis[cur]+1) % 2;     
                }
                else{
                    if(vis[cur] == vis[nxt]) return false;
                    continue;
                }
            }
        }
    }
    return true;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n, e, u, v;
    cin >> T;

    while(T--){
        cin >> n >> e;
        vector<vector<int>> adj(n+1);
        for(int i=0; i<e; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << (BFS(adj, n)?"YES":"NO") << '\n';
        
    }
    return 0;
}