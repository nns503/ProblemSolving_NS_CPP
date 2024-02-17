#include <bits/stdc++.h>

using namespace std;


int n, m;
bool vis[2001];
vector<int> adj[2001];
int answer;

void func(int cur, int cnt){
    if(cnt == 4){
        answer = true;
        return ;
    }
    for(int i=0; i<adj[cur].size(); i++){
        int nxt = adj[cur][i];
        if(vis[nxt]) continue;
        vis[nxt] = true;
        func(nxt, cnt+1);
        vis[nxt] = false;
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        vis[i] = true;
        func(i, 0);
        vis[i] = false;
    }

    cout << answer;
    return 0;
}
