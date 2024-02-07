#include <bits/stdc++.h>

using namespace std;

vector<int> u[101];
vector<int> d[101];
int n, m;
bool vis[101];
queue<int> q;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        u[a].push_back(b);
        d[b].push_back(a);
    }
    

    for(int i=1; i<=n; i++){
        fill(vis, vis+101, false);
        vis[i] = true; q.push(i);
        int answer = n-1;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int j=0; j<u[cur].size(); j++){
                int nxt = u[cur][j];
                if(vis[nxt]) continue;
                vis[nxt] = true;
                answer--;
                q.push(nxt);
            }
        }
        q.push(i);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int j=0; j<d[cur].size(); j++){
                int nxt = d[cur][j];
                if(vis[nxt]) continue;
                vis[nxt] = true;
                answer--;
                q.push(nxt);
            }
        }

        cout << answer << '\n';
    }
    return(0);
}