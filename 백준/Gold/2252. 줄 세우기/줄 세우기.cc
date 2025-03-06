#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> p(n+1, 0);
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        p[a]++;
        adj[b].push_back(a);
    }

    vector<int> answer;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(p[i] == 0){
            answer.push_back(i);
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(auto nxt : adj[x]){
            p[nxt]--;
            if(p[nxt] == 0){
                answer.push_back(nxt);
                q.push(nxt);
            }
        }
    }

    reverse(answer.begin(), answer.end());

    for(auto cur : answer){
        cout << cur << ' ';
    }
}