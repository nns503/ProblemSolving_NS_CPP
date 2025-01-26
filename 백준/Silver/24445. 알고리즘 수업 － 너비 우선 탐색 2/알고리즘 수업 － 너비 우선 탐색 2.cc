#include <bits/stdc++.h>

using namespace std;

int n, m, r;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    vector<int> dist(n+1, 0);
    vector<int> adj[n+1];

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end(), greater<>());
    }

    queue<int> q;
    q.push(r);
    dist[r] = 1;

    int cnt = 2;    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(dist[nxt] != 0) continue;
            dist[nxt] = cnt++;
            q.push(nxt);
        }
    }

    for(int i=1; i<=n; i++){
        cout << dist[i] << '\n';
    }

}