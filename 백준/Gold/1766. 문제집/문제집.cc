#include <bits/stdc++.h>

using namespace std;

int n, m;
bool chk[32001];
int p[32001];
vector<int> adj[32001];
priority_queue<int, vector<int>, greater<int>> q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        p[v]++;
        adj[u].push_back(v);
    }

    for(int i=1; i<=n; i++){
        if(p[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.top(); q.pop();
        cout << cur << ' ';
        for(int i=0; i<adj[cur].size(); i++){
            int nxt = adj[cur][i];
            p[nxt]--;
            if(p[nxt] == 0){
                q.push(nxt);
            }
        }
    }

    return 0;
}
