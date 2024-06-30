#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    vector<int> adj[n+1];

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> len(n+1, -1);
    queue<int> q;
    q.push(x);
    len[x] = 0;
    vector<int> ans;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            if(len[nxt] != -1) continue;
            len[nxt] = len[cur] + 1;
            if(len[nxt] == k) ans.push_back(nxt);
            else q.push(nxt);
        }
    }

    if(ans.empty()){
        cout << -1;
    }
    else{
        sort(ans.begin(), ans.end());
        for(auto cur : ans) cout << cur << '\n';
    }
    
    
    return 0;
}